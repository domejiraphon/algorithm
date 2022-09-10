#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <tuple>

using namespace std;
class Solution {
public:
  string decodeString(string s) {
    string out="";
    if (s.substr(2).find("[") >= s.substr(2).size()){
      string rep = s.substr(1, s.size()-1);
      int rev = stoi(string(1, s[0]));
      for (int i=0; i != rev; i++){
        out += rep.substr(1, rep.size()-2);}
      return out;
    }
    else {
      decodeHelperComposit(s);

        
        
      return out;
      }

  }

  string decodeHelperConcat(string s){
    string out="";
    while (s.find("]") < s.size()){
      string cur="";
      cur = s.substr(0, s.find("]")+1);

      s = s.substr(s.find("]")+1);
    
      out += decodeString(cur);

    }
  }

  string decodeHelperComposit(string s){
    string out="";
    if (isdigit(s[2])){
      string rep = s.substr(1, s.size()-1);
      int rev = stoi(string(1, s[0]));
      for (int i=0; i != rev; i++){
        out += decodeString(rep);}
      return out;
    }
    else {
      string first = ""; string second = "";
      for (int i=2; i!=s.size(); i++){
        if (isdigit(s[i])){second = s.substr(i, s.size()-1); break;}
        else {first += s[i];}
      }
      int rev = stoi(string(1, s[0]));
      string rec = decodeString(second);
      for (int i=0; i != rev; i++){out += first+rec;}
    }
    return out;
    }

};
int main()
{ 
  Solution sol;
  //cout<< sol.decodeString("3[ac]")<<endl;
  //cout<< sol.decodeString("3[a]2[bc]")<< endl;
  cout<< sol.decodeString("3[a2[c]]")<< endl;
  //cout<< sol.decodeString("2[abc]3[cd]ef")<< endl;
 
  return 0;
}