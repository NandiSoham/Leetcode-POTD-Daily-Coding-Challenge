// Problem Link -> https://leetcode.com/problems/find-the-closest-palindrome/description/

class Solution {
public:
    long mirrorLeftHalfToPalindrome(long leftHalf, bool isEvenLength) {
        long palindrome = leftHalf;
        if (!isEvenLength) {
            leftHalf /= 10;
        }

        while (leftHalf > 0) {
            int digit = leftHalf % 10;
            palindrome = (palindrome * 10) + digit;
            leftHalf /= 10;
        }
        return palindrome;
    }

    string nearestPalindromic(string number) {
        int length = number.size();
        int middle = length / 2;
        long firstHalf = stol(number.substr(0, length % 2 == 0 ? middle : middle + 1));

        vector<long> candidates;
        candidates.push_back(mirrorLeftHalfToPalindrome(firstHalf, length % 2 == 0));
        candidates.push_back(mirrorLeftHalfToPalindrome(firstHalf + 1, length % 2 == 0));
        candidates.push_back(mirrorLeftHalfToPalindrome(firstHalf - 1, length % 2 == 0));
        candidates.push_back((long)pow(10, length - 1) - 1);
        candidates.push_back((long)pow(10, length) + 1);

        long closestDifference = LONG_MAX;
        long closestPalindrome = 0;
        long originalNumber = stol(number);

        for (long &candidate : candidates) {
            if (candidate == originalNumber) continue;
            long currentDifference = abs(candidate - originalNumber);
            if (currentDifference < closestDifference) {
                closestDifference = currentDifference;
                closestPalindrome = candidate;
            } else if (currentDifference == closestDifference) {
                closestPalindrome = min(closestPalindrome, candidate);
            }
        }

        return to_string(closestPalindrome);
    }
};



// Time Complexity -> O(n)
// Space Complexity -> O(1)
