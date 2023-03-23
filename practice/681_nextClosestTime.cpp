/*
681. Next Closest Time
Given a time represented in the format "HH:MM", form the next closest time by reusing the current digits. There is no limit on how many times a digit can be reused.

You may assume the given input string is always valid. For example, "01:34", "12:09" are all valid. "1:34", "12:9" are all invalid.
*/
class Solution {
public:
  string nextClosestTime(string time) {
    set<char> num;
    for (auto ch: time){
      if (ch != ':')
        num.insert(ch);
    }
    string ans=time;
    for (int i=time.size() - 1; i>=0; i--){
      if (time[i] == ':')
        continue;
      auto it = num.find(time[i]);
      if (*it != *num.rbegin()){
        it++;
        ans[i] = *it;
        if((i >= 3 && stoi(ans.substr(3, 2))< 60) ||
          (i < 2 && stoi(ans.substr(0, 2))< 24))       
          return ans;      
      }
      ans[i] = *num.begin();
    }
    return ans;
  }
};
