#include <iostream>
#include <iterator>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void print(unordered_set<int> x){
  for (auto it: x){
    cout << it << ", ";
  }
  cout << endl;
}
void print(unordered_map<char, unordered_set<int>> x){
  for (auto it=x.begin(); it != x.end(); it++){
    cout << it -> first << ": ";
    for (auto m:it-> second){
      cout << m <<", ";
    }
    cout << endl;
  }
  cout << endl;
}

class Solution {
public:
  string getHint(string secret, string guess) {
    unordered_map<char, int> map;
    int n = secret.size();
    int m = guess.size();
    for (int i=0; i < n; i++){
      map[secret[i]]++;
    }
   
    int cow(0), bull(0);
    for (int i=0; i < m; i++){
      if (i < n && secret[i] == guess[i]){
        bull++;
        if (map[guess[i]] > 0){
          map[guess[i]]--;
         
        }
        }
      else if (map.find(guess[i]) != map.end()){
        if (map[guess[i]] > 0){
          cow++;
          map[guess[i]]--;
        }
        
      }
    }
    return to_string(bull) +"A"+to_string(cow) +"B";
  }
};

int main()
{ 
  
  Solution* sol;
  cout << sol -> getHint("1807", "7810")<< endl;
  cout << sol -> getHint("1123", "0111")<< endl;
  cout << sol -> getHint("1122", "1222")<< endl;
  cout << sol -> getHint("1133", "1233")<< endl;
  return 0;
}