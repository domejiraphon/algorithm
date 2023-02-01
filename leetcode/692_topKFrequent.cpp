/*
692. Top K Frequent Words
Given an array of strings words and an integer k, return the k most frequent strings.

Return the answer sorted by the frequency from highest to lowest. Sort the words with the same frequency by their lexicographical order.
*/
class Compare {
public:
  bool operator () (pair<int, string> a, pair<int, string> b){
    if (a.first == b.first){
      return a.second < b.second;
    }
    else {
      return a.first > b.first;
    }
    
  }
};
class Solution {
public:
  vector<string> topKFrequent(vector<string>& words, int k) {
    unordered_map<string, int> freq;
    int n=words.size();
    for (int i=0; i< n; i++){
      freq[words[i]]++;
    }
    priority_queue<pair<int, string>, vector<pair<int, string>>, Compare> minHeap;
    for (auto it=freq.begin(); it != freq.end(); it++){
      minHeap.push({it -> second, it -> first});
      if (minHeap.size() > k){minHeap.pop();}
    }
    vector<string> res(k);
    for (int i=k-1; i>=0; i--){
      res[i] = minHeap.top().second;
      minHeap.pop();
    }
    return res;
  }
};