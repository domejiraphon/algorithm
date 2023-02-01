#include <iostream>
#include <iterator>
#include <map>
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
  int lastRemaining(int n) {
    vector<int> order(n);
    for (int i=0; i < n; i++){order[i] = i +1;}
    while (order.size() > 1){
      removeLeft(order);
      removeRight(order);
    }
    return order[0];
  }
private:
  void removeLeft(vector<int>& arr){
    if (arr.size() == 1){return;}
    for (int i=0; i < arr.size(); i++){
      arr.erase(arr.begin() + i);
    }
  }
  void removeRight(vector<int>& arr){
    if (arr.size() == 1){return;}
    for (int i=arr.size() - 1; i >= 0; i-=2){
      arr.erase(arr.begin() + i);
    }
  }
};

int main()
{ 
  Solution* sol;
  cout << sol -> lastRemaining(9)<< endl;
  cout << sol -> lastRemaining(6)<< endl;
  cout << sol -> lastRemaining(1)<< endl;
  return 0;
}