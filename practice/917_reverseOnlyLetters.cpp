/*
917. Reverse Only Letters
Given a string s, reverse the string according to the following rules:

All the characters that are not English letters remain in the same position.
All the English letters (lowercase or uppercase) should be reversed.
Return s after reversing it.
*/
class Solution {
public:
  string reverseOnlyLetters(string s) {
    int n=s.size();
    int left=0, right=n - 1;
    while (left < right){
      while (left<right && !isalpha(s[left]))
        left++;
      while (left < right && !isalpha(s[right]))
        right--;
      //if (left > right)
      //  break;
      
      swap(s[left++], s[right--]);
      //cout << s << endl;
    }
    return s;
  }
};
