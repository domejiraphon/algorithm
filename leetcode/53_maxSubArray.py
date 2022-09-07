import os, sys
from loguru import logger  
import numpy as np
from typing import List
import math 

class Solution:
  """
  def maxSubArray(self, nums: List[int]) -> int:
    out = - math.inf
    for i in range(len(nums)):
      current = 0
      for j in range(i, len(nums)):
        current += nums[j]
        out = max(out, current)
    return int(out)
  """
  def maxSubArray(self, nums: List[int]) -> int:
    out = - math.inf
    current = 0
    for i in range(len(nums)):
      current += nums[i]
      out = max(out, current)
      if current < 0:
        current = 0
      

    return int(out)


@logger.catch
def main():
  nums = [-2,1,-3,4,-1,2,1,-5,4]
  sol = Solution()
  #nums = [5,4,-1,7,8]
  #nums=[-2, 1]
  print(sol.maxSubArray(nums))

if __name__ == "__main__":
  main()
        