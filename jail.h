#ifndef JAIL_H
#define JAIL_H

// jail will check if a player if on the jail square on the board 
// if so, the plaayer will be prompted to pay, roll a sum of 6, or use a jail card
// if not on the jail square return

#include <iostream>
#include <stdlib.h>
#include <math.h>
#include "dice.h"


int jailplayerchoice;
int jailwaitcounter;
int dicei;
int playerposition;
int playermoneybalance;
std::vector<int> updatedResults;

 
std::vector<int> jaill(int waitjailCounter, int initialPosition, int initialBalance, int jailCardBalance){

// set input parameters of function to variables in function // 
  playerposition = initialPosition;
  playermoneybalance = initialBalance;
  jailwaitcounter = waitjailCounter;
  outofjailcardbalance = jailCardBalance;
  

if (playerposition == 31) {
  if(jailwaitcounter == 3) {
    cout << "You have been in jail for 3 turns. You will now be moved to just visiting and your turn will end." << "\n";
    playerposition = 11;
    //end the turn

  cout << "You are on academic probation. You can: 1. Pay $50 2. Try to roll a 6 total. Use a get out of jail free card." << "\n" << "Enter the corresponding number 1,2 or 3 associated with your choice." << "\n";
  cin >> jailplayerchoice;

  if (jailplayerchoice == 1) {
    if (playermoneybalance >= 50) {
      playermoneybalance -= 50; //Controls player paying their way out
      playerposition = 11;
      //end turn
    if (playermoneybalance < 50) {
      cout << "You cannot afford bail. Please select another option." << "\n";
       //recall function
    }
  }

  if (jailplayerchoice == 2) {
    //call dice
    dicei = diceroll();  // returns sum of two die
    if (dicei == 6 ) {
      cout << "you're free\n";
      playerposition = 11; //Controls player trying to roll dice
     // end the turn
    }
    if (dicei != 6) {
    jailwaitcounter += 1;
    //End the turn
    }
  }

  if (jailplayerchoice == 3) {
    if (outofjailcardbalance >= 1) {
      outofjailcardbalance -= 1;
      playerposition == 11;
      }
    else
      cout << "You do not have any get out of jail free cards. Stop trying to finess the program." << "\n"; //Controls using get out of jail card
    //call back to start of jail function
  }
}
}
}
// return update values
waitjailCounter = jailwaitcounter; 
initialPosition = playerposition;
initialBalance = playermoneybalance;
jailCardBalance = outofjailcardbalance;
updatedResults = {waitjailCounter, initialPosition, initialBalance,jailCardBalance};
return updatedResults;
}

#endif