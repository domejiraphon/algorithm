class Solution2 {
  vector<int> nums;
  vector<int> used;
  int n;
public:
  bool makesquare(vector<int>& matchsticks) {
    //sort(matchsticks.begin(), matchsticks.end());
    long long target=0;
    n=matchsticks.size();
    for (int i=0; i<n; i++){target += matchsticks[i];}
    if (target % 4 != 0){return false;}
    nums = matchsticks;
    used.resize(n, false);
    target = target / 4;
    bool possible=true;
  
    for (int i=0; i<4 && possible; i++){
      possible = possible && backtrack(i, target);
    }
    return possible;
  }
private:
  bool backtrack(int i, int target){
    if (target == 0 && i <= n){return true;}
    if (i > n || target < 0){return false;}
    bool usedCur=false, notCur=false;
    if (i < n && !used[i]){
      used[i] = true;
      usedCur = backtrack(i + 1, target - nums[i]);
      if (!usedCur)
        used[i] = false;
    }
    if (!usedCur){
      notCur = backtrack(i + 1, target);
    }
    
    return usedCur || notCur;
  }
};

class Solution {
  vector<int> nums;
  int n,a,b,c,d;
public:
  bool makesquare(vector<int>& matchsticks) {
    int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
    if (sum % 4 != 0){return false;}
    a = b = c = d = sum / 4;
    n = matchsticks.size();
    sort(matchsticks.rbegin(), matchsticks.rend());
    nums = matchsticks;
    return backtrack(0);
  }
private:
  bool backtrack(int i){
    if (i == n)
      return (a == 0 && a == b && c == d && b == c) ? true : false;
    if (nums[i] <= a){
      a -= nums[i];
      if (backtrack(i + 1)) 
        return true;
      a += nums[i];
    }

    if (nums[i] <= b){
      b -= nums[i];
      if (backtrack(i + 1)) 
        return true;
      b += nums[i];
    }

    if (nums[i] <= c){
      c -= nums[i];
      if (backtrack(i + 1)) 
        return true;
      c += nums[i];
    }

    if (nums[i] <= d){
      d -= nums[i];
      if (backtrack(i + 1)) 
        return true;
      d += nums[i];
    }

    return false;
  }
};