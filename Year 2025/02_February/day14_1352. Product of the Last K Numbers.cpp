// Problem Link -> https://leetcode.com/problems/product-of-the-last-k-numbers/

// ======================================= Approach - 1 ====================================

class ProductOfNumbers {
public:
    vector<int> numbers;
    int size;
    
    ProductOfNumbers() {
        numbers.clear();
        size = 0;
    }
    
    void add(int number) {
        numbers.push_back(number);
    }
    
    int getProduct(int k) {
        int product = 1;
        int totalNumbers = numbers.size();
        
        for (int i = totalNumbers - k; i < totalNumbers; i++) {
            product *= numbers[i];
        }

        return product;
    }
};



// Time Complexity -> O(k)
// Space Complexity -> O(n)

// =========================================================================================
