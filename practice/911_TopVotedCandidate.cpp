/*
911. Online Election
You are given two integer arrays persons and times. In an election, the ith vote was cast for persons[i] at time times[i].

For each query at a time t, find the person that was leading the election at time t. Votes cast at time t will count towards our query. In the case of a tie, the most recent vote (among tied candidates) wins.

Implement the TopVotedCandidate class:

TopVotedCandidate(int[] persons, int[] times) Initializes the object with the persons and times arrays.
int q(int t) Returns the number of the person that was leading the election at time t according to the mentioned rules.
*/
class TopVotedCandidate {
  map<int, int> voted;
public:
  TopVotedCandidate(vector<int>& persons, vector<int>& times) {
    int n=persons.size();
    map<int, int> cur;
    int lead=-1;
    for (int i=0; i<n; i++){
      cur[persons[i]]++;
      lead = (cur[persons[i]] >= cur[lead]) ? persons[i] : lead;
      voted[times[i]] = lead;
    }
  }

  int q(int t) {
    auto it= voted.upper_bound(t);
    
    return prev(it) -> second;
  }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */
