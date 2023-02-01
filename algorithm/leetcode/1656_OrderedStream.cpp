/*
1656. Design an Ordered Stream
There is a stream of n (idKey, value) pairs arriving in an arbitrary order, where idKey is an integer between 1 and n and value is a string. No two pairs have the same id.

Design a stream that returns the values in increasing order of their IDs by returning a chunk (list) of values after each insertion. The concatenation of all the chunks should result in a list of the sorted values.

Implement the OrderedStream class:

OrderedStream(int n) Constructs the stream to take n values.
String[] insert(int idKey, String value) Inserts the pair (idKey, value) into the stream, then returns the largest possible chunk of currently inserted values that appear next in the order.

*/
class OrderedStream {
  vector<string> arr;
  int ptr;
  int N;
public:
  OrderedStream(int n) {
    arr.resize(n, "");
    ptr = 0;
    N = n;
  }
  
  vector<string> insert(int idKey, string value) {
    arr[idKey - 1] = value;
    vector<string> res;
  
    while (ptr < N && arr[ptr] != ""){
      res.push_back(arr[ptr++]);
    }

    return res;

  }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */
