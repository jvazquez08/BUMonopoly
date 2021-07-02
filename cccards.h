#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <random>

// cccards is called after the player makes his next move (calls playposition.h function printPosition())
// cccards checks if we are on a chance or community chest card
// if so, update the player monetary balance and position
// if its not a cc or chance card return original input

int cccardselect;
int chancecardselect;
int playerspace; 
int outofjailcardbalance;
std::vector<int> updatinginformation;

std::vector<int> cccards(int initialPos, int initialBal) {
  playerspace = initialPos;
  playerbalance = initialBal;
  if (playerspace == 8 || playerspace == 23 || playerspace == 37) {
   srand((unsigned int)time(NULL));
    {
     chancecardselect = rand()%16;
     chancecardselect =+ 1;
     if (chancecardselect == 1) {
      cout << "Advance to Stuvi 2." << "\n";
      playerspace = 40;

      
     } 

     if (chancecardselect == 2) {
      cout << "Advance to GO." << "\n";
      playerspace = 1;
      
     } 

     if (chancecardselect == 3) {
      cout << "Advance to FitRec. If you pass GO collect $200" << "\n";
      if (playerspace >= 26) {
        playerbalance += 200;
        cout << "new player balance is $" << playerbalance << "\n";
      }
      playerspace = 25;
      
     } 

     if (chancecardselect == 4) {
      cout << "Advance to the School of Theology" << "\n";
      if (playerspace >= 13) {
        playerbalance += 200;
        cout << "new player balance is $" << playerbalance << "\n";
      }
      playerspace = 12;
      
     } 

     if (chancecardselect == 5) {
        cout << "Advance to the nearest T stop. If owned, you must pay twice the fee associated with the stop." << "\n";
      // finish programming
     } 

     if (chancecardselect == 6) {
      cout << "Advance to the nearest T stop. If owned, you must pay twice the fee associated with the stop." << "\n";
      // finish programming
     } 

     if (chancecardselect == 7) {
      cout << "Advance to the nearest utility. If owned, pay 10x the value of a dice roll." << "\n";
      //finish programming
     } 

     if (chancecardselect == 8) {
      cout << "BU financial aid credits you $50" << "\n";
      playerspace += 50;
      
     } 

     if (chancecardselect == 9) {
      cout << "Congrats! You have been given a get off academic probation free card!" << "\n";
      outofjailcardbalance += 1;
     } 

     if (chancecardselect == 10) {
      cout << "Move back 3 spaces." << "\n";
      playerspace -= 3;
     
     } 

     if (chancecardselect == 11) {
      cout << "You have been placed on academic probation. Do not pass go. Go directly to the office." << "\n";
      playerspace = 41;

     } 

     if (chancecardselect == 12) {
      cout << "You need to make general repairs to all properties and all houses. Pay $25 for each house and $100 for each hotel." << "\n";
      //finish programming
     } 

     if (chancecardselect == 13) {
      cout << "BUPD caught you speeding on Commonwealth Avenue. Pay $15." << "\n";
      playerbalance -= 15;
      cout << "new player balance is $" << playerbalance << "\n";
     } 

     if (chancecardselect == 14) {
      cout << "Move to Blandford Street T stop. Collect $200 if you pass GO." << "\n";
      if (playerspace <= 7) {
        playerbalance += 200;
        cout << "new player balance is $" << playerbalance << "\n";
      }
      playerspace = 6;
     } 

     if (chancecardselect == 15) {
      cout << "You are the current chairman of C++. Pay each player $50." << "\n";
      //finish programming
     } 

     if (chancecardselect == 16) {
      cout << "Your side hustle tutoring freshmen pays off. Collect $150." << "\n";
      playerbalance += 150;
      cout << "new player balance is $" << playerbalance << "\n";
     }
   }
   // updatinginformation = {playerspace, playerbalance};
   // return updatinginformation;
 }

   if (playerspace == 3 || playerspace == 18 || playerspace == 34) {
    srand((unsigned int)time(NULL));
    {
     cccardselect = rand()%16;
     cccardselect =+ 1;
     if (cccardselect == 1) {
      cout << "Advance to GO. Collect $200" << "\n";
      playerbalance += 200;
      playerspace = 1;
      cout << "Your new balance is $" << playerbalance << "\n";
     } 

     if (cccardselect == 2) {
      cout << "BU Financial Aid makes an error in your favor. Collect $200." << "\n";
      playerbalance += 200;
      cout << "new player balance is $" << playerbalance << "\n";
     } 

     if (cccardselect == 3) {
      cout << "You go all out at Cane's. You owe them $50." << "\n";
      playerbalance -= 50;
      cout << "new player balance is $" << playerbalance << "\n";
     } 

     if (cccardselect == 4) {
      cout << "You make $50 by selling old textbooks." << "\n";
      playerbalance += 50;
      cout << "new player balance is $" << playerbalance << "\n";
     } 

     if (cccardselect == 5) {
      cout << "Congrats! You have been given a get off academic probation free card!" << "\n";
      outofjailcardbalance += 1;
     } 

     if (cccardselect == 6) {
      cout << "You have been placed on academic probation. Do not pass go. Go directly to the office." << "\n";
      playerspace = 41;
      ;
     } 

     if (cccardselect == 7) {
      cout << "Your convienence point fund matures. Collect $100." << "\n";
      playerbalance += 100;
      cout << "new player balance is $" << playerbalance << "\n";
     } 

     if (cccardselect == 8) {
      cout << "Partial tuition refund. Collect $20." << "\n";
      playerbalance += 20;
      cout << "new player balance is $" << playerbalance << "\n";
     } 

     if (cccardselect == 9) {
      cout << "The other players owe you money for late night ramen. Collect $10 from each player." << "\n";
      //Take $10 from each player
     } 

     if (cccardselect == 10) {
      cout << "You recieve another $100 from financial aid." << "\n";
      playerbalance += 100;
      cout << "new player balance is $" << playerbalance << "\n";
     } 

     if (cccardselect == 11) {
      cout << "Pay parking fee of $100. The bike rack is not for monster trucks." << "\n";
      playerbalance -= 100;
      cout << "new player balance is $" << playerbalance << "\n";
     } 

     if (cccardselect == 12) {
      cout << "Pay tuition fee of $50." << "\n";
      playerbalance -= 50;
      cout << "new player balance is $" << playerbalance << "\n";
     } 

     if (cccardselect == 13) {
      cout << "Recieve $25 for no reason." << "\n";
      playerbalance += 25;
      cout << "new player balance is $" << playerbalance << "\n";
     } 

     if (cccardselect == 14) {
      cout << "Construction of Commonwealth Avenue. Pay $40 per house and $115 per hotel." << "\n";
      //finish programming.
     } 

     if (cccardselect == 15) {
      cout << "You won second prize in a Boston Terrier dog show. Collect $10" << "\n";
      playerbalance += 10;
      cout << "new player balance is $" << playerbalance << "\n";
     } 

     if (cccardselect == 16) {
      cout << "You recieve a $100 scholarship from Hasbro Games for your Monopoly clone." << "\n";
      playerbalance += 100;
      cout << "new player balance is $" << playerbalance << "\n";
     }
   }

 }
 updatinginformation = {playerspace, playerbalance};
   return updatinginformation;
}
