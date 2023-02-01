class Solution {
public:
  vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
    vector<int> res = merge(arr1, arr2);
    res = merge(res, arr3);
    return res;
  }
private:
  vector<int> merge(vector<int>& arr1, vector<int>& arr2){
    int left = 0, n=arr1.size();
    int right = 0, m = arr2.size();
    vector<int> res;
    while (left < n && right < m){
      if (arr1[left] < arr2[right])
        left++;
      else if (arr1[left] > arr2[right])
        right++;
      else {
        //cout << arr1[left]<<", ";
        res.push_back(arr1[left++]);
        right++;
      }
    }
    
    return res;
  }
};
