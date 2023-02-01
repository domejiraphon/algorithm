/*
1366. Rank Teams by Votes
In a special ranking system, each voter gives a rank from highest to lowest to all teams participating in the competition.

The ordering of teams is decided by who received the most position-one votes. If two or more teams tie in the first position, we consider the second position to resolve the conflict, if they tie again, we continue this process until the ties are resolved. If two or more teams are still tied after considering all positions, we rank them alphabetically based on their team letter.

You are given an array of strings votes which is the votes of all voters in the ranking systems. Sort all teams according to the ranking system described above.

Return a string of all teams sorted by the ranking system.
*/
class Solution {
public:
  string rankTeams(vector<string>& votes) {
    int n=votes[0].size();
    int ranking[26][n];
    memset(ranking, 0, sizeof(ranking));
    for (auto vote: votes){
      for (int i=0; i<n; i++)
        ranking[vote[i] - 'A'][i]++;
    }
    
    sort(votes[0].begin(), votes[0].end(), 
        [&ranking, &n](char& a, char& b){
        for (int i=0; i<n; i++){
          if (ranking[a - 'A'][i] > ranking[b - 'A'][i])
            return true;
          else if (ranking[a - 'A'][i] < ranking[b - 'A'][i])
            return false;
        }
        return a < b;
      });
    return votes[0];
  }
};