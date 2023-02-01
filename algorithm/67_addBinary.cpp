#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <tuple>

using namespace std;

class Solution {
public:
  string addBinary(string a, string b) {
    int min_size = a.length() < b.length() ? a.length() : b.length();
    string sub_a = a.substr(a.length() - min_size, min_size);
    string sub_b = b.substr(b.length() - min_size, min_size);
    string prefix_a = a.substr(0, a.length() - min_size);
    string prefix_b = b.substr(0, b.length() - min_size);
    string out;
    char carry('0');
    for (int i=min_size-1; i != -1; i--){
      if (sub_a[i] == '1' && sub_b[i] == '1'){
        if (carry == '1'){
          out.append("1");
        }
        else {
          out.append("0");
        } 
        carry = '1';
      }
      else if (sub_a[i] == '0' && sub_b[i] == '1'){
        if (carry == '1'){
          out.append("0");
          carry = '1';
        }
        else {
          out.append("1");
          carry = '0';
        } 
      }
      else if (sub_a[i] == '1' && sub_b[i] == '0'){
        if (carry == '1'){
          out.append("0");
          carry = '1';
        }
        else {
          out.append("1");
          carry = '0';
        } 
      }
      else if (sub_a[i] == '0' && sub_b[i] == '0'){
        if (carry == '1'){
          out.append("1");
          carry = '0';
        }
        else {
          out.append("0");
          carry = '0';
        } 
      }
    }
    
    reverseStr(out);
    string out_prefix;
    
    if (prefix_a != ""){
      for (int i=prefix_a.size()-1; i != -1; i--){
        if (prefix_a[i] == '1'){
          if (carry == '1'){
            out_prefix.append("0");
          }
          else {
            out_prefix.append("1");
          } 
          carry = '1';
        }
        else if (prefix_a[i] == '0'){
          if (carry == '1'){
            out_prefix.append("1");
          }
          else {
            out_prefix.append("0");
          } 
          carry = '0';
        }
      }
      prefix_a = "";
    }
    
    else if (prefix_b != ""){
      for (int i=prefix_b.size(); i != -1; i--){
        if (prefix_b[i] == '1'){
          if (carry == '1'){
            out_prefix.append("0");
          }
          else {
            out_prefix.append("1");
          } 
          carry = '1';
        }
        else if (prefix_b[i] == '0'){
          if (carry == '1'){
            out_prefix.append("1");
          }
          else {
            out_prefix.append("0");
          } 
          carry = '0';
        }
      }
      prefix_b = "";
    }
    cout << out_prefix << endl; exit(0);
    if (prefix_a == "" && prefix_b == "" && carry =='1'){
      out_prefix.append("1");

    }
    reverseStr(out_prefix);
  
    return out_prefix + out;
  }

  // Function to reverse a string
  void reverseStr(string& str)
  {
      int len = str.length();
      int n = len-1;
      int i = 0;
      while(i<=n){
          //Using the swap method to switch values at each index
          swap(str[i],str[n]);
          n = n-1;
          i = i+1;
    }
  
  }
};

int main()
{
  string a("1010");
  string b("1011");
  Solution sol;
  //cout << sol.addBinary(a, b) << endl;
  a = "101111"; b = "10";
  cout << sol.addBinary(a, b) << endl;
  return 0;
}