//Martin Wilson
//p5.cpp
//This program is a card game very similar to war. Two players will
//play the game and will play until one player runs out of cards

#include <iostream>
#include <cstdlib>
#include "stack.h"
#include "queue.h"

using namespace std;

void welcome();
//IN: Takes nothing in
//OUT: Prints a welcome message to the screen
//MODIFY: Does not modify anything

void goodbye();
//IN: Takes nothing in
//OUT: Prints a goodbye message to the screen
//MODIFY: Does not modify anything

Stack shuffle();
//IN: Does not takes in anything
//OUT: Returns a shuffled stack.
//MODIFY: Does not modify anything

void takeCard(Queue& q, Stack& s, Stack& discard);
//IN: Takes in a players queue and the deal stack
//OUT: updates the deal stack and the player queue by removing on from the
//deal stack and adding that value to the queue
//MODIFY: Might reshuffle the deal stack if it is empty

const int DECKSIZE = 52;
const int MIN = 0;
const int START = 14;
const char YES = 'y';

int main()
{
  Stack deal;
  Stack discard;

  Queue p1;
  Queue p2;

  unsigned seed = time(0);
  srand(seed);

  string player1;
  string player2;
  char ans = 'y';
  bool player1Turn = true;
  bool done;
  int cardToBeat;
  int cardPlayed;

  welcome();

  while(tolower(ans) == YES){

    done = false;
    
    cout << endl << endl << "Input player 1's name: ";
    cin >> player1;
    
    cout << endl << "Input player 2's name: ";
    cin >> player2;
    cin.ignore();

    deal = shuffle();
    
    for(int i = 0; i < START; i++){
      if(player1Turn){
        p1.enqueue(deal.pop());
        player1Turn = false;
      } else {
        p2.enqueue(deal.pop());
        player1Turn = true;
      }
    }

    discard.push(deal.pop());

    player1Turn = true;
    
    while(!done){
      cardToBeat = discard.pop();
      discard.push(cardToBeat);

      if(player1Turn){
        cout << endl << endl << "It's " << player1 << "'s turn!!"
             << endl << "The card to beat is " << cardToBeat << '.'
             << endl << "Press enter to draw a card. ";
        cin.get();

        cardPlayed = p1.dequeue();

        cout << endl << "You drew " << cardPlayed << '.';

        if(cardPlayed > cardToBeat){

          cout << " Nice you won. You don't need to take a card."
               << endl << endl;
          discard.push(cardPlayed);

        } else if(cardPlayed == cardToBeat){

          cout << "You tied! Press enter to get a card. " << endl; 
          cin.get();
          takeCard(p1, deal, discard);
          discard.push(cardPlayed);

        } else {

          cout << " You lost the round."
               << " Press enter to take two cards. " << endl;
          cin.get();
          takeCard(p1, deal, discard);
          takeCard(p1, deal, discard);
          discard.push(cardPlayed);

        }

        if(p1.isEmpty())
          done = true;

        player1Turn = false;
        
      } else {
         
        cout << endl << endl << "It's " << player2 << "'s turn!!"
             << endl << "The card to beat is " << cardToBeat << '.'
             << endl << "Press enter to draw a card. ";
        cin.get();

        cardPlayed = p2.dequeue();

        cout << endl << "You drew " << cardPlayed << '.';

        if(cardPlayed > cardToBeat){

          cout << "Nice you won. You don't need to take a card."
               << endl << endl;
          discard.push(cardPlayed);
          
        } else if(cardPlayed == cardToBeat){

          cout << "You tied. Press enter to take a card." << endl;
          cin.get();
          takeCard(p2, deal, discard);
          discard.push(cardPlayed);

        } else {

          cout << "You lost the round."
               << " Press enter to take two cards. " << endl;
          cin.get();
          takeCard(p2, deal, discard);
          takeCard(p2, deal, discard);
          discard.push(cardPlayed);

        }

        if(p2.isEmpty())
          done = true;

        player1Turn = true;

      }
    }

    if(p1.isEmpty()){
      cout << endl << "Congrats " << player1 << " You won!!!";
    } else {
      cout << endl << "Congrats " << player2 << " You won!!!";
    }
    

    cout << endl << endl << "Would you like to play again(y/n): ";
    cin >> ans;
    
  }

  goodbye();
  
  return 0;
}

void welcome()
{
  cout << endl << "Welcome to Silly Little Games Super Special Card Game."
       << endl << "In this game there are 4 sets of 1-13 cards in the deck."
       << endl << "The goal of the game is to get rid of all your cards, "
       << endl << "by doing so you will win the game." << endl
       << "At the beinging of the game each player will be dealt 7 cards."
       << endl << "There will also be one card added to the discard pile so"
       << endl << "that we can compare the player cards." << endl
       << "A turn consists of one player drawing the top card out of their"
       << endl << "deck and comparing it to the card we originally put into"
       << endl << "the discard pile. This continues until one player wins."
       << endl << "Goodluck and have fun!!";
}

void goodbye()
{
  cout << endl << "Thank you for playing!!" << endl;
}


Stack shuffle()
{
  Stack s(DECKSIZE);
  int arr[DECKSIZE];
  int counter = 0;
  int temp;
  int swapValue;

  for(int i = 1; i <= 13; i++){
    for(int j = 0; j < 4; j++){
      s.push(i);
    }
  }

   while(!s.isEmpty()){
    temp = s.pop();
    arr[counter] = temp;
    counter++;
  }
  
   for(int i = 0; i < DECKSIZE; i++){
    temp = (rand() % (DECKSIZE));
    swapValue = arr[i];
    arr[i] = arr[temp];
    arr[temp] = swapValue;
  }

  for(int i = 0; i < 52; i++){
    s.push(arr[i]);
  }
  
  return s;
}

void takeCard(Queue& q, Stack& s, Stack& discard)
{
  if(s.isEmpty()){
    s = shuffle();
    while(!discard.isEmpty())
      discard.pop();
  }
  q.enqueue(s.pop()); 
}
