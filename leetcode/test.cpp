// CPP program to illustrate
// std :: lower_bound
#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

  
bool compare( pair<int, string> const& t1, pair<int, string> const& t2 )
  {
      return t1.first < t2.first;
  }

 
bool compare2( int const& t1, int const& t2 )
  {
      return t1 > t2;
  }

int main()
{
	vector<pair<int, string>> res;
  res.push_back({1, "ads"});
  res.push_back({2, "dfs"});
  res.push_back({3, "dfs"});
  res.push_back({9, "dfs"});
  res.push_back({23, "dfsfs"});
  //lower_bound(res.begin(), res.end(), 10, Compare()) ;
  int idx = lower_bound(res.begin(), res.end(), 10, compare) - res.begin();
  cout << idx << endl;
  vector<int> d = {1,35,67,90,234};
  int idx = lower_bound(d.begin(), d.end(), 3, compare2) -d.begin();
  cout << idx << endl;
	return 0;
}

