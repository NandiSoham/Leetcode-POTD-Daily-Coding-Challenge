// Problem Link -> https://leetcode.com/problems/count-good-triplets-in-an-array/description/

class Solution {
public:
    void markIndexVisited(int nodeIndex, int left, int right,
                           int updatePosition, vector<long long>& segmentTree) {
        if (left == right) {
            segmentTree[nodeIndex] = 1;
            return;
        }

        int mid = left + (right - left) / 2;
        if (updatePosition <= mid) {
            markIndexVisited(2 * nodeIndex + 1, left, mid, updatePosition,
                              segmentTree);
        } else {
            markIndexVisited(2 * nodeIndex + 2, mid + 1, right, updatePosition,
                              segmentTree);
        }

        segmentTree[nodeIndex] =
            segmentTree[2 * nodeIndex + 1] + segmentTree[2 * nodeIndex + 2];
    }

    long long computeSegmentSum(int queryLeft, int queryRight, int nodeIndex,
                               int left, int right,
                               vector<long long>& segmentTree) {
        if (right < queryLeft || left > queryRight) {
            return 0;
        }

        if (left >= queryLeft && right <= queryRight) {
            return segmentTree[nodeIndex];
        }

        int mid = left + (right - left) / 2;
        long long leftSum = computeSegmentSum(
            queryLeft, queryRight, 2 * nodeIndex + 1, left, mid, segmentTree);
        long long rightSum =
            computeSegmentSum(queryLeft, queryRight, 2 * nodeIndex + 2, mid + 1,
                             right, segmentTree);
        return leftSum + rightSum;
    }

    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        unordered_map<int, int> valToIdx;
        for (int i = 0; i < n; i++) {
            valToIdx[nums2[i]] = i;
        }

        vector<long long> segmentTree(4 * n);
        long long tripletCount = 0;

        markIndexVisited(0, 0, n - 1, valToIdx[nums1[0]],
                          segmentTree);

        for (int i = 1; i < n; i++) {
            int currIdx = valToIdx[nums1[i]];
            long long commonLeftCount =
                computeSegmentSum(0, currIdx, 0, 0, n - 1, segmentTree);
            long long uncommonLeftCount = i - commonLeftCount;
            long long remainingRightCount = (n - 1) - currIdx;
            long long commonRightCount =
                remainingRightCount - uncommonLeftCount;
            tripletCount += commonLeftCount * commonRightCount;

            markIndexVisited(0, 0, n - 1, currIdx, segmentTree);
        }

        return tripletCount;
    }
};


// Time complexity -> O(n logn)
// Space Complexity -> O(n)
