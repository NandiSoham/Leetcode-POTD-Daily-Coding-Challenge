// Problem Link -> https://leetcode.com/problems/delete-duplicate-folders-in-system/description/

class Solution {
public:
    struct FolderNode {
        string name;
        string subStructure;
        unordered_map<string, FolderNode*> children;
    };

    FolderNode* createNode(string name) {
        FolderNode* newNode = new FolderNode();
        newNode->name = name;
        newNode->subStructure = "";
        return newNode;
    }

    void addPath(FolderNode* root, vector<string>& path) {
        for (auto& dir : path) {
            if (!root->children.count(dir)) {
                root->children[dir] = createNode(dir);
            }
            root = root->children[dir];
        }
    }

    string serializeStructure(FolderNode* node,
                              unordered_map<string, int>& seenStructures) {
        vector<pair<string, string>> serializedChildren;

        for (auto& [childName, childNode] : node->children) {
            string childStructure =
                serializeStructure(childNode, seenStructures);
            serializedChildren.push_back({childName, childStructure});
        }

        sort(serializedChildren.begin(), serializedChildren.end());

        string serialized = "";
        for (auto& [childName, structure] : serializedChildren) {
            serialized += "(" + childName + structure + ")";
        }

        node->subStructure = serialized;

        if (!serialized.empty()) {
            seenStructures[serialized]++;
        }

        return serialized;
    }

    void eliminateDuplicates(FolderNode* node,
                             unordered_map<string, int>& seenStructures) {
        for (auto it = node->children.begin(); it != node->children.end();) {
            FolderNode* childNode = it->second;
            if (!childNode->subStructure.empty() &&
                seenStructures[childNode->subStructure] > 1) {
                it = node->children.erase(it);
            } else {
                eliminateDuplicates(childNode, seenStructures);
                ++it;
            }
        }
    }

    void buildFinalPaths(FolderNode* node, vector<string>& currentPath,
                         vector<vector<string>>& output) {
        for (auto& [dir, child] : node->children) {
            currentPath.push_back(dir);
            output.push_back(currentPath);
            buildFinalPaths(child, currentPath, output);
            currentPath.pop_back();
        }
    }

    vector<vector<string>>
    deleteDuplicateFolder(vector<vector<string>>& paths) {
        FolderNode* root = createNode("/");

        for (auto& path : paths) {
            addPath(root, path);
        }

        unordered_map<string, int> seenStructures;
        serializeStructure(root, seenStructures);

        eliminateDuplicates(root, seenStructures);

        vector<vector<string>> finalPaths;
        vector<string> tempPath;
        buildFinalPaths(root, tempPath, finalPaths);

        return finalPaths;
    }
};


