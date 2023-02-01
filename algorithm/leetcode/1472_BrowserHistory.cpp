/*
1472. Design Browser History
You have a browser of one tab where you start on the homepage and you can visit another url, get back in the history number of steps or move forward in the history number of steps.

Implement the BrowserHistory class:

BrowserHistory(string homepage) Initializes the object with the homepage of the browser.
void visit(string url) Visits url from the current page. It clears up all the forward history.
string back(int steps) Move steps back in history. If you can only return x steps in the history and steps > x, you will return only x steps. Return the current url after moving back in history at most steps.
string forward(int steps) Move steps forward in history. If you can only forward x steps in the history and steps > x, you will forward only x steps. Return the current url after forwarding in history at most steps.
*/
class BrowserHistory {
  vector<string> links;
  int ptr;
public:
  BrowserHistory(string homepage) {
    links.push_back(homepage);
    ptr=0;
  }
  
  void visit(string url) {
    while (ptr < links.size()-1)
      links.pop_back();
    links.push_back(url);
    ptr++;
  }
  
  string back(int steps) {
    ptr = max(ptr - steps, 0);
    
    return links[ptr];
      
  }
  
  string forward(int steps) {
  
    ptr = min(steps + ptr, (int)links.size() - 1);
    return links[ptr];
  }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
