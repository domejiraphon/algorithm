/*
Given an array of characters chars, compress it using the following algorithm:

Begin with an empty string s. For each group of consecutive repeating characters in chars:

If the group's length is 1, append the character to s.
Otherwise, append the character followed by the group's length.
The compressed string s should not be returned separately, but instead, be stored in the input character array chars. Note that group lengths that are 10 or longer will be split into multiple characters in chars.

After you are done modifying the input array, return the new length of the array.

You must write an algorithm that uses only constant extra space.

 
*/
class Solution {
public:
  int compress(vector<char>& chars) {
    int i = 0, res = 0;
    int n=chars.size();
    while (i < n){
      int group = 1;
      while (i+ group < n && chars[i + group] == chars[i])
        group++;
      chars[res++] = chars[i];
      if (group > 1){
        for (auto ch: to_string(group))
          chars[res++] = ch;
      }
      i += group;
    }
    return res;
  }
};