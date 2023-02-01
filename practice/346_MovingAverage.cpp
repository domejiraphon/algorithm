/*
346. Moving Average from Data Stream
Given a stream of integers and a window size, calculate the moving average of all integers in the sliding window.

Implement the MovingAverage class:

MovingAverage(int size) Initializes the object with the size of the window size.
double next(int val) Returns the moving average of the last size values of the stream.
*/
class MovingAverage {
  deque<pair<int, int>> res;
  int n;
public:
  MovingAverage(int size) {
    n = size;
  }

  double next(int val) {
    if (res.size() == 0){
      res.push_back({val, val});
      return val;
    }
    int front =0;
    if (res.size() == n){
      front = res.front().second;
  
      res.pop_front();
    }
    
    res.push_back({val, res.back().second + val});
    return (double)(res.back().second - front)/ res.size();

  }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */