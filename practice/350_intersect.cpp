class Solution {
public:
  vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    int left=0, right =0;
    int n=nums1.size(), m = nums2.size();
    vector<int> res;
    while (left < n && right < m){
      if (nums1[left] < nums2[right])
        left++;
      else if (nums1[left] > nums2[right])
        right++;
      else {
        res.push_back(nums1[left++]);
        right++;
      }
    }
    return res;
  }
};
