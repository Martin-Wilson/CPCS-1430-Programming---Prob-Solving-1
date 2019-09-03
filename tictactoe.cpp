//Martin Wilson
//tictactoe.cpp

#include <iostream>

using namespace std;

#include "tictactoe.h"

//constructor
Tictactoe::Tictactoe()
{
  board = new char*[SIZE];

  for(int i = 0; i < SIZE; i++)
    board[i] = new char[SIZE];

  for(int r = 0; r < SIZE; r++){
    for(int c = 0; c < SIZE; c++){
      board[r][c] = SPACE;
    }
  }
}

//copy constructor and overloaded assignment operator
Tictactoe& Tictactoe::operator=(const Tictactoe& rhs)
{
  if(this != &rhs){
    for(int i = 0; i < SIZE; i++)
      delete [] board[i];
  

  delete[] board;
  board = new char*[SIZE];

  for(int i = 0; i < SIZE; i++)
    board[i] = new char[SIZE];

  for(int r = 0; r < SIZE; r++){
    for(int c = 0; c < SIZE; c++){
      board[r][c] = rhs.board[r][c];
    }
   }
  }
  return *this;
}

//destructor
Tictactoe::~Tictactoe()
{
  for(int i = 0; i < SIZE; i++)
    delete [] board[i];

  delete [] board;
}

bool Tictactoe::isWinner(char &tie)
{
  if((board[0][0] == tie && board[0][1] == tie && board[0][2] == tie
     && board[0][0] != SPACE && board[0][1] != SPACE)||
      (board[1][0] == (tie && !SPACE) && board[1][1] == (tie && !SPACE)
       && board[1][2] == (tie && !SPACE)) ||
      (board[2][0] == (tie && !SPACE) && board[2][1] == (tie && !SPACE)
      && board[2][2] == (tie && !SPACE)) ||
      (board[0][0] == (tie && !SPACE) && board[1][0] == (tie && !SPACE)
       && board[2][0] == (tie && !SPACE)) ||
      (board[0][1] == (tie && !SPACE) && board[1][1] == (tie && !SPACE)
       && board[2][1] == (tie && !SPACE)) ||
      (board[0][2] == (tie && !SPACE) && board[1][2] == (tie && !SPACE)
       && board[2][2] == (tie && !SPACE )) ||
      (board[0][0] == (tie && !SPACE) && board[1][1] == (tie && !SPACE)
       && board[2][2] == (tie && !SPACE)) ||
      (board[2][0] == (tie && !SPACE) && board[1][1] == (tie && !SPACE)
      && board[0][2] == (tie && !SPACE))){
    return true;
  }else{
    tie = 'T';
    return false;
  }
        
}

bool Tictactoe::takeTurn(char piece, int row, int column)
{
  if(board[row][column] == SPACE){
    board[row][column] = piece;
    return true;

  } else{
    return false;
  }

}

void Tictactoe::displayBoard()
{

  cout << endl << endl <<  SPACE << SPACE << SPACE << SPACE << SPACE << SPACE
       << SPACE << SPACE << SPACE << SPACE
       <<"Columns" << endl
       << SPACE << SPACE << SPACE << SPACE << SPACE << SPACE << SPACE << SPACE;
  

    for(int c = 0; c < SIZE; c++){
      cout << SPACE << c << SPACE << SPACE;
    }
  
    for(int r = 0; r < SIZE; r++){
      if(r != 1){
        cout << endl << SPACE << SPACE << SPACE << SPACE
             << SPACE << r << SPACE << SPACE;
      }else {
        cout << endl << "Rows 1  ";  

      }
      
      for(int c = 0; c < SIZE; c++){
        cout << SPACE << board[r][c] << SPACE << LINE;
              
      }     
      
      cout << endl << SPACE << SPACE << SPACE << SPACE
           << SPACE << SPACE << SPACE << SPACE;
      
      for(int i = 0; i < 3; i++){
        cout << DOT << DOT << DOT << LINE;
      }
    }

}

void Tictactoe::clearBoard()
{
  for(int r = 0;r < SIZE; r++){
    for(int c = 0; c <SIZE; c++){
      board[r][c] = SPACE;
    }
  }
}
