/*
1352. Product of the Last K Numbers
Design an algorithm that accepts a stream of integers and retrieves the product of the last k integers of the stream.

Implement the ProductOfNumbers class:

ProductOfNumbers() Initializes the object with an empty stream.
void add(int num) Appends the integer num to the stream.
int getProduct(int k) Returns the product of the last k numbers in the current list. You can assume that always the current list has at least k numbers.
The test cases are generated so that, at any time, the product of any contiguous sequence of numbers will fit into a single 32-bit integer without overflowing.


*/class ProductOfNumbers {
  vector<int> prefixProd;
public:
  ProductOfNumbers() {
    prefixProd.push_back(1);
  }
  
  void add(int num) {
    if (num != 0)
      prefixProd.push_back(prefixProd.back() * num);
    else
      prefixProd = {1};
  }
  
  int getProduct(int k) {
   
    return k < prefixProd.size() ? prefixProd.back() / prefixProd[prefixProd.size() - k-1]: 0;
    
  }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
