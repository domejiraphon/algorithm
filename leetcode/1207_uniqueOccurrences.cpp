#include <iostream>
#include <iterator>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <vector>
#include <tuple>

using namespace std;
void print(vector<int> vec){
  for (auto ele: vec){
    cout << ele << ", ";
  }
  cout << endl;
}
class Solution {
public:
  bool uniqueOccurrences(vector<int>& arr) {
    unordered_map<int, int> hash;
    for (auto ele: arr){
      hash[ele]++;
    }
    unordered_set<int> Set;
    for (auto it=hash.begin(); it != hash.end(); it++){
      if (Set.find(it -> second) == Set.end()){
        Set.insert(it -> second);
      }
      else {return false;}
    }
    return true;
  }
};
int main()
{ 
  Solution* sol;
  vector<int> nums = {1,2,2,1,1,3};
  cout << sol -> uniqueOccurrences(nums)<< endl;

  nums = {1,2};
  cout << sol -> uniqueOccurrences(nums)<< endl;

  nums = {-3,0,1,-3,1,1,1,-3,10,0};
  cout << sol -> uniqueOccurrences(nums)<< endl;
  
  return 0;
}