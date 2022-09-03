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
  vector<int> plusOne(vector<int>& digits) {
    int size=digits.size();
    int carry(0);
    int sum(0);
    for (int i=size-1; i!=-1; i--){
      sum = carry + digits[i];
      if (i == size -1) sum++;
      digits[i] = sum % 10;
      carry = (int) sum /10;
      if (carry==0)
        break;
    }
    if (carry ==1){
      vector<int> out{1};
      out.insert(out.end(), digits.begin(), digits.end());
      return out;
    }
    else
      return digits;
  }
};

int main()
{
  vector<int> digits1{1, 2, 3};
  vector<int> digits2{4, 3, 2, 1};
  vector<int> digits3{9};
  vector<int> out1, out2, out3;

  Solution sol;
  out1 = sol.plusOne(digits1);
  out2 = sol.plusOne(digits2);
  out3 = sol.plusOne(digits3);
  print_vector(out1);
  print_vector(out2);
  print_vector(out3);
  return 0;
}