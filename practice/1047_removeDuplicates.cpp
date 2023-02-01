/** 1047. Remove All Adjacent Duplicates In String
 * 
 * You are given a string s consisting of lowercase English letters.
 *  A duplicate removal consists of choosing two adjacent and equal letters and removing them.
 * We repeatedly make duplicate removals on s until we no longer can.
 * Return the final string after all such duplicate removals have been made. 
 * It can be proven that the answer is unique.
*/
class Solution {
public:
  string removeDuplicates(string s) {
    stack<char> S;
    for (auto ele : s){
      if (!S.empty() && S.top() == ele){
        S.pop();
      }
      else {S.push(ele);}
    }
    s.clear();
    while (!S.empty()){
      s = S.top() + s; S.pop();
    }
    return s;
  }
};