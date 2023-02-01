/*
433. Minimum Genetic Mutation

A gene string can be represented by an 8-character long string, with choices from 'A', 'C', 'G', and 'T'.

Suppose we need to investigate a mutation from a gene string startGene to a gene string endGene where one mutation is defined as one single character changed in the gene string.

For example, "AACCGGTT" --> "AACCGGTA" is one mutation.
There is also a gene bank bank that records all the valid gene mutations. A gene must be in bank to make it a valid gene string.

Given the two gene strings startGene and endGene and the gene bank bank, return the minimum number of mutations needed to mutate from startGene to endGene. If there is no such a mutation, return -1.

Note that the starting point is assumed to be valid, so it might not be included in the bank.

 
*/
class Solution {
public:
  int minMutation(string start, string end, vector<string>& bank) {
    queue<string> Q;
    Q.push(start);
    int num=0;
    unordered_set<string> bankDict = {bank.begin(), bank.end()};
    unordered_set<string> seen;
    while (!Q.empty()){
      int n=Q.size();
      for (int i=0; i<n; i++){
        string cur = Q.front();
        Q.pop();
        if (cur == end)
          return num;
        for (int j=0; j<10; j++){
          for (char ch: "ACGT"){
            string mut = cur;
            mut[j] = ch;
            if (bankDict.count(mut) && !seen.count(mut)){
              seen.insert(mut);
              Q.push(mut);
            }
          }
        }
      }
      num++;
    }
    return -1;
  }
};
