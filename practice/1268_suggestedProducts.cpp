#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
      sort(products.begin(), products.end());
      int start(0), n(products.size()), end(n);
      string cur;
      vector<vector<string>> res;
      for (auto c: searchWord){
        cur += c;
        start = lower_bound(products.begin() + start, products.end(), cur) - products.begin();
        res.push_back({});
        for (int i=start; i<min(start +3, end) && products[i].substr(0, cur.size()) == cur; i++){
          res.back().push_back(products[i]);
        }
       
      }
      return res;
    }

};

int main()
{ 
  for (int i=0; i< 10 && i % 2 == 0; i++){
    cout << i << endl;
  }
  return 0;
}