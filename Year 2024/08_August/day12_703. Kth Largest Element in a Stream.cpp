// Problem Link -> https://leetcode.com/problems/kth-largest-element-in-a-stream/description/

class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int kthLargestValue;
    
    KthLargest(int k, vector<int>& nums) {
        kthLargestValue = k;
        for(int &num : nums) {
            minHeap.push(num);
            
            if(minHeap.size() > k)
                minHeap.pop();
        }
    }
    
    int add(int value) {
        minHeap.push(value);
        
        if(minHeap.size() > kthLargestValue)
            minHeap.pop();
        
        return minHeap.top();
    }
};



// Time Complexity -> O(n*logK)
// Space Complexity -> O(K)
