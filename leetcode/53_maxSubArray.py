import os, sys
from loguru import logger  
import numpy as np
from typing import List


class Solution:
  def maxSubArray(self, nums: List[int]) -> int:
    out = np.zeros((len(nums), len(nums)))
    out[0][0] = nums[0]
    maxi = nums[0]
    for i in range(len(nums)):
      for j in range(1, len(nums)):
        out[i][j] = max(nums[j], out[i][j-1]+nums[j])
        if maxi < out[i][j]:
          maxi = out[i][j]
    return int(maxi)

@logger.catch
def main():
  nums = [-2,1,-3,4,-1,2,1,-5,4]
  sol = Solution()
  nums = [5,4,-1,7,8]
  nums=[1]
  print(sol.maxSubArray(nums))

if __name__ == "__main__":
  main()
        