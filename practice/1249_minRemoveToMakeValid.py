import os, sys
from loguru import logger  
import numpy as np
from typing import List

class Solution:
  def minRemoveToMakeValid(self, s: str) -> str:
    idx = {"(":[], ")": []}
    
    for i in range(len(s)):
      if s[i] == "(":
        if len(idx["("]) >= len(idx[")"]):
          idx[s[i]].append(i)
      elif s[i] == ")":
        if len(idx["("]) > len(idx[")"]):
          idx[s[i]].append(i)
    idx["("] = idx["("][:min(len(idx["("]), len(idx[")"]))]
    idx[")"] = idx[")"][:min(len(idx["("]), len(idx[")"]))]
  
    out = ""
    for i in range(len(s)):
      if s[i] in ["(", ")"]:
        if i in idx["("] or i in idx[")"]:
          out += s[i]
      else:
        out += s[i]
    return out

@logger.catch
def main():
 
  sol = Solution()
  print(sol.minRemoveToMakeValid("lee(t(c)o)de)"))
  print(sol.minRemoveToMakeValid("a)b(c)d"))
  print(sol.minRemoveToMakeValid("))(("))
  print(sol.minRemoveToMakeValid("a)b(c)d"))


if __name__ == "__main__":
  main()
        