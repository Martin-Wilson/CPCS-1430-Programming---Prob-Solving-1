//Martin Wilson

//stack.cpp



using namespace std;

#include"stack.h"

Stack::Stack(int size)
{

  if(size <= 3)
    size = 50;
  list = new int[size];
  top = -1;
  max = size;

  for(int i = 0; i < max; i++)
    list[i] = 0;
}

Stack::Stack(const Stack& s)
{
  top = s.top;
  max = s.max;
  list = new int[max];

  for(int i = 0; i < max; i++)
    list[i] = s.list[i];
   
}

Stack& Stack::operator=(const Stack& rhs)
{
  if(this != &rhs){
    delete [] list;
    max = rhs.max;
    top = rhs.top;
    list = new int[max];
    
    for(int i = 0; i < max; i++)
      list[i] = rhs.list[i];
  }
  return *this;
}

Stack::~Stack()
{
  delete [] list;
}

void Stack::push(int data)
{
  if(full())
    reSize();

  top++;
  list[top] = data;
  
}

int Stack::pop()
{
  if(isEmpty()){
    throw EmptyStack();
  }

  int lastIndex = top;
  top--;
  return list[lastIndex];
}

bool Stack::isEmpty() const
{
  if(top == -1)
    return true;
  else
    return false;
}

bool Stack::full() const
{
  int checker = max -1;
  
  if(top == checker)
    return true;
  else
    return false;
}

void Stack::reSize()
{
  int* temp;
  int newSize = max + max;
  temp = new int[newSize];

  for(int i = 0; i < max; i++)
    temp[i] = list[i];

  delete [] list;
  list = temp;
}

