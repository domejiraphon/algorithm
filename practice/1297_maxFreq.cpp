/**
 * 1297. Maximum Number of Occurrences of a Substring
 * Given a string s, return the maximum number of ocurrences of any substring under the following rules:

The number of unique characters in the substring must be less than or equal to maxLetters.
The substring size must be between minSize and maxSize inclusive.
*/
class Solution {
public:
  int maxFreq(string s, int maxLetters, int minSize, int maxSize) 
  {
    int start=0,result=0;
    unordered_map<int,int> count;           	
    unordered_map<string,int> occurence;      
    for(int i=0;i<s.length();i++)		
    {
      count[s[i]]++;					
      if(i-start+1>minSize)               
      {
          if(--count[s[start]]==0)	
              count.erase(s[start]);
          start++;
      }
      if(i-start+1==minSize&&count.size()<=maxLetters)	
          result=max(result,++occurence[s.substr(start,i-start+1)]); 
    }
    return result;
  }
};
