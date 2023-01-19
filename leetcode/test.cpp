#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <tuple>

using namespace std;

int main ()
{
  map<int,int> mymap;
  
  mymap[10]=20;
  mymap[100]=100;


  auto itlow=mymap.upper_bound(102);  // itlow points to b
  if (itlow == mymap.begin())
    cout << "D";
  if (itlow == mymap.end())
    cout << "Dsdf";
  

  return 0;
}
