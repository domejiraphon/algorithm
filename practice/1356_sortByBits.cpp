/*
1356. Sort Integers by The Number of 1 Bits
You are given an integer array arr. Sort the integers in the array in ascending order by the number of 1's in their binary representation and in case of two or more integers have the same number of 1's you have to sort them in ascending order.

Return the array after sorting it.
*/
class Solution {
public:
  vector<int> sortByBits(vector<int>& arr) {
    int n=arr.size();
    unordered_map<int, int> num1;
    for (int i=0; i<n; i++)
      compute(arr[i], num1);
    sort(arr.begin(), arr.end(), [&num1](int& a, int& b){
      return (num1[a] == num1[b]) ? a < b : num1[a] < num1[b];
    });
    return arr;
  
  }
private:
  void compute(int num, unordered_map<int, int>& num1){
    if (num1.count(num))
      return;
    int count=0;
    int temp = num;
    while (num > 0){
      count += num % 2;
      num /= 2;
    }
    num1[temp] = count;
  }
};
