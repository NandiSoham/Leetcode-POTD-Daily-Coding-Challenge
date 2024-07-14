// problem Link -> https://leetcode.com/problems/number-of-atoms/description/

class Solution {
public:
    typedef unordered_map<string, int> AtomCountMap;

    string countOfAtoms(string formula) {
        int formulaLength = formula.length();
        
        stack<AtomCountMap> atomStack;
        atomStack.push(AtomCountMap());

        int index = 0;
    
        while (index < formulaLength) {
            if (formula[index] == '(') {
                atomStack.push(AtomCountMap());
                index++;
            } else if (formula[index] == ')') {
                AtomCountMap currentMap = atomStack.top();
                atomStack.pop();
                index++;
                string multiplierStr;
                while (index < formula.length() && isdigit(formula[index])) {
                    multiplierStr += formula[index];
                    index++;
                }
                if (!multiplierStr.empty()) {
                    int multiplier = stoi(multiplierStr);
                    for (auto& [atom, count] : currentMap) {
                        currentMap[atom] = count * multiplier;
                    }
                }

                for (auto& [atom, count] : currentMap) {
                    atomStack.top()[atom] += count;
                }
            } else {
                string currentAtom;
                currentAtom += formula[index];
                index++;
                while (index < formula.length() && islower(formula[index])) {
                    currentAtom += formula[index];
                    index++;
                }

                string countStr;
                while (index < formula.length() && isdigit(formula[index])) {
                    countStr += formula[index];
                    index++;
                }

                int count = countStr.empty() ? 1 : stoi(countStr);
                atomStack.top()[currentAtom] += count;
            }
        }
        
        map<string, int> sortedAtomCountMap(begin(atomStack.top()), end(atomStack.top()));

        string result;
        for (auto& [atom, count] : sortedAtomCountMap) {
            result += atom;
            if (count > 1) {
                result += to_string(count);
            }
        }

        return result;
    }
};



// Time Complexity -> O(n^2)
// Space Compelxity -> O(n)
