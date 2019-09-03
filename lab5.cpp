// Martin Wilson
// lab5.cpp

#include <iostream>
#include <fstream>

using namespace std;

struct Node
{
  int data;
  Node* next;
};

const string FILENAME = "/home/fac/sreeder/class/cs1430/lab5.dat";

void insertInOrder(Node*& h, int d);
// inserts d into h in numerical order
// post: h may be changed

void printList(Node* h);
// prints all data on h to the screen in a column

void delList(Node*& h);
// post: each node of h deleted

int main()
{
  Node* head = nullptr;
  ifstream inFile;
  int num;

  inFile.open(FILENAME);
  if (inFile.fail()){
	cout << "file problem...exiting program...press enter...";
	cin.get();
  }

  while (inFile >> num)
	insertInOrder(head, num);

  inFile.close();

  cout << endl;
  printList(head);

  cout << endl << endl;

  delList(head);

  return 0;
}

void insertInOrder(Node*& h, int d)
{
  Node* temp = new Node;

  temp -> data = d;
  Node* ptr;

  if(h == nullptr || h -> data > temp -> data){
    temp -> next = h;
    h = temp;
  }else {
    ptr = h;

    while(ptr -> next != nullptr && ptr -> next -> data < temp -> data)
      ptr = ptr -> next;

    temp -> next = ptr -> next;
    ptr -> next = temp;
  }
}

void printList(Node* h)
{
  Node* temp = h;

  while(temp != nullptr){
    cout << temp -> data << endl;
    temp = temp -> next;

  }
}

void delList(Node*& h)
{
  Node* delptr;

  while(h != nullptr){
    delptr = h;
    h = h -> next;
    delete delptr;
  }

}
