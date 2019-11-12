//Sean Wright
//stack.h
//This is the header file for the stack class
#ifndef STACK_H
#define STACK_H

class Stack
{
 public:
  class EmptyStack{};
  // exception class thrown when attempt made to pop from empty stack

  explicit Stack(int size = 50);
  // constructor

  Stack(const Stack& s);
  // copy constructor

  Stack& operator=(const Stack& rhs);
  // overloaded assignment operator

  ~Stack();
  // destructor

  void push(int data);
  // adds data to stack

  int pop();
  // removes and returns data from stack
  // can throw EmptyStack exception

  bool isEmpty() const;
  // returns status of stack

  
  
 private:
  int* list; // stack
  int max;    // size of stack
  int top;    // top of stack

  bool full() const;
  // returns status of stack

  void resize();
  // allocates more stack memory
};

#endif