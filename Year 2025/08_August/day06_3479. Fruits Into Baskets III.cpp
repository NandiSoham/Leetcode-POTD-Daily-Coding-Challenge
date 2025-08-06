// Problem link -> https://leetcode.com/problems/fruits-into-baskets-iii/description/

class Solution {
public:
    void build(int i, int l, int r, vector<int>& baskets, vector<int>& segmentTree) {
        if (l == r) {
            segmentTree[i] = baskets[l];
            return;
        }
        int mid = (l + r) / 2;
        int leftChild = 2 * i + 1;
        int rightChild = 2 * i + 2;

        build(leftChild, l, mid, baskets, segmentTree);
        build(rightChild, mid + 1, r, baskets, segmentTree);

        segmentTree[i] = max(segmentTree[leftChild], segmentTree[rightChild]);
    }

    bool querySegmentTree(int i, int l, int r, vector<int>& segmentTree, int val) {
        if (segmentTree[i] < val)
            return false;

        if (l == r) {
            segmentTree[i] = -1;
            return true;
        }

        int mid = (l + r) / 2;
        int leftChild = 2 * i + 1;
        int rightChild = 2 * i + 2;
        bool placed;

        if (segmentTree[leftChild] >= val) {
            placed = querySegmentTree(leftChild, l, mid, segmentTree, val);
        } else {
            placed = querySegmentTree(rightChild, mid + 1, r, segmentTree, val);
        }

        segmentTree[i] = max(segmentTree[leftChild], segmentTree[rightChild]);
        return placed;
    }

    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        vector<int> segTree(4 * n, -1);

        build(0, 0, n - 1, baskets, segTree);

        int unplacedCount = 0;
        for (int &fruit : fruits) {
            if (!querySegmentTree(0, 0, n - 1, segTree, fruit)) {
                unplacedCount++;
            }
        }

        return unplacedCount;
    }
};



// Time Complexity -> O(n logn)
// SPace complexity -> O(n)
