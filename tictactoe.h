//Martin Wilson
//tictactoe.h

#include <iostream>

#ifndef BOARD_H
#define BOARD_H

class Tictactoe
{
  
 public:
   
   //constructor
  Tictactoe();

  Tictactoe(const Tictactoe &obj);
  
  Tictactoe& operator =(const Tictactoe& rhs);

  ~Tictactoe();

  //takes in the char that the player played and checks to see if there is a winner
  //return true if their is a winner false if no winner and 't' if a tie
  //or space if no tie
  bool isWinner(char &tie);

  //returns true if move works and places the peices there. returns false if the space is not avaible
  bool takeTurn(char piece, int row, int column);

  //prints out the board to the screen
  void displayBoard();

  //clears the board
  void clearBoard();
  
 private:

  //2d array of char
  char** board;
  int total;
  const char SPACE = ' ';
  const char LINE = '|';
  const char DOT = '_';
  const int SIZE = 3;
     

};
#endif //TICTACTOE_H
    
