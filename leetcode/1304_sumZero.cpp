#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <tuple>

using namespace std;

class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> out (n);
        int low = 0, high(n-1);
        int val = (int) n / 2;
        while (low < high){
            out[low] = - val;
            out[high] = val;
            low++, high--; val--;
        }
        if (n % 2 == 1){out[(int) n /2] = 0;}
        return out;
    }
};

int main()
{ 
  
  Solution* sol;
  vector<int> out = sol -> sumZero(66);
  return 0;
}