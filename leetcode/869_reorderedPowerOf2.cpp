/*
869. Reordered Power of 2
You are given an integer n. We reorder the digits in any order (including the original order) such that the leading digit is not zero.

Return true if and only if we can do this so that the resulting number is a power of two.
*/
class Solution {
public:
  bool reorderedPowerOf2(int n) {
    int numDigit = log10(n)+1;
    int cur=1;
    vector<int> freqN = countFreq(n);
    vector<int> target;
    while (log10(cur) <= numDigit){
      int nu = (int) log10(cur)+1;
      if (nu == numDigit){
        target = countFreq(cur);
        bool found=true; 
        for (int j=0; j<10 && found; j++){
          if (freqN[j] != target[j])
            found = false;
        }
        if (found)
          return true;
      }
      if (cur > pow(10, 9)+1)
        break;
      cur = 2 * cur;
    }
    
    return false;
  }
private:
  vector<int> countFreq(int n){
    vector<int> freq(10, 0);
    while (n > 0){
      freq[n % 10]++;
      n /= 10;
    }
    return freq;
  }
};
