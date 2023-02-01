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
/**
 * This is the interface for the expression tree Node.
 * You should not remove it, and you can define some classes to implement it.
 */

class Node {
public:
  virtual ~Node () {};
  virtual int evaluate() const = 0;
protected:
    // define your fields here
};


/**
 * This is the TreeBuilder class.
 * You can treat it as the driver code that takes the postinfix input 
 * and returns the expression tree represnting it as a Node.
 */
class NumNode: public Node {
private:
  int num;
public:
  NumNode(string n){
    num = stoi(n);
  }

  int evaluate () const {
    return num;
  }
};



class OpNode: public Node {
private:
  char op;
  Node* left;
  Node* right;
public:
  OpNode(char o, Node* l, Node* r){
    op=o;
    left = l;
    right = r;
  }
  int evaluate () const {
    if (op == '+')
      return left -> evaluate() + right -> evaluate();
    else if (op == '-')
      return left -> evaluate() - right -> evaluate();
    else if (op == '*')
      return left -> evaluate() * right -> evaluate();
    else
      return left -> evaluate() / right -> evaluate();
  }
};

class TreeBuilder {
public:
  Node* buildTree(vector<string>& postfix) {
    stack<Node*> stk;
    int n=postfix.size();
    for (int i=0; i<n; i++){
      if (isdigit(postfix[i][0])){
        NumNode* cur = new NumNode(postfix[i]);
        stk.push(cur);
      }
      else{
        Node* right = stk.top();
        stk.pop();
        Node* left = stk.top();
        stk.pop();
        Node* cur  = new OpNode(postfix[i][0], left, right);
        stk.push(cur);
      }
    }
    return stk.top();
  }
};


/**
 * Your TreeBuilder object will be instantiated and called as such:
 * TreeBuilder* obj = new TreeBuilder();
 * Node* expTree = obj->buildTree(postfix);
 * int ans = expTree->evaluate();
 */