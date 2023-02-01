/*
2232. Minimize Result by Adding Parentheses to Expression
You are given a 0-indexed string expression of the form "<num1>+<num2>" where <num1> and <num2> represent positive integers.

Add a pair of parentheses to expression such that after the addition of parentheses, expression is a valid mathematical expression and evaluates to the smallest possible value. The left parenthesis must be added to the left of '+' and the right parenthesis must be added to the right of '+'.

Return expression after adding a pair of parentheses such that expression evaluates to the smallest possible value. If there are multiple answers that yield the same result, return any of them.

The input has been generated such that the original value of expression, and the value of expression after adding any pair of parentheses that meets the requirements fits within a signed 32-bit integer.

 
*/
class Solution {
public:
  string minimizeResult(string expression) {
    int posAdd = expression.find('+');
    string num1 = expression.substr(0, posAdd);
    string num2 = expression.substr(posAdd+1);
    int n=num1.size();
    int m=num2.size();
    int ans=INT_MAX;
    string cur;
    
    for (int i=0; i<n; i++){
      int n1 = (i ==0)? 1:stoi(num1.substr(0, i));
      int n2 = stoi(num1.substr(i));
      for (int j=1; j<=m; j++){
        int m1 = stoi(num2.substr(0, j));
        int m2 = (j == m) ? 1 : stoi(num2.substr(j));
        if (ans > n1 * (n2 + m1) * m2){
          cur = num1.substr(0, i) + "(" + num1.substr(i)+ "+" +num2.substr(0, j) +")" + num2.substr(j);       
          ans = n1 * (n2 + m1) * m2;
        }
      }
    }
    return cur;
  }
};