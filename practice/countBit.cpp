#include <iostream>

using namespace std; 

int countNumber(int n){
  int count=0;
  
  for (int i=0; i<32; i++){
    if (n == 0)
      break;
    if (n & 1)
      count++;
    n = n >> 1;
  }
  return count;
}

int main(){
  cout << countNumber(2) << endl;
  cout << countNumber(3) << endl;
}
