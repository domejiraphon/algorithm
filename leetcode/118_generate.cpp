#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <tuple>

using namespace std;
template <typename T>
void print_vector(const std::vector<T> & vec, std::string sep=", ")
{
    for(auto elem : vec)
    { 
      cout << "{";
      for(auto in_elem : elem) {
        cout<<in_elem<< sep;
      }
      cout << "}, ";
    }
    cout<<endl;
}

class Solution {
public:
  vector<vector<int>> generate(int numRows) {
    if (numRows == 1) {
      vector<vector<int>> out {{1}};
      return out;
    }
    else if (numRows == 2) {
      vector<vector<int>> out {{1}, {1, 1}};
      return out;
    }
    vector<vector<int>> out {{1}, {1, 1}};
    vector<int> cur {};
    for (int i=3; i != numRows+1; i++){
      cur.push_back(1);
      for (int j=0; j != out[out.size() - 1].size()-1; j++){
        cur.push_back(out[out.size() - 1][j] + out[out.size() - 1][j+1]);
      }
      cur.push_back(1);
      out.push_back(cur);
      cur.clear();
    }
    return out;
  }
};

int main()
{ 
  Solution sol;
  vector<vector<int>> out = sol.generate(5);
  print_vector(out);
  return 0;
}