/*
895. Maximum Frequency Stack

Design a stack-like data structure to push elements to the stack and pop the most frequent element from the stack.

Implement the FreqStack class:

FreqStack() constructs an empty frequency stack.
void push(int val) pushes an integer val onto the top of the stack.
int pop() removes and returns the most frequent element in the stack.
If there is a tie for the most frequent element, the element closest to the stack's top is removed and returned.
*/
class FreqStack {
  unordered_map<int, int> freq;
  unordered_map<int, stack<int>> group;
  int maxFreq;
public:
  FreqStack() {
    maxFreq = 1;
  }
  
  void push(int val) {
    freq[val]++;
    if (freq[val] > maxFreq){
      maxFreq = freq[val];
    }
    group[freq[val]].push(val);
  }
  
  int pop() {
    int tmp = group[maxFreq].top();
    group[maxFreq].pop();
    freq[tmp]--;
    if (group[maxFreq].size() == 0)
      maxFreq--;

    return tmp;
  }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
