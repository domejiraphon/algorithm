#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <queue>
#include <cmath>
#include <set>
#include <algorithm>

using namespace std;

void print(vector<int> x){
  
    for (auto elem: x){
      cout << elem <<", ";}
  cout << endl;
  
}

int getDigit(int n, int idx=0)
{
  int digits = (int)log10(n);
  n = (int)(n / pow(10, digits -idx));
  if (idx !=0){
    return n% 10;
  }
  return n;
}

bool sortby(const int &a,
              const int &b){
  int digitA = getDigit(a);
  int digitB = getDigit(b);
  if (digitA > digitB){
    return true;
  }
  else if (digitA < digitB){
    return false;
  }
  else {
    int idxA = 1;
    int idxB = 1;
    while (digitA ==  digitB &&
          idxA <= (int)log10(a) &&
          idxB <= (int)log10(b)){
      digitA = getDigit(a, idxA);
      digitB = getDigit(b, idxB);
      idxA++; idxB++;
      cout << digitA <<", " << digitB<<endl;
      if (digitA != digitB){
        return (digitA > digitB);
      }
    }
    
    if (a < b){
      int lastDigit = b % 10;
      int firstDigit = getDigit(a);
      if (lastDigit != firstDigit){return lastDigit > firstDigit;}
      else {return a < b;}
      
    }
    else {
      int lastDigit = a % 10;
      int firstDigit = getDigit(b);
      if (lastDigit != firstDigit){return lastDigit > firstDigit;}
      else {return a < b;}
    }
    
  }
}


class Solution {
public:
  string largestNumber(vector<int>& nums) {
    sort(nums.begin(), nums.end(), sortby);
    print(nums);
    string out;
    for (auto i: nums){
      out += to_string(i);
    }
    return out;
  }
};

int main()
{ 
  
  Solution* sol;

  vector<int> nums = {10, 2};
  cout << sol ->largestNumber(nums)<<endl;

  nums = vector<int> {3, 30, 34, 5, 9};
  cout << sol ->largestNumber(nums)<<endl;

  nums = vector<int> {111311, 1113};
  cout << sol ->largestNumber(nums)<<endl;
  return 0;
}