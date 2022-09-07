import os, sys
from loguru import logger  
import numpy as np
from typing import List

class Solution:
  def minimumTotal(self, triangle: List[List[int]]) -> int:
    min_layer = [triangle[0][0]]
    idx = 0
    for i in range(1, len(triangle)):
      left = min_layer[i-1] + triangle[i][idx]
      right = min_layer[i-1] + triangle[i][idx+1]
      if left < right:
        min_layer.append(left)
      else:
        min_layer.append(right)
        idx += 1
    print(min_layer)
    return min_layer[-1]

@logger.catch
def main():
  triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
  triangle = [[-1],[2,3],[1,-1,-3]]
  sol = Solution()
 
  print(sol.minimumTotal(triangle))

if __name__ == "__main__":
  main()
        