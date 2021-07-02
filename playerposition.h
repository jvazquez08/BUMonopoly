// Copyright 2021 Christopher Lemus lemusc@bu.edu
// Copyright 2021 Jovany Vazquez jvazquez@bu.edu
// Copyright 2021 Zachary Capone zcapone@bu.edu
#ifndef PLAYERPOSITION_H
#define PLAYERPOSITION_H

// this fucnction will roll dice when the player presses the key R on the monopoly board
// the next position will be calculated based on the initial position and dice roll total

#include <iostream>
#include <stdlib.h>
#include <math.h>
#include "dice.h"

using std::cout;
using std::cin;
using std::__cxx11::stoi;
int playerpos;  // player board position
int dicenum;  // number rolled by dice
int playerbalance;  // player monetary balance
// if player owns property --> 1 else --> 0 //
int own2 = 0;
int own4 = 0;
int own6 = 0;
int own7 = 0;
int own9 = 0;
int own10 = 0;
int own12 = 0;
int own13 = 0;
int own14 = 0;
int own15 = 0;
int own16 = 0;
int own17 = 0;
int own19 = 0;
int own20 = 0;
int own22 = 0;
int own24 = 0;
int own25 = 0;
int own26 = 0;
int own27 = 0;
int own28 = 0;
int own29 = 0;
int own30 = 0;
int own32 = 0;
int own33 = 0;
int own35 = 0;
int own36 = 0;
int own38 = 0;
int own40 = 0;

std::vector<int> printPosition(int initialPosition, int initialBalance) {
// these tokens are to differentiate between players and keep track of each ones totals
  std::vector<int> updatedinfo;
// set funtion input = to funcation variables //
  playerpos = initialPosition;
  playerbalance = initialBalance;


  dicenum = diceroll();  // roll dice for new player turn // 
  playerpos += dicenum;  // add position to initial position from function

  cout << "player position " << playerpos << "\n";
  if (playerpos > 40) { //In the case the player loops the board.
    playerpos -= 40;
    playerbalance += 200;
    cout << "You have recieved $200 for passing 'GO'." << "\n";
    cout << "Your balance is now $" << playerbalance << "\n";
  }

  if (playerpos == 1) {
    cout << "You are currently on 'GO'." << "\n";
  }

  if (playerpos == 2) {
    cout << "You are currently at the Hojo." << "\n";
    if(own2 == 1) {
      cout << "This property is owned and you owe $2 rent." << "\n";
      playerbalance -= 2;
      cout << "Your balance is now $" << playerbalance << "\n";
      if (playerbalance < 0) {
        cout << "You are bankrupt and are no longer in the game." << "\n";
      }
    }
    if (own2 == 0) {
      cout << "This property is unowned. Would you like to buy it? Type '1' for yes and '0' for no:" << "\n";
      cin >> own2;
      if (own2 == 0) {
        cout << "This property is still currently unowned." << "\n";
      }
      if (playerbalance < 60) {
        cout << "You cannot afford this property" << "\n";
        own2 = 0;
        cout << "This property is still currently unowned." << "\n";
      }
      if (own2 == 1) {
        cout << "You have purchased this property and are now the owner." << "\n";
        playerbalance -= 60;
        cout << "Your balance is now $" << playerbalance << "\n";
      }
    }
  }

  if (playerpos == 3) {
    cout << "You are currently on a Community Chest space." << "\n";
  }

  if (playerpos == 4) {
    cout << "You are currently at Towers." << "\n";
    if(own4 == 1) {
      cout << "This property is owned and you owe $4 rent." << "\n";
      playerbalance -= 4;
      cout << "Your balance is now $" << playerbalance << "\n";
      if (playerbalance < 0) {
        cout << "You are bankrupt and are no longer in the game." << "\n";
      }
    }
    if (own4 == 0) {
      cout << "This property is unowned. Would you like to buy it? Type '1' for yes and '0' for no:" << "\n";
      cin >> own4;
      if (own4 == 0) {
        cout << "This property is still currently unowned." << "\n";
      }
      if (playerbalance < 60) {
        cout << "You cannot afford this property" << "\n";
        own4 = 0;
        cout << "This property is still currently unowned." << "\n";
      }
      if (own4 == 1) {
        cout << "You have purchased this property and are now the owner." << "\n";
        playerbalance -= 60;
        cout << "Your balance is now $" << playerbalance << "\n";
      }
    }
  }

  if (playerpos == 5) {
    cout << "You are currently on 'Income Tax' you owe $200." << "\n";
    playerbalance -= 200;
    cout << "Your balance is now $" << playerbalance << "\n";
    if (playerbalance < 0) {
      cout << "You are bankrupt and are no longer in the game." << "\n";
    }
  }

  if (playerpos == 6) {
    cout << "You are currently at Blandford St. T Stop." << "\n";
    if(own6 == 1) {
      cout << "This property is owned and you owe $25 rent." << "\n";
      playerbalance -= 25;
      if (playerbalance < 0) {
        cout << "You are bankrupt and are no longer in the game." << "\n";
      }
    }
    if (own6 == 0) {
      cout << "This property is unowned. Would you like to buy it? Type '1' for yes and '0' for no:" << "\n";
      cin >> own6;
      if (own6 == 0) {
        cout << "This property is still currently unowned." << "\n";
      }
      if (playerbalance < 200) {
        cout << "You cannot afford this property" << "\n";
        own6 = 0;
        cout << "This property is still currently unowned." << "\n";
      }
      if (own6 == 1) {
        cout << "You have purchased this property and are now the owner." << "\n";
        playerbalance -= 200;
        cout << "Your balance is now $" << playerbalance << "\n";
      }
    }
  }

  if (playerpos == 7) {
    cout << "You are currently at Warren Towers." << "\n";
    if(own7 == 1) {
      cout << "This property is owned and you owe $6 rent." << "\n";
      playerbalance -= 6;
      if (playerbalance < 0) {
        cout << "You are bankrupt and are no longer in the game." << "\n";
      }
    }
    if (own7 == 0) {
      cout << "This property is unowned. Would you like to buy it? Type '1' for yes and '0' for no:" << "\n";
      cin >> own7;
      if (own7 == 0) {
        cout << "This property is still currently unowned." << "\n";
      }
      if (playerbalance < 100) {
        cout << "You cannot afford this property" << "\n";
        own7 = 0;
        cout << "This property is still currently unowned." << "\n";
      }
      if (own7 == 1) {
        cout << "You have purchased this property and are now the owner." << "\n";
        playerbalance -= 100;
        cout << "Your balance is now $" << playerbalance << "\n";
      }
    }
  }

  if (playerpos == 8) {
    cout << "You have landed on a Chance Card." << "\n";
  }

  if (playerpos == 9) {
    cout << "You are currently at West Campus Towers." << "\n";
    if(own9 == 1) {
      cout << "This property is owned and you owe $8 rent." << "\n";
      playerbalance -= 8;
      cout << "Your balance is now $" << playerbalance << "\n";
      if (playerbalance < 0) {
        cout << "You are bankrupt and are no longer in the game." << "\n";
      }
    }
    if (own9 == 0) {
      cout << "This property is unowned. Would you like to buy it? Type '1' for yes and '0' for no:" << "\n";
      cin >> own9;
      if (own9 == 0) {
        cout << "This property is still currently unowned." << "\n";
      }
      if (playerbalance < 100) {
        cout << "You cannot afford this property" << "\n";
        own9 = 0;
        cout << "This property is still currently unowned." << "\n";
      }
      if (own9 == 1) {
        cout << "You have purchased this property and are now the owner." << "\n";
        playerbalance -= 100;
        cout << "Your balance is now $" << playerbalance << "\n";
      }
    }
  }

  if (playerpos == 10) {
    cout << "You are currently at the College of General Studies." << "\n";
    if(own10 == 1) {
      cout << "This property is owned and you owe $6 rent." << "\n";
      playerbalance -= 6;
      cout << "Your balance is now $" << playerbalance << "\n";
      if (playerbalance < 0) {
        cout << "You are bankrupt and are no longer in the game." << "\n";
      }
    }
    if (own10 == 0) {
      cout << "This property is unowned. Would you like to buy it? Type '1' for yes and '0' for no:" << "\n";
      cin >> own10;
      if (own10 == 0) {
        cout << "This property is still currently unowned." << "\n";
      }
      if (playerbalance < 120) {
        cout << "You cannot afford this property" << "\n";
        own10 = 0;
        cout << "This property is still currently unowned." << "\n";
      }
      if (own10 == 1) {
        cout << "You have purchased this property and are now the owner." << "\n";
        playerbalance -= 120;
        cout << "Your balance is now $" << playerbalance << "\n";
      }
    }
  }


  if (playerpos == 11) {
    cout << "You are currently on 'Just Visiting'." << "\n";
  }

  if (playerpos == 12) {
    cout << "You have landed on the BU School of Theology." << "\n";
    if(own12 == 1) {
      cout << "This property is owned and you owe $10 rent." << "\n";
      playerbalance -= 10;
      cout << "Your balance is now $" << playerbalance << "\n";
      if (playerbalance < 0) {
        cout << "You are bankrupt and are no longer in the game." << "\n";
      }
    }
    if (own12 == 0) {
      cout << "This property is unowned. Would you like to buy it? Type '1' for yes and '0' for no:" << "\n";
      cin >> own12;
      if (own12 == 0) {
        cout << "This property is still currently unowned." << "\n";
      }
      if (playerbalance < 140) {
        cout << "You cannot afford this property" << "\n";
        own12 = 0;
        cout << "This property is still currently unowned." << "\n";
      }
      if (own12 == 1) {
        cout << "You have purchased this property and are now the owner." << "\n";
        playerbalance -= 140;
        cout << "Your balance is now $" << playerbalance << "\n";
      }
    }
  }

  if (playerpos == 13) {
    cout << "You have landed on BU 802.1x." << "\n";
    if(own13 == 1) {
      cout << "This property is owned and you owe $25 rent." << "\n";
      playerbalance -= 25;
      cout << "Your balance is now $" << playerbalance << "\n";
      if (playerbalance < 0) {
        cout << "You are bankrupt and are no longer in the game." << "\n";
      }
    }
    if (own13 == 0) {
      cout << "This property is unowned. Would you like to buy it? Type '1' for yes and '0' for no:" << "\n";
      cin >> own13;
      if (own13 == 0) {
        cout << "This property is still currently unowned." << "\n";
      }
      if (playerbalance < 150) {
        cout << "You cannot afford this property" << "\n";
        own13 = 0;
        cout << "This property is still currently unowned." << "\n";
      }
      if (own13 == 1) {
        cout << "You have purchased this property and are now the owner." << "\n";
        playerbalance -= 150;
        cout << "Your balance is now $" << playerbalance << "\n";
      }
    }
  }

  if (playerpos == 14) {
    cout << "You are currently at the BU College of Communications." << "\n";
    if(own14 == 1) {
      cout << "This property is owned and you owe $10 rent." << "\n";
      playerbalance -= 10;
      cout << "Your balance is now $" << playerbalance << "\n";
      if (playerbalance < 0) {
        cout << "You are bankrupt and are no longer in the game." << "\n";
      }
    }
    if (own14 == 0) {
      cout << "This property is unowned. Would you like to buy it? Type '1' for yes and '0' for no:" << "\n";
      cin >> own14;
      if (own14 == 0) {
        cout << "This property is still currently unowned." << "\n";
      }
      if (playerbalance < 140) {
        cout << "You cannot afford this property" << "\n";
        own14 = 0;
        cout << "This property is still currently unowned." << "\n";
      }
      if (own14 == 1) {
        cout << "You have purchased this property and are now the owner." << "\n";
        playerbalance -= 140;
        cout << "Your balance is now $" << playerbalance << "\n";
      }
    }
  }

  if (playerpos == 15) {
    cout << "You are currently at the College of Arts and Sciences." << "\n";
    if(own15 == 1) {
      cout << "This property is owned and you owe $12 rent." << "\n";
      playerbalance -= 12;
      cout << "Your balance is now $" << playerbalance << "\n";
      if (playerbalance < 0) {
        cout << "You are bankrupt and are no longer in the game." << "\n";
      }
    }
    if (own15 == 0) {
      cout << "This property is unowned. Would you like to buy it? Type '1' for yes and '0' for no:" << "\n";
      cin >> own15;
      if (own15 == 0) {
        cout << "This property is still currently unowned." << "\n";
      }
      if (playerbalance < 160) {
        cout << "You cannot afford this property" << "\n";
        own15 = 0;
        cout << "This property is still currently unowned." << "\n";
      }
      if (own15 == 1) {
        cout << "You have purchased this property and are now the owner." << "\n";
        playerbalance -= 160;
        cout << "Your balance is now $" << playerbalance << "\n";
      }
    }
  }

  if (playerpos == 16) {
    cout << "You are currently at the 'BU East' T stop." << "\n";
    if(own16 == 1) {
      cout << "This property is owned and you owe $25 rent." << "\n";
      playerbalance -= 25;
      cout << "Your balance is now $" << playerbalance << "\n";
      if (playerbalance < 0) {
        cout << "You are bankrupt and are no longer in the game." << "\n";
      }
    }
    if (own16 == 0) {
      cout << "This property is unowned. Would you like to buy it? Type '1' for yes and '0' for no:" << "\n";
      cin >> own16;
      if (own16 == 0) {
        cout << "This property is still currently unowned." << "\n";
      }
      if (playerbalance < 200) {
        cout << "You cannot afford this property" << "\n";
        own16 = 0;
        cout << "This property is still currently unowned." << "\n";
      }
      if (own16 == 1) {
        cout << "You have purchased this property and are now the owner." << "\n";
        playerbalance -= 200;
        cout << "Your balance is now $" << playerbalance << "\n";
      }
    }
  }

  if (playerpos == 17) {
    cout << "You are currently at the Metcalf Science Center." << "\n";
    if(own17 == 1) {
      cout << "This property is owned and you owe $14 rent." << "\n";
      playerbalance -= 14;
      cout << "Your balance is now $" << playerbalance << "\n";
      if (playerbalance < 0) {
        cout << "You are bankrupt and are no longer in the game." << "\n";
      }
    }
    if (own17 == 0) {
      cout << "This property is unowned. Would you like to buy it? Type '1' for yes and '0' for no:" << "\n";
      cin >> own17;
      if (own17 == 0) {
        cout << "This property is still currently unowned." << "\n";
      }
      if (playerbalance < 180) {
        cout << "You cannot afford this property" << "\n";
        own17 = 0;
        cout << "This property is still currently unowned." << "\n";
      }
      if (own17 == 1) {
        cout << "You have purchased this property and are now the owner." << "\n";
        playerbalance -= 180;
        cout << "Your balance is now $" << playerbalance << "\n";
      }
    }
  }

  if (playerpos == 18) {
    cout << "You have landed on a 'Community Chest' space." << "\n";
  }

  if (playerpos == 19) {
    cout << "You are currently at the Ingalls Engineering Building." << "\n";
    if(own19 == 1) {
      cout << "This property is owned and you owe $14 rent." << "\n";
      playerbalance -= 14;
      cout << "Your balance is now $" << playerbalance << "\n";
      if (playerbalance < 0) {
        cout << "You are bankrupt and are no longer in the game." << "\n";
      }
    }
    if (own19 == 0) {
      cout << "This property is unowned. Would you like to buy it? Type '1' for yes and '0' for no:" << "\n";
      cin >> own19;
      if (own19 == 0) {
        cout << "This property is still currently unowned." << "\n";
      }
      if (playerbalance < 180) {
        cout << "You cannot afford this property" << "\n";
        own19 = 0;
        cout << "This property is still currently unowned." << "\n";
      }
      if (own19 == 1) {
        cout << "You have purchased this property and are now the owner." << "\n";
        playerbalance -= 180;
        cout << "Your balance is now $" << playerbalance << "\n";
      }
    }
  }

  if (playerpos == 20) {
    cout << "You have landed at the BU Photonics Center." << "\n";
    if(own20 == 1) {
      cout << "This property is owned and you owe $16 rent." << "\n";
      playerbalance -= 16;
      cout << "Your balance is now $" << playerbalance << "\n";
      if (playerbalance < 0) {
        cout << "You are bankrupt and are no longer in the game." << "\n";
      }
    }
    if (own20 == 0) {
      cout << "This property is unowned. Would you like to buy it? Type '1' for yes and '0' for no:" << "\n";
      cin >> own20;
      if (own20 == 0) {
        cout << "This property is still currently unowned." << "\n";
      }
      if (playerbalance < 200) {
        cout << "You cannot afford this property" << "\n";
        own20 = 0;
        cout << "This property is still currently unowned." << "\n";
      }
      if (own20 == 1) {
        cout << "You have purchased this property and are now the owner." << "\n";
        playerbalance -= 200;
      }
    }
  }

  if (playerpos == 21) {
    cout << "You have somehow managed to find 'Free Parking' in Boston." << "\n";
  }

  if (playerpos == 22) {
    cout << "You have landed at the BU Chapel." << "\n";
    if(own22 == 1) {
      cout << "This property is owned and you owe $18 rent." << "\n";
      playerbalance -= 18;
      cout << "Your balance is now $" << playerbalance << "\n";
      if (playerbalance < 0) {
        cout << "You are bankrupt and are no longer in the game." << "\n";
      }
    }
    if (own22 == 0) {
      cout << "This property is unowned. Would you like to buy it? Type '1' for yes and '0' for no:" << "\n";
      cin >> own22;
      if (own22 == 0) {
        cout << "This property is still currently unowned." << "\n";
      }
      if (playerbalance < 220) {
        cout << "You cannot afford this property" << "\n";
        own22 = 0;
        cout << "This property is still currently unowned." << "\n";
      }
      if (own22 == 1) {
        cout << "You have purchased this property and are now the owner." << "\n";
        playerbalance -= 220;
        cout << "Your balance is now $" << playerbalance << "\n";
      }
    }
  }

  if (playerpos == 23) {
    cout << "You landed on a 'Chance Card'." << "\n";
  }

  if (playerpos == 24) {
    cout << "You are visting FitRec for a workout." << "\n";
    if(own24 == 1) {
      cout << "This property is owned and you owe $18 rent." << "\n";
      playerbalance -= 18;
      cout << "Your balance is now $" << playerbalance << "\n";
      if (playerbalance < 0) {
        cout << "You are bankrupt and are no longer in the game." << "\n";
      }
    }
    if (own24 == 0) {
      cout << "This property is unowned. Would you like to buy it? Type '1' for yes and '0' for no:" << "\n";
      cin >> own24;
      if (own24 == 0) {
        cout << "This property is still currently unowned." << "\n";
      }
      if (playerbalance < 220) {
        cout << "You cannot afford this property" << "\n";
        own24 = 0;
        cout << "This property is still currently unowned." << "\n";
      }
      if (own24 == 1) {
        cout << "You have purchased this property and are now the owner." << "\n";
        playerbalance -= 220;
        cout << "Your balance is now $" << playerbalance << "\n";
      }
    }
  }

  if (playerpos == 25) {
    cout << "You are a currently a freshman at the BU Beach, confused there is no sand." << "\n";
    if(own25 == 1) {
      cout << "This property is owned and you owe $20 rent." << "\n";
      playerbalance -= 20;
      cout << "Your balance is now $" << playerbalance << "\n";
      if (playerbalance < 0) {
        cout << "You are bankrupt and are no longer in the game." << "\n";
      }
    }
    if (own25 == 0) {
      cout << "This property is unowned. Would you like to buy it? Type '1' for yes and '0' for no:" << "\n";
      cin >> own25;
      if (own25 == 0) {
        cout << "This property is still currently unowned." << "\n";
      }
      if (playerbalance < 240) {
        cout << "You cannot afford this property" << "\n";
        own25 = 0;
        cout << "This property is still currently unowned." << "\n";
      }
      if (own25 == 1) {
        cout << "You have purchased this property and are now the owner." << "\n";
        playerbalance -= 240;
        cout << "Your balance is now $" << playerbalance << "\n";
      }
    }
  }

  if (playerpos == 26) {
    cout << "You have landed at the 'BU Central' T stop." << "\n";
    if(own26 == 1) {
      cout << "This property is owned and you owe $25 rent." << "\n";
      playerbalance -= 25;
      cout << "Your balance is now $" << playerbalance << "\n";
      if (playerbalance < 0) {
        cout << "You are bankrupt and are no longer in the game." << "\n";
      }
    }
    if (own26 == 0) {
      cout << "This property is unowned. Would you like to buy it? Type '1' for yes and '0' for no:" << "\n";
      cin >> own26;
      if (own26 == 0) {
        cout << "This property is still currently unowned." << "\n";
      }
      if (playerbalance < 200) {
        cout << "You cannot afford this property" << "\n";
        own26 = 0;
        cout << "This property is still currently unowned." << "\n";
      }
      if (own26 == 1) {
        cout << "You have purchased this property and are now the owner." << "\n";
        playerbalance -= 200;
        cout << "Your balance is now $" << playerbalance << "\n";
      }
    }
  }

  if (playerpos == 27) {
    cout << "You are currently in South Campus" << "\n";
    if(own27 == 1) {
      cout << "This property is owned and you owe $22 rent." << "\n";
      playerbalance -= 22;
      cout << "Your balance is now $" << playerbalance << "\n";
      if (playerbalance < 0) {
        cout << "You are bankrupt and are no longer in the game." << "\n";
      }
    }
    if (own27 == 0) {
      cout << "This property is unowned. Would you like to buy it? Type '1' for yes and '0' for no:" << "\n";
      cin >> own27;
      if (own27 == 0) {
        cout << "This property is still currently unowned." << "\n";
      }
      if (playerbalance < 260) {
        cout << "You cannot afford this property" << "\n";
        own27 = 0;
        cout << "This property is still currently unowned." << "\n";
      }
      if (own27 == 1) {
        cout << "You have purchased this property and are now the owner." << "\n";
        playerbalance -= 260;
        cout << "Your balance is now $" << playerbalance << "\n";
      }
    }
  }

  if (playerpos == 28) {
    cout << "You are currently walking on Bay State Road." << "\n";
    if(own28 == 1) {
      cout << "This property is owned and you owe $22 rent." << "\n";
      playerbalance -= 22;
      cout << "Your balance is now $" << playerbalance << "\n";
      if (playerbalance < 0) {
        cout << "You are bankrupt and are no longer in the game." << "\n";
      }
    }
    if (own28 == 0) {
      cout << "This property is unowned. Would you like to buy it? Type '1' for yes and '0' for no:" << "\n";
      cin >> own28;
      if (own28 == 0) {
        cout << "This property is still currently unowned." << "\n";
      }
      if (playerbalance < 260) {
        cout << "You cannot afford this property" << "\n";
        own28 = 0;
        cout << "This property is still currently unowned." << "\n";
      }
      if (own28 == 1) {
        cout << "You have purchased this property and are now the owner." << "\n";
        playerbalance -= 260;
        cout << "Your balance is now $" << playerbalance << "\n";
      }
    }
  }

  if (playerpos == 29) {
    cout << "You are visiting the BU Boathouse." << "\n";
    if(own29 == 1) {
      cout << "This property is owned and you owe $25 rent." << "\n";
      playerbalance -= 25;
      cout << "Your balance is now $" << playerbalance << "\n";
      if (playerbalance < 0) {
        cout << "You are bankrupt and are no longer in the game." << "\n";
      }
    }
    if (own29 == 0) {
      cout << "This property is unowned. Would you like to buy it? Type '1' for yes and '0' for no:" << "\n";
      cin >> own29;
      if (own29 == 0) {
        cout << "This property is still currently unowned." << "\n";
      }
      if (playerbalance < 150) {
        cout << "You cannot afford this property" << "\n";
        own29 = 0;
        cout << "This property is still currently unowned." << "\n";
      }
      if (own29 == 1) {
        cout << "You have purchased this property and are now the owner." << "\n";
        playerbalance -= 150;
        cout << "Your balance is now $" << playerbalance << "\n";
      }
    }
  }

  if (playerpos == 30) {
    cout << "You have landed at Stuvi 1." << "\n";
    if(own30 == 1) {
      cout << "This property is owned and you owe $24 rent." << "\n";
      playerbalance -= 24;
      cout << "Your balance is now $" << playerbalance << "\n";
      if (playerbalance < 0) {
        cout << "You are bankrupt and are no longer in the game." << "\n";
      }
    }
    if (own30 == 0) {
      cout << "This property is unowned. Would you like to buy it? Type '1' for yes and '0' for no:" << "\n";
      cin >> own30;
      if (own30 == 0) {
        cout << "This property is still currently unowned." << "\n";
      }
      if (playerbalance < 280) {
        cout << "You cannot afford this property" << "\n";
        own30 = 0;
        cout << "This property is still currently unowned." << "\n";
      }
      if (own30 == 1) {
        cout << "You have purchased this property and are now the owner." << "\n";
        playerbalance -= 280;
        cout << "Your balance is now $" << playerbalance << "\n";
      }
    }
  }

  if (playerpos == 31) {
    cout << "You have been placed on academic probation. Go directly to the office. Do not pass 'GO'." << "\n";
  }

  if (playerpos == 32) {
    cout << "You are enjoying homemade pasta at Marciano Commons." << "\n";
    if(own32 == 1) {
      cout << "This property is owned and you owe $26 rent." << "\n";
      playerbalance -= 26;
      cout << "Your balance is now $" << playerbalance << "\n";
      if (playerbalance < 0) {
        cout << "You are bankrupt and are no longer in the game." << "\n";
      }
    }
    if (own32 == 0) {
      cout << "This property is unowned. Would you like to buy it? Type '1' for yes and '0' for no:" << "\n";
      cin >> own32;
      if (own32 == 0) {
        cout << "This property is still currently unowned." << "\n";
      }
      if (playerbalance < 300) {
        cout << "You cannot afford this property" << "\n";
        own32 = 0;
        cout << "This property is still currently unowned." << "\n";
      }
      if (own32 == 1) {
        cout << "You have purchased this property and are now the owner." << "\n";
        playerbalance -= 300;
        cout << "Your balance is now $" << playerbalance << "\n";
      }
    }
  }

  if (playerpos == 33) {
    cout << "You are visiting the Kilachand Science Building." << "\n";
    if(own33 == 1) {
      cout << "This property is owned and you owe $26 rent." << "\n";
      playerbalance -= 26;
      cout << "Your balance is now $" << playerbalance << "\n";
      if (playerbalance < 0) {
        cout << "You are bankrupt and are no longer in the game." << "\n";
      }
    }
    if (own33 == 0) {
      cout << "This property is unowned. Would you like to buy it? Type '1' for yes and '0' for no:" << "\n";
      cin >> own33;
      if (own33 == 0) {
        cout << "This property is still currently unowned." << "\n";
      }
      if (playerbalance < 300) {
        cout << "You cannot afford this property" << "\n";
        own33 = 0;
        cout << "This property is still currently unowned." << "\n";
      }
      if (own33 == 1) {
        cout << "You have purchased this property and are now the owner." << "\n";
        playerbalance -= 300;
        cout << "Your balance is now $" << playerbalance << "\n";
      }
    }
  }

  if (playerpos == 34) {
    cout << "You have landed on a 'Community Chest' space." << "\n";
  }

  if (playerpos == 35) {
    cout << "You have landed on the 'Questrom School of Business." << "\n";
    if(own35 == 1) {
      cout << "This property is owned and you owe $28 rent." << "\n";
      playerbalance -= 28;
      cout << "Your balance is now $" << playerbalance << "\n";
      if (playerbalance < 0) {
        cout << "You are bankrupt and are no longer in the game." << "\n";
      }
    }
    if (own35 == 0) {
      cout << "This property is unowned. Would you like to buy it? Type '1' for yes and '0' for no:" << "\n";
      cin >> own35;
      if (own35 == 0) {
        cout << "This property is still currently unowned." << "\n";
      }
      if (playerbalance < 320) {
        cout << "You cannot afford this property" << "\n";
        own35 = 0;
        cout << "This property is still currently unowned." << "\n";
      }
      if (own35 == 1) {
        cout << "You have purchased this property and are now the owner." << "\n";
        playerbalance -= 320;
        cout << "Your balance is now $" << playerbalance << "\n";
      }
  }

  if (playerpos == 36) {
    cout << "You are at the 'BU West' T stop." << "\n";
    if(own36 == 1) {
      cout << "This property is owned and you owe $25 rent." << "\n";
      playerbalance -= 25;
      cout << "Your balance is now $" << playerbalance << "\n";
      if (playerbalance < 0) {
        cout << "You are bankrupt and are no longer in the game." << "\n";
      }
    }
    if (own36 == 0) {
      cout << "This property is unowned. Would you like to buy it? Type '1' for yes and '0' for no:" << "\n";
      cin >> own36;
      if (own36 == 0) {
        cout << "This property is still currently unowned." << "\n";
      }
      if (playerbalance < 200) {
        cout << "You cannot afford this property" << "\n";
        own36 = 0;
        cout << "This property is still currently unowned." << "\n";
      }
      if (own36 == 1) {
        cout << "You have purchased this property and are now the owner." << "\n";
        playerbalance -= 200;
        cout << "Your balance is now $" << playerbalance << "\n";
      }
    }
  }

  if (playerpos == 37) {
    cout << "You have landed on a 'Chance' card." << "\n";
  }

  if (playerpos == 38) {
    cout << "You have landed at Myles Standish Hall." << "\n";
    if(own38 == 1) {
      cout << "This property is owned and you owe $35 rent." << "\n";
      playerbalance -= 35;
      cout << "Your balance is now $" << playerbalance << "\n";
      if (playerbalance < 0) {
        cout << "You are bankrupt and are no longer in the game." << "\n";
      }
    }
    if (own38 == 0) {
      cout << "This property is unowned. Would you like to buy it? Type '1' for yes and '0' for no:" << "\n";
      cin >> own38;
      if (own38 == 0) {
        cout << "This property is still currently unowned." << "\n";
      }
      if (playerbalance < 350) {
        cout << "You cannot afford this property" << "\n";
        own38 = 0;
        cout << "This property is still currently unowned." << "\n";
      }
      if (own38 == 1) {
        cout << "You have purchased this property and are now the owner." << "\n";
        playerbalance -= 350;
        cout << "Your balance is now $" << playerbalance << "\n";
      }
    }
    if(own38 == 1) {
      cout << "This property is owned and you owe $35 rent." << "\n";
      playerbalance -= 35;
      cout << "Your balance is now $" << playerbalance << "\n";
      if (playerbalance < 0) {
        cout << "You are bankrupt and are no longer in the game." << "\n";
      }
    }
  }

  if (playerpos == 39) {
    cout << "You have landed on the 'Luxury Tax' space. Pay $100 to BU Financial Aid." << "\n";
    playerbalance -= 100;
    cout << "Your balance is now $" << playerbalance << "\n";
    if (playerbalance < 0) {
      cout << "You are bankrupt and are no longer in the game." << "\n";
    }
  }

  if (playerpos == 40) {
    cout << "You are visiting Stuvi 2." << "\n";
    if(own40 == 1) {
      cout << "This property is owned and you owe $50 rent." << "\n";
      playerbalance -= 50;
      cout << "Your balance is now $" << playerbalance << "\n";
      if (playerbalance < 0) {
        cout << "You are bankrupt and are no longer in the game." << "\n";
      }
    }
    if (own40 == 0) {
      cout << "This property is unowned. Would you like to buy it? Type '1' for yes and '0' for no:" << "\n";
      cin >> own40;
      if (own40 == 0) {
        cout << "This property is still currently unowned." << "\n";
      }
      if (playerbalance < 400) {
        cout << "You cannot afford this property" << "\n";
        own40 = 0;
        cout << "This property is still currently unowned." << "\n";
      }
      if (own40 == 1) {
        cout << "You have purchased this property and are now the owner." << "\n";
        playerbalance -= 400;
        cout << "Your balance is now $" << playerbalance << "\n";
      }
    }
  }

  }
  // return updated values // 
    updatedinfo = {playerpos, playerbalance};
    return updatedinfo;
}


#endif