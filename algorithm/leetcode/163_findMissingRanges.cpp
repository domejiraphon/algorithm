#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <tuple>

using namespace std;
void print(const std::vector<string> & vec, std::string sep=", ")
{
    for(auto elem : vec)
    {
        std::cout<<elem<< sep;
    }
    std::cout<<std::endl;
}

class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> result;
        int prev = lower - 1;
        for (size_t i = 0; i <= nums.size(); i++) {
            int curr = (i < nums.size()) ? nums[i] : upper + 1;
            if (prev + 1 <= curr - 1) {
                result.push_back(formatRange(prev + 1, curr - 1));
            }
            prev = curr;
        }
        return result;
    }

    // formats range in the requested format
    string formatRange(int lower, int upper) {
        if (lower == upper) {
            return to_string(lower);
        }
        return to_string(lower) + "->" + to_string(upper);
    }
};

int main()
{ 
  
  Solution* sol;
  vector<int> nums = {0,1,3,50,75};
  vector<string> out;
  out = sol -> findMissingRanges(nums, -3, 99);
  print(out);

  nums = {-1};
  out = sol -> findMissingRanges(nums, -1, -1);
  print(out);
  return 0;
}