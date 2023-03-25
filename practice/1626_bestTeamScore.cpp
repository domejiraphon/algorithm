/*
1626. Best Team With No Conflicts
You are the manager of a basketball team. For the upcoming tournament, you want to choose the team with the highest overall score. The score of the team is the sum of scores of all the players in the team.

However, the basketball team is not allowed to have conflicts. A conflict exists if a younger player has a strictly higher score than an older player. A conflict does not occur between players of the same age.

Given two lists, scores and ages, where each scores[i] and ages[i] represents the score and age of the ith player, respectively, return the highest overall score of all possible basketball teams.
*/
class Solution {
public:
  int bestTeamScore(vector<int>& scores, vector<int>& ages) {
    vector<pair<int, int>> pairScores;
    int n=ages.size();
    vector<vector<int>> memo(n+1, vector<int>(n, -1));
    for (int i=0; i<n; i++)
      pairScores.push_back({ages[i], scores[i]});
    sort(pairScores.begin(), pairScores.end());
    return bestScore(pairScores, -1, 0, memo);
  }
private:
  int bestScore(vector<pair<int, int>>& pairScores, int bound, int i, vector<vector<int>>& memo){
    if (i == pairScores.size())
      return 0;
    if (memo[bound+1][i] != -1)
      return memo[bound+1][i];
    int out = bestScore(pairScores, bound, i+1, memo);
    if (bound == -1 || pairScores[i].second >= pairScores[bound].second)
      out = max(out, pairScores[i].second + bestScore(pairScores, i, i+1, memo));
    return memo[bound+1][i] = out;
  }
};
