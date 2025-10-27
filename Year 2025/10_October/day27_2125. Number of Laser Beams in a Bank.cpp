// Problem Link -> https://leetcode.com/problems/number-of-laser-beams-in-a-bank/description/

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n = bank.size();
        int prevRowDevice = 0;  
        int ans = 0;

        for(int i = 0; i < n; i++){
            int currRowDevice = 0;

            for(char &ch : bank[i]){
                if(ch == '1') currRowDevice++;
            }

            ans += (currRowDevice * prevRowDevice);

            if(currRowDevice != 0){
                prevRowDevice = currRowDevice;
            }
        }

        return ans;
    }
};



// Time Complexity -> O(R * C)
// Space com[plexity - O(1)
