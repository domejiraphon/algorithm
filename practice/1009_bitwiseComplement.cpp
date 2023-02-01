class Solution {
public:
  int bitwiseComplement(int n) {
    string out;
    bin(n, out);
    int k=out.size();
    int cur(0);
    for (int i=0; i< k; i++){
      out[i] = (out[i] == '0') ? '1': '0';
      cur += (out[i] - '0')*(pow(2, k-i-1));
    }
    return cur;
  }
private:
  void bin(unsigned n, string& out){
    if (n > 1)
        bin(n / 2, out);
    out += to_string(n % 2);
  }
};
