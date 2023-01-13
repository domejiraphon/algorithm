class Solution {
public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int n=nums1.size();
    int m=nums2.size();
    int i=0, j=0;
    vector<int> merge;
    while(i<n && j<m){
      if (nums1[i] < nums2[j])
        merge.push_back(nums1[i++]);
      else
        merge.push_back(nums2[j++]);
    }
    while (i<n)
      merge.push_back(nums1[i++]);
    while(j<m)
      merge.push_back(nums2[j++]);
    
    int size = n+m;
    return (size % 2 == 1) ? merge[size/2] : (double)(merge[size/2] + merge[(size/2)-1])/2;
  }
};

class Solution {
public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int n1=nums1.size();
    int n2=nums2.size();
    int n=n1+n2;
    if (n1 > n2)
      return findMedianSortedArrays(nums2, nums1);
    int partition = (n + 1)/2;

    if (n1 == 0)
      return (n2 % 2) ? nums2[n2/2] : (double) (nums2[n2/2] + nums2[n2/2-1])/2;
    if (n2 == 0)
      return (n1 % 2) ? nums1[n1/2] : (double) (nums1[n1/2] + nums1[n1/2-1])/2;

    int left1=0;
    int right1=n1;
    int mid1, mid2;
    int l1,r1,l2,r2;
    do {
      
      mid1 = (left1 + right1) / 2;
      mid2 = (partition - mid1);
      l1 = mid1 == 0 ? INT_MIN : nums1[mid1 - 1];
      l2 = mid2 == 0 ? INT_MIN : nums2[mid2 - 1];

      r1 = mid1 >= n1 ? INT_MAX : nums1[mid1];
      r2 = mid2 >= n2 ? INT_MAX : nums2[mid2];
      if (l1 <= r2 && l2 <= r1){
        return n %2 ? max(l1, l2) : (double) (max(l1, l2) + min(r1, r2)) /2;
      }
      
      if(l1>r2)
        right1=mid1-1;
      else
        left1=mid1+1;
      
            
        
      
    }while (left1 <= right1);

    return 0.0;

  }
};