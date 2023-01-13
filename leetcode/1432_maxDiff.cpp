/*
1432. Max Difference You Can Get From Changing an Integer
You are given an integer num. You will apply the following steps exactly two times:

Pick a digit x (0 <= x <= 9).
Pick another digit y (0 <= y <= 9). The digit y can be equal to x.
Replace all the occurrences of x in the decimal representation of num by y.
The new integer cannot have any leading zeros, also the new integer cannot be 0.
Let a and b be the results of applying the operations to num the first and second times, respectively.

Return the max difference between a and b.


*/
class Solution {
public:
  int maxDiff(int num) {
    int maxVal = num;
    int minVal = num;
    int first=num;
    while (first >= 10)
      first /= 10;
    
    for (int x=0; x< 10; x++){
      for (int y=0; y< 10; y++){
        
        if (x == first && y==0)
          continue;
        
        int res=0;
        int tmp=num;
        int carry=0;
        
        while (tmp > 0){
          int cur = tmp % 10;
          if (cur == x)
            res += pow(10, carry) * y;
          else
            res += pow(10, carry) * cur;
          tmp /= 10;
          carry++;
        }
        
       
        maxVal = max(maxVal, res);
        minVal = min(minVal, res);
      }
    }
    cout << maxVal << endl;
    cout << minVal << endl;
    return maxVal - minVal;
  }
};