// Problem Link -> https://leetcode.com/problems/lexicographically-minimum-string-after-removing-stars/description/

class Solution {
public:
    typedef pair<char, int> charIdxPair;

    struct comparator {
        bool operator()(charIdxPair &a, charIdxPair &b){
            if(a.first == b.first) {
                return a.second < b.second;
            }
            return a.first > b.first;
        }
    };

    string clearStars(string s) {
        int n = s.length();

        priority_queue<charIdxPair, vector<charIdxPair>, comparator> minHeap;

        for(int i = 0; i < n; i++) {
            if(s[i] != '*') {
                minHeap.push({s[i], i});
            } else {
                int removeIdx = minHeap.top().second;
                minHeap.pop();
                s[removeIdx] = '*';
            }
        }

        string ansStr = "";
        for(int i = 0; i < n; i++) {
            if(s[i] != '*') {
                ansStr.push_back(s[i]);
            }
        }

        return ansStr;
    }
};



// Time Complexity -> O(nlogn)
// Space Complexity -> O(n)
