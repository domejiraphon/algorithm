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
        std::cout<<elem<< sep;
    }
    std::cout<<std::endl;
}

class Solution {
public:
  int climbStairs(int n) {
    if (n == 0)
      return 0;
    else if (n==1)
      return 1;
    else if (n==2)
      return 2;
    
    vector<int> out {0, 1, 2};
    for (int i=3; i != n+1; i++){
      int cur = out[out.size()-1] + out[out.size()-2];
      out.push_back(cur);
    }
    print_vector(out);
    return out[out.size()-1];
  }
};

int main()
{
  Solution sol;
  //cout << sol.climbStairs(2) << endl;
  //cout << sol.climbStairs(3) << endl;
  cout << sol.climbStairs(4) << endl;
  return 0;
}