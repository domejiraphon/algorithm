/*
1563. Stone Game V
There are several stones arranged in a row, and each stone has an associated value which is an integer given in the array stoneValue.

In each round of the game, Alice divides the row into two non-empty rows (i.e. left row and right row), then Bob calculates the value of each row which is the sum of the values of all the stones in this row. Bob throws away the row which has the maximum value, and Alice's score increases by the value of the remaining row. If the value of the two rows are equal, Bob lets Alice decide which row will be thrown away. The next round starts with the remaining row.

The game ends when there is only one stone remaining. Alice's is initially zero.

Return the maximum score that Alice can obtain.
*/
class Solution {
public:
  int stoneGameV(vector<int>& stoneValue) {
    int n=stoneValue.size();
    vector<int> prefix(n+1, 0);
    for (int i=0; i<n; i++)
      prefix[i+1] = prefix[i]+stoneValue[i];
    vector<vector<int>> memo(n, vector<int>(n, -1));
    int out = maxAlice(prefix, 0, n-1, memo);
    
    return out;
  }
private:
  int maxAlice(vector<int>& stone, int start, int end, vector<vector<int>>& memo){
    if (start == end)
      return 0;
    if (memo[start][end] != -1)
      return memo[start][end];
    int out=0;
    for (int i=start; i<end; i++){
      int left = stone[i+1] - stone[start];
      int right = stone[end+1] - stone[i+1];
      if (left <= right)
        out = max(out, left + maxAlice(stone, start, i, memo));
      if (right <= left)
        out = max(out, right + maxAlice(stone, i+1, end, memo));
    }
    return memo[start][end] = out;
  }

};
