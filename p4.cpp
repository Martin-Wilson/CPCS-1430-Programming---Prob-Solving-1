//Martin Wilson
//lab4.cpp

#include <iostream>
#include "stack.h"
#include "queue.h"

using namespace std;

void testStack();
//IN: Takes in nothing
//OUT: Tests the stack class and updates the user on the progess with messages
//MODIFY: Does not modify the stack in any way. It will use all public methods
//in the stack class in order to properly test it.

void testQueue();
//IN: Takes in nothing
//OUT: Tests the queue class and updates the user on the progress with messages
//MODIFY: Does not modify the queue in any way. It will use all public methods
//in the queue class in order to properly test it.

void clearScreen();
//IN: Takes in nothing
//OUT: Prints empty lines in order to clear the screen the number of empty
//lines is keep in the constant SCREEN
//MODIFY: Does not modify anything

int const SCREEN = 40;

int main()
{
  cout << endl << endl << "Welcome to the stack and queue tester." << endl
       << "This program will test all public functions of my stack and queue"
       << "class." << endl << "Press enter to test the stack class. ";
  cin.get();
  testStack();
  clearScreen();
  cout << endl << endl << "Press enter to test the queue class. ";
  cin.get();
  testQueue();
  
  return 0;
}


void testStack()
{
  int val;
  int numOfValues;
  Stack s4(3);

  cout << endl << endl << "Now testing the stack class."
       << endl << "Constructing a stack with default size, size 3, " << endl
       << "and one with a user determined size." << endl
       << "Input an integer greater than 3. ";
  cin >> val;

  Stack s1;
  Stack s2(val);

  cout << endl << endl << "How many values would you like to push into "
       << "stack ";
  cin >> numOfValues;

  for(int i = 0; i < numOfValues; i++){
    cout << endl << i + 1 << ". Now pushing " << i + 10 << " into the stack.";
    s1.push(i+10);
  }
  
  cout << endl << endl << "Now testing copy constructor.";

  Stack s3(s1);

  cout << endl << endl << "Now popping all values from orginal stack" << endl;
  while(!s1.isEmpty())
    cout << s1.pop() << ' ';

  cout << endl << "Now popping all values from copied stack" << endl;
  while(!s3.isEmpty())
    cout << s3.pop() << ' ';

  cout << endl << endl << "Now testing resizing function." << endl
       << "Pushing 5 values onto stack(s4) of size 3.";

  for(int i = 0; i < 5; i++){
    cout << endl << "Now pushing " << i+3 << " in to the stack.";
    s4.push(i+3);
  }

  cout << endl << endl << "Now testing assignment operator." << endl
       << "Copying s4 into the first stack.";
  s1 = s4;

  cout << endl << "Now popping all of s4." << endl;
  while(!s4.isEmpty())
    cout << s4.pop() << ' ';

  cout << endl << "Now popping all of first stack." << endl;
  while(!s1.isEmpty())
    cout << s1.pop() << ' ';

  cout << endl << endl << "Attempting to catch an empty stack exception.";
  try{
    cout << endl << s1.pop();
  }
  catch (Stack::EmptyStack){
    cout << endl << "ERROR: Cannot pop from empty stack.";
  }
  
}


void testQueue()
{
  int numOfValues;
  
  cout << endl << endl << "Now testing the queue class." << endl
       << "Creating two new queues.";
  Queue q1;
  Queue q3;

  cout << endl << endl
       << "How many values would you like to add to the first queue: ";
  cin >> numOfValues;
  cout << endl;
  
  for(int i = 0; i < numOfValues; i++){
    cout << i + 1 << ". Enqueuing " << i+7 << endl;
    q1.enqueue(i+7);
  }

  cout << endl << "Copying the first queue into a new instance.";
  Queue q2(q1);

  cout << endl << "Dequeuing and printing from the first queue." << endl;
  while(!q1.isEmpty()){
    cout << q1.dequeue() << ' ';
  }

  cout << endl << "Copying the second queue into the third queue using the"
       << endl << " overloaded assignment operator. ";
  q3 = q2;

  cout << endl << endl
       << "Dequeuing and printing from the second queue." << endl;
  while(!q2.isEmpty())
    cout << q2.dequeue() << ' ';

  cout << endl << "Dequeuing and printing from the third queue. " << endl;
  while(!q3.isEmpty())
    cout << q3.dequeue() << ' ';

  cout << endl << endl << "Attempting to catch an EmptyQueue exception"
       << endl;

  try{
    cout << q3.dequeue();
  }
  catch(Queue::EmptyQueue){
    cout << "ERROR: Cannot remove from empty queue" << endl << endl;
  }
}

void clearScreen()
{
  for(int i = 0; i < SCREEN; i++)
    cout << endl;
}
