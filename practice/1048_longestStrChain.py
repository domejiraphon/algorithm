import os, sys
from loguru import logger  
import numpy as np
from typing import List

class Solution:
  def longestStrChain(self, words: List[str]) -> int:
    words = sorted(words, key=len)
    count = 0
    wordsA = words[0]
    longest = 0
    out = []
    for i in range(len(words)):
      #print(wordsA, words[i],  self.isPredecessor(wordsA, words[i]))
      if i == 0: wordsA = words[0]
      if self.isPredecessor(wordsA, words[i]):
        count +=1  
        wordsA = words[i]
        out.append(wordsA)
      longest = max(longest, count)
    print(out)
    return longest
  
  def isPredecessor(self, wordsA: str, wordsB : str) -> bool:
    for i in range(len(wordsA)):
      tmpA_1 = wordsA[:i]
      tmpA_2 = wordsA[i:]
      for j in range(len(wordsB)-len(tmpA_1)+1):
        tmpB_1 = wordsB[j:j+len(tmpA_1)]
        tmpB_2 = wordsB[j+len(tmpA_1):]
        if tmpA_1 == tmpB_1 and tmpA_2 in tmpB_2:
          return True
    return False
      


        
@logger.catch
def main():
  nums = ["xbc","pcxbcf","xb","cxbc","pcxbc"]
  sol = Solution()
  nums=["a","b","ba","bca","bda","bdca"]
  nums = ["a","b","ba","abc","abd","bdca"]
  print(sol.longestStrChain(nums))

if __name__ == "__main__":
  main()
        