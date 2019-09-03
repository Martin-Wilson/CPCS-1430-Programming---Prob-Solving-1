//Martin Wilson
//lab6.cpp

#include <iostream>
#include <fstream>

using namespace std;

struct Node
{
  int data;
  Node* next;
};

void insertInList(Node*& head, int value);

void cleanList(Node* head);

void delList(Node*& head);

void printList(Node* head);

const string FNAME = "/home/fac/sreeder/class/cs1430/lab6.dat";

int main()
{
  Node* head = nullptr;
  ifstream infile;
  int num;
  
  infile.open(FNAME.c_str());
  if(infile.fail()){
    cout << endl << "File does not exist or file error press enter";
    cin.get();
    return 0;
  }

  while(infile >> num)
    insertInList(head, num);

  infile.close();

  cout << endl;
  printList(head);
  cout << endl << endl;

  cleanList(head);

  cout << endl;
  printList(head);
  cout << endl << endl;

  delList(head);
  
  return 0;
}

void insertInList(Node*& head, int value)
{

  Node* temp = new Node;

  temp -> data = value;
  Node* ptr;

  if(head == nullptr || head -> data >= temp -> data){
    temp -> next = head;
    head = temp;
  } else {
    ptr = head;
    //check the >= if it is needed
    while(ptr -> next != nullptr && ptr -> next -> data <= temp -> data)
      ptr = ptr -> next;

    temp -> next = ptr -> next;
    ptr -> next = temp;
  } 

}

void cleanList(Node* head)
{
  Node* delptr;
  Node* walker = head;
  
  while(walker != nullptr && walker -> next != nullptr){
    delptr = walker -> next;

    if(delptr -> data == walker -> data){
      walker -> next = delptr -> next;
      delete delptr;
    } else{
      walker = walker -> next;
    }
  }
}

void delList(Node*& head)
{
  Node* delptr;

  while(head != nullptr){
    delptr = head;
    head = head -> next;
    delete delptr;
  }
}

void printList(Node* head)
{
  Node* temp = head;

  while(temp != nullptr){
    cout << temp -> data << ' ';
    temp = temp -> next;
  }

}
