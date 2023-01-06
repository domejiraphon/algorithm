/*
359. Logger Rate Limiter
Design a logger system that receives a stream of messages along with their timestamps. Each unique message should only be printed at most every 10 seconds (i.e. a message printed at timestamp t will prevent other identical messages from being printed until timestamp t + 10).

All messages will come in chronological order. Several messages may arrive at the same timestamp.

Implement the Logger class:

Logger() Initializes the logger object.
bool shouldPrintMessage(int timestamp, string message) Returns true if the message should be printed in the given timestamp, otherwise returns false.

*/
class Logger {
  unordered_map<string, int> time;
public:
  Logger() {
    
  }
  
  bool shouldPrintMessage(int timestamp, string message) {
    if (time.count(message)){
      int prev = time[message];
      if (timestamp - time[message] >= 10){
        time[message] = timestamp;
        return true;
      }
      else
        return false;
    }
    else {
      time[message] = timestamp;
      return true;
    }
  }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */
