//Martin Wilson
//stack.h

#ifndef STACK_H
#define STACK_H

//class EmptyStack{};
//exception thrown if you try to pop from an empty stack

class Stack
{
  
 public:

  class EmptyStack{};
  //exception thrown if you try to pop from an empty stack
  
  Stack(int size = 50);
  //explicit constructor, call in order to create a stack object

  Stack(const Stack& s);
  //copy constructor

  Stack& operator=(const Stack& rhs);
  //overloaded assignment operator

  ~Stack();
  //Deconstructor, deallocates all the memory used by the stack 

  void push(int data);
  //IN: Takes in a value of type int
  //OUT: Does not return anything
  //MODIFY: Pushes the value taken in to the top of the stack

  int pop();
  //IN: Does not take anything in
  //OUT: Returns the value at the top of the stack
  //MODIFY: Removes one item from the list

  bool isEmpty() const;
  //IN: Does not take anything in
  //OUT: Return true if the stack is empty and false if it is not
  //MODIFY: does not modify the stack

 private:

  int* list;
  int max;
  int top; 
  
  bool full() const;
  //IN: Does not take anything in
  //OUT: Returns true if the stack is full and false if it is not
  //MODIFY: Does not modify the stack
  void reSize();
  //IN: Does not take anthing in
  //OUT: Does not return anything
  //MODIFY: Resizes the stack to a larger size

};

#endif //STACK_H
