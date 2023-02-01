/*
2102. Sequentially Ordinal Rank Tracker
A scenic location is represented by its name and attractiveness score, where name is a unique string among all locations and score is an integer. Locations can be ranked from the best to the worst. The higher the score, the better the location. If the scores of two locations are equal, then the location with the lexicographically smaller name is better.

You are building a system that tracks the ranking of locations with the system initially starting with no locations. It supports:

Adding scenic locations, one at a time.
Querying the ith best location of all locations already added, where i is the number of times the system has been queried (including the current query).
For example, when the system is queried for the 4th time, it returns the 4th best location of all locations already added.
Note that the test data are generated so that at any time, the number of queries does not exceed the number of locations added to the system.

Implement the SORTracker class:

SORTracker() Initializes the tracker system.
void add(string name, int score) Adds a scenic location with name and score to the system.
string get() Queries and returns the ith best location, where i is the number of times this method has been invoked (including this invocation).

*/
struct Node {
  string name;
  int score;
  Node(string n, int s){
    name = n;
    score = s;
  }
  bool operator<(const Node & l) const {
    return score > l.score || (score == l.score && name < l.name);
  }
};

class SORTracker {
  set<Node> locations;
  set<Node>::iterator it;
public:
  SORTracker() {
    
  }
  
  void add(string name, int score) {
    auto scene = Node(name, score);
    if (locations.empty()){
      locations.insert(scene);
      it = locations.begin();
      return;
    }
    locations.insert(scene);
    if (it == locations.end() || scene < *it) 
      it--;
  }
  
  string get() {
    string temp = it -> name;
    it++;
    return temp;
  }
};

/**
 * Your SORTracker object will be instantiated and called as such:
 * SORTracker* obj = new SORTracker();
 * obj->add(name,score);
 * string param_2 = obj->get();
 */
