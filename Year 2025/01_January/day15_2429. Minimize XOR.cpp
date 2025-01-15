// Problem Link -> https://leetcode.com/problems/minimize-xor/description/

// ======================================= Approach - 1 ====================================

class Solution {
public:
    bool isBitSet(int &number, int position) {
        return number & (1 << position);
    }

    bool enableBit(int &number, int position) {
        return number |= (1 << position);
    }

    bool disableBit(int &number, int position) {
        return number &= ~(1 << position);
    }

    int minimizeXor(int number1, int number2) {
        int result = number1;
        int targetSetBits = __builtin_popcount(number2);
        int currentSetBits = __builtin_popcount(result);
        int bitPosition = 0;
        
        if (currentSetBits < targetSetBits) {
            while (currentSetBits < targetSetBits) {
                if (!isBitSet(result, bitPosition)) {
                    enableBit(result, bitPosition);
                    currentSetBits++;
                }
                bitPosition++;
            }
        } else if (currentSetBits > targetSetBits) {
            while (currentSetBits > targetSetBits) {
                if (isBitSet(result, bitPosition)) {
                    disableBit(result, bitPosition);
                    currentSetBits--;
                }
                bitPosition++;
            }
        }

        return result;
    }
};



// Time Complexity -> O(log(n))
// Space Complexity -> O(1)

// =========================================================================================


// ======================================= Approach - 2 ====================================

class Solution {
public:
    bool isBitSet(int &number, int position) {
        return number & (1 << position);
    }

    bool enableBit(int &number, int position) {
        return number |= (1 << position);
    }

    bool disableBit(int &number, int position) {
        return number &= ~(1 << position);
    }

    bool isBitUnset(int number, int position) {
        return (number & (1 << position)) == 0;
    }

    int minimizeXor(int number1, int number2) {
        int result = 0;

        int targetSetBits = __builtin_popcount(number2);

        for (int position = 31; position >= 0 && targetSetBits > 0; position--) {
            if (isBitSet(number1, position)) {
                enableBit(result, position);
                targetSetBits--;
            }
        }

        for (int position = 0; position < 32 && targetSetBits > 0; position++) {
            if (isBitUnset(number1, position)) {
                enableBit(result, position);
                targetSetBits--;
            }
        }

        return result;
    }
};



// Time Complexity -> O(log(n))
// Space Complexity -> O(1)

// =========================================================================================
