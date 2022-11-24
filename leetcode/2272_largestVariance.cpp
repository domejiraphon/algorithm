class Solution {
public:
  int largestVariance(string s) {
    int largest=0;
    
    for(char p='a'; p <= 'z'; p++){
      for (char q='a'; q <= 'z'; q++){
        if (p == q){continue;}
        bool extend(false);
        int pFreq = 0;
        int qFreq = 0;
        for (auto ch: s){
          if (ch == p){pFreq++;}
          else if (ch == q){qFreq++;}
          
          if (qFreq > 0){
            largest = max(largest, pFreq - qFreq);
          }
          else if (qFreq == 0 && extend) {
            largest = max(largest, pFreq - 1);
          }
          if (qFreq > pFreq){
            pFreq = 0;
            qFreq = 0;
            extend = true;
          }
        }
        
      }
    }
    return largest;
  }
};
