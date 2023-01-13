/*
1628. Design an Expression Tree With Evaluate Function
Given the postfix tokens of an arithmetic expression, build and return the binary expression tree that represents this expression.

Postfix notation is a notation for writing arithmetic expressions in which the operands (numbers) appear before their operators. For example, the postfix tokens of the expression 4*(5-(7+2)) are represented in the array postfix = ["4","5","7","2","+","-","*"].

The class Node is an interface you should use to implement the binary expression tree. The returned tree will be tested using the evaluate function, which is supposed to evaluate the tree's value. You should not remove the Node class; however, you can modify it as you wish, and you can define other classes to implement it if needed.

A binary expression tree is a kind of binary tree used to represent arithmetic expressions. Each node of a binary expression tree has either zero or two children. Leaf nodes (nodes with 0 children) correspond to operands (numbers), and internal nodes (nodes with two children) correspond to the operators '+' (addition), '-' (subtraction), '*' (multiplication), and '/' (division).

It's guaranteed that no subtree will yield a value that exceeds 109 in absolute value, and all the operations are valid (i.e., no division by zero).

Follow up: Could you design the expression tree such that it is more modular? For example, is your design able to support additional operators without making changes to your existing evaluate implementation?


*/
/**
 * This is the interface for the expression tree Node.
 * You should not remove it, and you can define some classes to implement it.
 */

class Node {
public:
  virtual ~Node () {};
  virtual int evaluate() const = 0;
};

class NumNode: public Node {
private:
  int val;
  int evaluate () const {
    return val;
  }
public:
  NumNode(int v){
    val = v;
  }
};

class OpNode: public Node {
private:
  char sign;
  Node* left=nullptr;
  Node* right=nullptr;
public:
  OpNode(char s, Node* l, Node* r){
    sign = s;
    left = l;
    right = r;
  }
  int evaluate () const {
    int num1 = left -> evaluate();
    int num2 = right -> evaluate();
    switch (sign) {
      case '+':
        return num1 + num2;
      case '-':
        return num1 - num2;
      case '*':
        return num1 * num2;
      case '/':
        return num1 / num2;
      default:
        return 0;
    } 
  }
};

/**
 * This is the TreeBuilder class.
 * You can treat it as the driver code that takes the postinfix input 
 * and returns the expression tree represnting it as a Node.
 */

class TreeBuilder {
public:
  Node* buildTree(vector<string>& postfix) {
    stack<Node*> stk;
    for (auto token: postfix){
      if (isdigit(token[0]))  
        stk.push(new NumNode(getNumber(token)));
      else{
        auto right = stk.top(); stk.pop();
        auto left = stk.top(); stk.pop();
        stk.push(new OpNode(token[0], left, right));
      }
    }
    return stk.top();
  }
private:
  int getNumber(string s){
    int n=s.size();
    int i=0;
    int cur=0;
    while (i<n && isdigit(s[i])){
      cur = 10 * cur + (s[i++] - '0');
    }
    return cur;
  }
};


/**
 * Your TreeBuilder object will be instantiated and called as such:
 * TreeBuilder* obj = new TreeBuilder();
 * Node* expTree = obj->buildTree(postfix);
 * int ans = expTree->evaluate();
 */
