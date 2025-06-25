// Problem link -> https://leetcode.com/problems/kth-smallest-product-of-two-sorted-arrays/description/

class Solution {
public:
    long long countProductsLessThanOrEqual(vector<int>& arr1, vector<int>& arr2,
                                           long long targetProduct) {
        long long totalCount = 0;
        int size2 = arr2.size();

        for (int i = 0; i < arr1.size(); i++) {

            if (arr1[i] >= 0) {
                int left = 0, right = size2 - 1, maxIndex = -1;

                while (left <= right) {
                    int mid = left + (right - left) / 2;
                    long long product = 1LL * arr1[i] * arr2[mid];

                    if (product <= targetProduct) {
                        maxIndex = mid;
                        left = mid + 1;
                    } else {
                        right = mid - 1;
                    }
                }

                totalCount += (maxIndex + 1);
            } else {
                int left = 0, right = size2 - 1, minIndex = size2;

                while (left <= right) {
                    int mid = left + (right - left) / 2;
                    long long product = 1LL * arr1[i] * arr2[mid];

                    if (product <= targetProduct) {
                        minIndex = mid;
                        right = mid - 1;
                    } else {
                        left = mid + 1;
                    }
                }

                totalCount += (size2 - minIndex);
            }
        }
        return totalCount;
    }

    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2,
                                 long long k) {
        long long ans = 0;
        long long low = -1e10, high = 1e10;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            long long productCount =
                countProductsLessThanOrEqual(nums1, nums2, mid);

            if (productCount >= k) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
