void print(vector<int> x){
  for (auto row: x){cout << row <<", ";}
  cout << endl;
}
class Solution {
  int n;
  vector<int> arr;
public:
  int findKthLargest(vector<int>& nums, int k) {
    n = nums.size();
    arr = nums;
    return quickSelect(0, n - 1, n - k);
  }
private:
  int quickSelect(int start, int end, int k){
    if (start == end)
      return arr[start];
    int pivotIdx = rand() % (end - start) + start;

    pivotIdx = partition(start, end, pivotIdx);
    if (k == pivotIdx)
      return arr[k];
    else if (k < pivotIdx)
      return quickSelect(start, pivotIdx - 1, k);
    else 
      return quickSelect(pivotIdx + 1, end, k);

  }
  int partition(int start, int end, int pivotIdx){
    int idx=start;
    int pivot = arr[pivotIdx];
    swap(arr[end], arr[pivot]);
    for (int i=start; i<= end; i++){
      if (arr[i] < pivot)
        swap(arr[i], arr[idx++]);
    }
    swap(arr[idx], arr[end]);
    return idx;
  }
};