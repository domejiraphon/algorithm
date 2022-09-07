import os, sys
from loguru import logger  
import numpy as np
from typing import List
import math 

class Solution:
  def uniquePaths(self, m: int, n: int) -> int:
    grid = np.ones((m, n)).astype(int)
    for i in range(1, m):
      for j in range(1, n):
        grid[i][j] = grid[i-1][j] + grid[i][j-1]
    return grid[-1][-1]
        

@logger.catch
def main():
  sol = Solution()
  #nums = [5,4,-1,7,8]
  #nums=[-2, 1]
  print(sol.uniquePaths(3, 7))

if __name__ == "__main__":
  main()
        