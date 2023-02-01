/*
818. Race Car
Your car starts at position 0 and speed +1 on an infinite number line. Your car can go into negative positions. Your car drives automatically according to a sequence of instructions 'A' (accelerate) and 'R' (reverse):

When you get an instruction 'A', your car does the following:
position += speed
speed *= 2
When you get an instruction 'R', your car does the following:
If your speed is positive then speed = -1
otherwise speed = 1
Your position stays the same.
For example, after commands "AAR", your car goes to positions 0 --> 1 --> 3 --> 3, and your speed goes to 1 --> 2 --> 4 --> -1.

Given a target position target, return the length of the shortest sequence of instructions to get there.
*/
class Solution {
public:
  int racecar(int target) {
    vector<int> memo(target+1, INT_MAX);
    return dp(target, memo);
  }
private:
  int dp(int i, vector<int>& memo){
    if (i == 0)
      return 0;
    if (memo[i] != INT_MAX)
      return memo[i];
    
    int m=1, j=1;
    while (j < i){
      int p=0, q=0;
      while (p < j){
        memo[i] = min(memo[i], m + 1 + q + 1 + dp(i - (j - p), memo));
        p = pow(2, ++q) - 1;
      }
      j = (1 << ++m) - 1;
    }
    
    if (j == i)
      memo[i] = min(memo[i], m);
    else if (j > i)
      memo[i] = min(memo[i], m + 1 + dp(j - i, memo));
    return memo[i];
  }
};