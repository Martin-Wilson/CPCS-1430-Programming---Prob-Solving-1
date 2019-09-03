//Martin Wilson
//p9.cpp

#include <fstream>
#include <iostream>

using namespace std;

void insertSort(string arr[],int numElements);

int search(string arr[],int numElements,string target);

void printList(string arr[], int numElements);


const char YES = 'y';
const string FNAME = "/home/fac/sreeder/class/cs1430/lab9.dat";
const int SIZE = 50;

int main()
{
  char ans = 'y';
  string arr[SIZE];
  string searchFor;
  int numE = 0;
  int answer;

  ifstream infile;
  infile.open(FNAME.c_str());

  if(infile.fail()){
    cout << "File error press enter to exit program..";
    cin.get();
    return 0;
  }

  while(infile >> arr[numE]){
    numE++;
  }

  infile.close();

  cout << endl << endl << "Printing the array." << endl << endl; 

  printList(arr, numE);

  insertSort(arr, numE);

  cout << endl << endl << "Printing the sorted list." << endl << endl;

  printList(arr, numE);

  while(ans == YES){
    cout << endl << endl << "What string would you like to search for? ";
    cin >> searchFor;
    answer = search(arr, numE, searchFor);

    if(answer < 0){
      cout << endl << "That string is not in the list. ";
    }else{
      cout << endl << "Yay! That string is in the list. " << endl
           << arr[answer]
           << " is at index " << answer; 
    }

    cout << endl << "Would you like to search for another string(y/n): ";
    cin >> ans;
  }

  return 0;
}

void insertSort(string arr[], int numElements)
{
  string val;
  int count;
  
  for(int i = 1; i < numElements; i++){
    val = arr[i];
    count = i -1;

    while(count >= 0 && arr[count] > val){
      arr[count+1] = arr[count];
      count = count - 1;
    }
    arr[count +1] = val;
  }
}

int search(string arr[], int numElements,string target)
{
  int first = 0;
  int last = numElements;
  int mid = (first + last)/2;

  while(first <= last && arr[mid] != target){
    if(arr[mid] < target)
      first = mid +1;
    else
      last = mid -1;

    mid = (first + last)/2;
  }

  if(arr[mid] == target){
    while(mid >= 1 && arr[mid-1] == target)
      mid--;
    return mid;
  } else {
    return -1;
  }
  
}

void printList(string arr[], int numElements)
{
  for(int i = 0; i < numElements; i++)
    cout << endl << i << ' ' << arr[i];
}


