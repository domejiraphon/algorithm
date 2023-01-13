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
        if (x ==  y)
          continue;
        if (x == first && y==0)
          continue;
        
        int res=0;
        int tmp=num;
        int carry=0;
        while (tmp > 0){
          int cur = tmp % 10;
          if (cur == x)
            res += pow(10, carry) * y;
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
