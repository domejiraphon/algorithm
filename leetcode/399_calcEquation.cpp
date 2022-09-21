#include <iostream>
#include <iterator>
#include <map>
#include <unordered_map>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

void print(unordered_map<string, double> hashTable){
  for (auto it = hashTable.begin(); it != hashTable.end(); it++){
    cout<< it -> first<< ", "<< it -> second<< endl;
  }
}

void print(vector<double> vect){
  for (auto it : vect){
    cout<< it << ", ";
  }
  cout << endl;
}

void print(vector<vector<string>> vect){
  for (auto it : vect){
    for (auto ele: it){
      cout << ele << ", ";
    }
    cout << endl;
  }
  
}

class Solution {
public:
  vector<double> calcEquation(vector<vector<string>>& equations, 
                        vector<double>& values, 
                        vector<vector<string>>& queries) {
    vector<double> out;
    sort(equations.begin(), equations.end());
    
    unordered_map<string, double> hashTable;
    for (int i=0; i != equations.size(); i++){
      if (hashTable.find(equations[i][0]) == hashTable.end()){
        if (hashTable.find(equations[i][1]) == hashTable.end()){
          hashTable[equations[i][0]] = values[i];
          hashTable[equations[i][1]] = 1.0;
        }
        else {hashTable[equations[i][0]] = values[i] * hashTable[equations[i][1]];}
      }
      else {hashTable[equations[i][1]] = hashTable[equations[i][0]]/ values[i];}
    }
    print(hashTable);
    exit(0);
    for (int i=0; i != queries.size(); i++){
      if (hashTable.find(queries[i][0]) != hashTable.end() &&
          hashTable.find(queries[i][1]) != hashTable.end()){
            out.push_back(hashTable[queries[i][0]] / hashTable[queries[i][1]]);
          }
      else { out.push_back(-1.0);}
    }
    return out;
      
  }
};

int main()
{ 
  
  Solution* sol;
  vector<vector<string>> equations = {{"a", "b"}, {"b", "c"}};
  vector<double> values = {2.0, 3.0};
  vector<vector<string>> queries = {{"a", "c"}, {"b", "a"}, {"a", "e"}, {"a", "a"}, {"x", "x"}};
  vector<double> out; 
  //out = sol -> calcEquation(equations, values, queries);
  //print(out);

  equations = vector<vector<string>> {{"a", "b"}, {"e", "f"}, {"b", "e"}};
  values = vector<double> {3.4, 1.4, 2.3};
  queries = vector<vector<string>> {{"b", "a"}, {"a", "f"}, {"f", "f"}, {"e", "e"}, {"c", "c"}, {"a", "c"}, {"f", "e"}};
  out = sol -> calcEquation(equations, values, queries);
  print(out);

  
  
  return 0;
}