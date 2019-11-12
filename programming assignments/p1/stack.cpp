 //Sean Wright
// stack.cpp
//This is the main stack class file
#include "stack.h"
#include <iostream>
using namespace std;

Stack::Stack(int size)
{
  if (size < 3)   // a minimum size of 3 ensures the resize works
    size = 50;
  max = size;
  list = new int[max];
  top = 0;       // array index for next storage
}

Stack::Stack(const Stack& s)
{
  max = s.max;          // copy the value from the already existing Stack
  list = new int[max];  // allocate new memory for this new Stack
  top = s.top;          // copy the value from the already existing Stack

  for (int i = 0; i < top; i++)  // copy the values from the already existing Stack
    list[i] = s.list[i];
}

Stack& Stack::operator=(const Stack& rhs)
{
  if (this != &rhs){        // ensure you are working with two different objects
    delete [] list;         // remove the dynamic memory from the LHS object
    max = rhs.max;          // overwrite the value in the LHS object with the value in the RHS object
    list = new int[max];    // allocate new dynamic memory for the LHS object
    top = rhs.top;          // overwrite the value in the LHS object with the value in the RHS object
    for (int i = 0; i < top; i++) // copy the values from the RHS object into the new memory
      list[i] = rhs.list[i];
  }
  return *this;             // return the address of the LHS object (stored in "this")
}

Stack::~Stack()
{
  delete [] list;           // deallocate the memory that was allocated
}

void Stack::push(int data)
{
  //Tests to make sure that data is a prime, if so then it adds it to the stack.
  //I don't count 1 as being a prime number.
  bool isPrime = true;
  if(data < 2)
	  isPrime = false;
  else	  
  {
	  for(int i = 2; i <= data / 2; ++i)
	  {
		  if(data % i == 0)
		  {
			  isPrime = false;
			  break;
		  }
	  }
  }
  if (isPrime)
  { 
	  if (full())       // see if there is room on the Stack
	     resize();       // if no room on the Stack, make the Stack larger
      list[top] = data; // add the new item to the top of the stack
	  top++;  // move the index
  }
}

int Stack::pop()
{
  if (isEmpty()) {        // an empty Stack has nothing to pop
    cout<<"Stack is empty, nothing can be popped."<<endl;
	throw EmptyStack();  // this is the class created in the .h file to indicate an error
  }
  else {
    top--;               // decrement top to find the value
    return list[top];    // return the top value
  }
}

bool Stack::isEmpty() const
{
  return top == 0;  // check to see if anything is on the Stack
}

bool Stack::full() const
{
  return top == max;  // see if the Stack is full and needs to be resized
}

void Stack::resize()
{
  int* tmp;                                 // temporary pointer for a new array
  int larger = static_cast<int>(max * 1.5); // make the new array 1.5 times larger than the old one
  tmp = new int[larger];                    // allocate memory for the larger array
  for (int i = 0; i < top; i++)             // copy the values from the old array to the new one
    tmp[i] = list[i];

  delete [] list;                          // deallocate the old array
  list = tmp;                              // assign the old array name to the new array
  max = larger;                            // update the size of the array
}
