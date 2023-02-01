class Solution {
  int m = pow(10, 9) + 7;
public:
  int numPrimeArrangements(int n) {
		int ans=1;
    for(int i=2; i<=n; i++){
        int j=3;
        while(j<i){
          if(i%j==0) break;
          j+=2;
        }
        if(j==i) ans++;
      }
    long out = fact(ans) * fact(n - ans) % m;
    return out;
  }
private:
  long fact(int n){
    long out(1);
    for (int i=1; i<=n; i++){
      out = (out * i) % m;
    }
    return out % m;
  }
};