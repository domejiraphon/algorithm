/*
332. Reconstruct Itinerary
You are given a list of airline tickets where tickets[i] = [fromi, toi] represent the departure and the arrival airports of one flight. Reconstruct the itinerary in order and return it.

All of the tickets belong to a man who departs from "JFK", thus, the itinerary must begin with "JFK". If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string.

For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
You may assume all tickets form at least one valid itinerary. You must use all the tickets once and only once.
*/
class Solution {
  set<vector<string>> tix;
public:
  vector<string> findItinerary(vector<vector<string>>& tickets) {
    tix = {tickets.begin(), tickets.end()};
    unordered_map<string, set<string>> graph;
    for (auto ticket: tickets)
      graph[ticket[0]].insert(ticket[1]);
    vector<string> res;
    string cur = "JFK";
    res.push_back(cur);
    dfs(graph, cur, res);
    return res;
  }
private:
  void dfs(unordered_map<string, set<string>>& graph, string& cur, vector<string>& res){
    for (auto neigh: graph[cur]){
      if (tix.count({cur, neigh})){
        res.push_back(neigh);
        tix.erase({cur, neigh});
        dfs(graph, neigh, res);
      }
    }
  }
};
