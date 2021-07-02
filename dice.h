// Copyright 2021 Christopher Lemus lemusc@bu.edu
// Copyright 2021 Jovany Vazquez jvazquez@bu.edu
// Copyright 2021 Zachary Capone zcapone@bu.edu
#ifndef DICE_H
#define DICE_H

// diceroll() rolls two die and returns a sumation // 

int diceroll(){
  srand((unsigned int)time(NULL));
    {
        int dicenum1; 
        int dicenum2;
        int dicenum;
        int dicei = 0;

        using std::cout;
        dicenum1 = rand()%6;
        dicenum1 += 1;
        cout << dicenum1 << "\n";
        dicenum2 =rand()%6;
        dicenum2 += 1;
        cout << dicenum2 << "\n";
        dicenum = dicenum1 + dicenum2;
        cout << dicenum << "\n";
    return dicenum;
  }
}

#endif