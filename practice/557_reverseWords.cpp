/*
557. Reverse Words in a String III
Given a string s, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.
*/
class Solution {
public:
  string reverseWords(string s) {
    int n=s.size();
    string cur="";
    string res="";
    for (int i=0; i<=n; i++){
      if (i == n || s[i] == ' '){
        reverse(cur);
        res += cur + ' ';
        cur = "";
      }
      else
        cur += s[i];
    }
    return res.substr(0, res.size() - 1);
  }
private:
  void reverse(string& cur){
    int left=0, right = cur.size() - 1;
    while (left < right)
      swap(cur[left++], cur[right--]);
    
  }
};
