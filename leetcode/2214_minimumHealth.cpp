#include <iostream>
#include <iterator>
#include <map>
#include <unordered_map>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>

using namespace std;
void print(vector<int> x){
  for (auto row: x){
    cout << row <<", ";
  }
  cout << endl;
}
class Solution {
public:
  long long minimumHealth(vector<int>& damage, int armor) {
    sort(damage.begin(), damage.end());
    int n = damage.size();
    long long out = 0;
    for (int i=0; i < n; i++){
      if (damage[i] >= armor){
        out += damage[i] - armor;
        armor = INT_MAX;
      }
      else {
        if (i == n - 1 && armor != INT_MAX){
          continue;
        }
        out += damage[i];
      }
    }
    return out + 1;
  }
};
int main()
{ 
  
  Solution* sol = new Solution();
  vector<int> damage = {2,7,4,3};
  cout << sol -> minimumHealth(damage, 4)<< endl;

  damage = {2,5,3,4};
  cout << sol -> minimumHealth(damage, 7)<< endl;

  damage = {3,3,3};
  cout << sol -> minimumHealth(damage, 0)<< endl;
  return 0;
}