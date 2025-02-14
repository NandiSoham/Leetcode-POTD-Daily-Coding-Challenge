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


// ======================================= Approach - 2 ====================================

class ProductOfNumbers {
public:
    vector<int> cumulativeProduct;
    int n;

    ProductOfNumbers() {
        cumulativeProduct.clear();
        n = 0;
    }
    
    void add(int num) {
        if (num == 0) {
            cumulativeProduct.clear();
            n = 0;
        } else {
            if (cumulativeProduct.empty()) {
                cumulativeProduct.push_back(num);
            } else {
                cumulativeProduct.push_back(cumulativeProduct[n - 1] * num);
            }
            n++;
        }
    }
    
    int getProduct(int k) {
        if (k > n) {
            return 0;
        }
        if (k == n) {
            return cumulativeProduct[n - 1];
        }
        return cumulativeProduct[n - 1] / cumulativeProduct[n - k - 1];
    }
};



// Time Complexity -> O(1)
// Space Complexity -> O(n)

// =========================================================================================
