/*858. Mirror Reflection
 * There is a special square room with mirrors on each of the four walls. 
 Except for the southwest corner, there are receptors on each of the remaining corners, numbered 0, 1, and 2.
 The square room has walls of length p and a laser ray from the southwest corner first meets 
 the east wall at a distance q from the 0th receptor.
  
  Given the two integers p and q, return the number of the receptor that the ray meets first.
  The test cases are guaranteed so that the ray will meet a receptor eventually.
*/
class Solution {
public:
  int mirrorReflection(int p, int q) {
    int lcm = (p * q) / gcd(p, q);
    int m = lcm / p;
    int n = lcm / q;
    if (m % 2 == 0 && n %2 == 1){return 0;}
    else if (m % 2 == 1 && n %2 == 1){return 1;}
    else {return 2;}
  }
private:
  int gcd(int a, int b) {
    while(b) {
      a = a % b;
      swap(a, b);
    }
    return a;
  }
};
