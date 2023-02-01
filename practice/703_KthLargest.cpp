/*
703. Kth Largest Element in a Stream
Design a class to find the kth largest element in a stream. Note that it is the kth largest element in the sorted order, not the kth distinct element.

Implement KthLargest class:

KthLargest(int k, int[] nums) Initializes the object with the integer k and the stream of integers nums.
int add(int val) Appends the integer val to the stream and returns the element representing the kth largest element in the stream.

*/
class KthLargest {
  priority_queue<int, vector<int>, greater<int>> minHeap;
  int K;
public:
  KthLargest(int k, vector<int>& nums) {
    int n=nums.size();
    for (int i=0; i<n; i++){
      minHeap.push(nums[i]);
      if (minHeap.size() > k)
        minHeap.pop();
    }
    K = k;
  }

  int add(int val) {
    minHeap.push(val);
    if (minHeap.size() > K)
      minHeap.pop();
    return minHeap.top();
  }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
