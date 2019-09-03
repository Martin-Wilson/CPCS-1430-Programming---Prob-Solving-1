//Martin Wilson
//queue.cpp


using namespace std;

#include "queue.h"

Queue::Queue()
{

  front = nullptr;
  tail = nullptr;
  
}

Queue::Queue(const Queue& aQueue)
{  
  QNode* temp = aQueue.front;
  front = new QNode;
  front -> value = temp -> value;
  tail = front;
  temp = temp -> next;
  
  while(temp != nullptr){
    tail -> next = new QNode;
    tail = tail -> next;
    tail -> value = temp -> value;
    temp = temp -> next;
  }
}

Queue& Queue::operator=(const Queue& rhs)
{
  if(this != &rhs){
    while(front != nullptr){
      QNode* delptr = front;
      front = front -> next;
      delete delptr;
    }
    if(rhs.front == nullptr){
      front = nullptr;
      tail = nullptr;
    }else{
      QNode* temp = rhs.front;

      front = new QNode;
      front -> value = rhs.front -> value;
      temp = temp -> next;
      tail = front;

      while(temp != nullptr){
        tail -> next = new QNode;
        tail = tail -> next;
        tail -> value = temp -> value;
        temp = temp -> next;
      }
      tail -> next = nullptr;
    }
  }
  return *this;
}

Queue::~Queue()
{
  while(front != nullptr){
    QNode* delptr = front;
    front = front -> next;
    delete delptr;
  }
  tail = nullptr;
}

void Queue::enqueue(int data)
{
  QNode* temp = new QNode;
  temp -> value = data;
  
  
  if(front == nullptr){
      front = temp;
      tail = temp;
  } else{
    tail -> next = temp;
    tail = temp;
  }
  tail -> next = nullptr;
  
}

int Queue::dequeue()
{
  if(isEmpty()){
    throw EmptyQueue();
  }

  if(front == tail)
    tail = nullptr;
  
  QNode* delptr;
  int data = front -> value;
  
  delptr = front;
  front = front -> next;
  delete delptr;

  return data;
}

bool Queue::isEmpty() const
{
  if(front == nullptr && tail == nullptr)
    return true;
  else
    return false;
}

