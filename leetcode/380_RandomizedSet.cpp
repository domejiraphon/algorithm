#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <tuple>
#include <unordered_set>
using namespace std;
void print(const vector<int> x){
  for (auto row: x){
    cout << row << " ";
  }
  cout << endl;
}

class RandomizedSet {
public:
    vector<int> nums;
    map<int,int> hashTable;
    
    bool insert(int val) {
      if (hashTable.find(val) == hashTable.end()){
        hashTable[val] = nums.size();
        nums.push_back(val); return true;
      }
      else {return false;}
    }
    
    bool remove(int val) {
      if (hashTable.find(val) == hashTable.end()){
        return false;
      }
      else {
        hashTable[nums[nums.size() - 1]] = hashTable[val];
        swap(nums[hashTable[val]], nums[nums.size() - 1]);
        nums.erase(nums.begin() + nums.size() - 1);
        hashTable.erase(val);
        return true;
      }
    }
    
    int getRandom() {
      return nums[rand() % nums.size()];
    }
};

int main()
{ 
  RandomizedSet* obj = new RandomizedSet();
  obj->insert(0);
  obj->insert(1);
  obj->remove(0);
  
  obj->insert(2);
  obj->remove(1);
  print(obj -> nums);
  cout << obj->getRandom() <<endl;
  
  return 0;
}