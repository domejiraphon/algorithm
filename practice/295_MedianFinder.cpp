class Compare1 {
public:
  bool operator () (int& a, int& b){
    return a < b;
  }
};

class Compare2 {
public:
  bool operator () (int& a, int& b){
    return a > b;
  }
};

class MedianFinder {
  priority_queue<int, vector<int>, Compare1> LeftHeap;
  priority_queue<int, vector<int>, Compare2> RightHeap;
public:
  MedianFinder() {
      
  }
  
  void addNum(int num) {
    LeftHeap.push(num);
    RightHeap.push(LeftHeap.top());
    LeftHeap.pop();
    if (LeftHeap.size() < RightHeap.size()){
      LeftHeap.push(RightHeap.top());
      RightHeap.pop();
    }
  }
  
  double findMedian() {
    int n=LeftHeap.size() + RightHeap.size();
    return (n % 2 == 0) ? (double) (LeftHeap.top() + RightHeap.top())/2 : LeftHeap.top();
  }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */