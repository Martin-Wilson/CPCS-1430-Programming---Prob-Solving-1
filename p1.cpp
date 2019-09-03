#include<iostream>

using namespace std;

#include "player.h"
#include "board.h"

const char YES = 'y';
const int PSIZE = 7;
const int MIN = 2;
const int MAX = 6;

int main()
{
  Board board;
  Player players[PSIZE];

  string name;
  char ans = 'y';
  int playerNum = 0;
  int chuteOrLadder = 0;
  int loc;

  bool winnerFound = false;
  int playerTracker = 1;

  int winner;
  
  while(ans == YES){

    name  = "";
    playerNum = 0;
    chuteOrLadder = 0;
    loc = 0;
    winnerFound = false;
    playerTracker = 1;
    
    cout << endl << "Welcome to chutes and ladders" << endl
         << "In this game 2 to 6 play the game untill someone"
         << " lands on space 100"
         << '.' << endl << "Watch out for chutes and good luck!!!";
    
    while(playerNum < MIN || playerNum > MAX){
      cout << endl << "How many players would you like to play with(2-6)";
      cin >> playerNum;
    }
    
    for(int i = 1; i <= playerNum; i++){
      cout << endl << "Input player " << i << "'s name: ";
      cin >> name;
      players[i].setName(name);
    }

    cin.ignore();
    
    while(!winnerFound){

      chuteOrLadder = 0;
      loc = players[playerTracker].getLocation();
      board.takeTurn(players[playerTracker].getName(), loc,
                     chuteOrLadder);
      players[playerTracker].checkChuteLadder(chuteOrLadder);
      players[playerTracker].setLocation(loc);

      winnerFound = board.winner(loc);
      winner = playerTracker;
      
      playerTracker++;
      if(playerTracker > playerNum)
        playerTracker = 1;
    }

    cout << endl << "CONGRATS " << players[winner].getName()
         << "!!!!" << endl << "You Wonnnn!!!!" << endl << "You went up "
         << players[winner].getLadders() << " ladders." << endl
         << "You went down " << players[winner].getChutes()
         << " chutes." << endl;

    for(int i = 1; i <= playerNum; i++){
      players[i].reset();
    }
    
    
    cout << endl << "Would you like to play again(Y/N): ";
    cin >> ans;
  }

  cout << endl << "Thank you for playing!!!" << endl;
  
  return 0;
}
