// Copyright 2021 Christopher Lemus lemusc@bu.edu
// Monopoly board SFML

#include <SFML/Graphics.hpp>
#include <iostream>
#include <chrono>
#include <ctime>
#include <string>
#include <vector>
#include "dice.h"
#include "playerposition.h"
#include "cccards.h"
#include "jail.h"

using std::cin;
using std::cout;
using std::__cxx11::stoi;
using std::__cxx11::to_string;
using std::string;
using std::vector;
using std::endl;

int userinput;  // declare number of players for game
int moveTracker = 0;  // keep track of who moved in a match;
// jail counter for every player
int sealWaitJailCounter = 0;
int terrierWaitJailCounter = 0;
int presidentWaitJailCounter = 0;
int shuttleWaitJailCounter = 0;
// jail card balance for each player 
int sealJailCardBalance = 0;
int terrierJailCardBalance = 0;
int presidentJailCardBalance = 0;
int shuttleJailCardBalance = 0;
// skip tokens to keep track of who can play 
int sealSkipToken = 0;
int terrierSkipToken = 0;
int presidentSkipToken = 0;
int shuttleSkipToken = 0; 
// initial positions on board
int terrierinitialPos = 1;
int sealinitialPos = 1;
int presidentinitialPos = 1;
int shuttleinitialPos = 1;
// initial balances for each player
int terrierinitialBalance = 1500;
int sealinitialBalance = 1500;
int presidentinitialBalance = 1500;
int shuttleinitialBalance = 1500;
//vector for coordinates
vector<int> xy;
vector<int> coord;


vector<int> coordinate(int pos){  // This function calculates coordinate which will move players around board
  int playerposition;
  playerposition = pos;
  if (playerposition == 1) { 
    coord = {790, 780};
  }
  if (playerposition > 1 && playerposition <= 11){
    // hard code coordinates to be returned for the piece 
    coord = {790-68*(playerposition-1), 780};
  } else if (playerposition >= 12 && playerposition <= 21){ 
    coord = {110, 780-68*(playerposition-11)};
    // hard code coordinates to be returned for the piece
  } else if (playerposition >= 22 && playerposition <= 31){
    // hard code coordinates to be returned for the piece 
    coord = {110+68*(playerposition-21), 110};
  } else if (playerposition >= 32 && playerposition <= 40){
    // hard code coordinates to be returned for the piece 
    coord = {790, 110+68*(playerposition-31)};
  }
  return coord;
}

int main(int argc, char** argv){
cout << "enter number of players: " << endl;
cin >> userinput;  // For # players at cmnd line
std::vector<int> sealinfo, terrierinfo, presidentinfo, shuttleinfo;
std::vector<int> cccout;  // returns position and new balance
std::vector<int> jailout; // returns jail counter for each player, position, $$$balance, jailcard balance

// Words + Font + Size //
sf::Text hojo, towers, warren, westcamp, cgs, sth, com, cas,
sci, eng, pho, buchapel, fitrec, bubeach, baystateroad, southcamp,
stuvi1, marciano, kilachand, questrom, myleshall, stuvi2,
blanford, bueast, bucentral, buwest, electric, buboathouse, chancee1,
chancee2, chancee3, commchest1, commchest2, commchest3,
go, luxurytax, incometax, jail, free, gto, bumono;
sf::Font font;
font.loadFromFile("/usr/share/fonts/truetype/ubuntu/Ubuntu-BI.ttf");

// Define Strings
hojo.setString("The Hojo\n\nPrice $60");
hojo.setFont(font);
hojo.setCharacterSize(12);
hojo.setFillColor(sf::Color::Black);
towers.setString("The Towers\n\nPrice $60");
towers.setFont(font);
towers.setCharacterSize(12);
towers.setFillColor(sf::Color::Black);
warren.setString("Warren\n\nPrice $100");
warren.setFont(font);
warren.setCharacterSize(12);
warren.setFillColor(sf::Color::Black);
westcamp.setString("West\nCampus \ntowers\n\nPrice $100");
westcamp.setFont(font);
westcamp.setCharacterSize(12);
westcamp.setFillColor(sf::Color::Black);
cgs.setString("CGS\n\nPrice $120");
cgs.setFont(font);
cgs.setCharacterSize(12);
cgs.setFillColor(sf::Color::Black);
sth.setString("STH\n\nPrice $140");
sth.setFont(font);
sth.setCharacterSize(12);
sth.setFillColor(sf::Color::Black);
com.setString("COM\n\nPrice $140");
com.setFont(font);
com.setCharacterSize(12);
com.setFillColor(sf::Color::Black);
cas.setString("CAS\n\nPrice $160");
cas.setFont(font);
cas.setCharacterSize(12);
cas.setFillColor(sf::Color::Black);
sci.setString("SCI\n\nPrice $180");
sci.setFont(font);
sci.setCharacterSize(12);
sci.setFillColor(sf::Color::Black);
eng.setString("ENG\n\nPrice $180");
eng.setFont(font);
eng.setCharacterSize(12);
eng.setFillColor(sf::Color::Black);
pho.setString("PHO\n\nPrice $200");
pho.setFont(font);
pho.setCharacterSize(12);
pho.setFillColor(sf::Color::Black);
buchapel.setString("BU\nChapel\n\nPrice $220");
buchapel.setFont(font);
buchapel.setCharacterSize(12);
buchapel.setFillColor(sf::Color::Black);
fitrec.setString("FitRec\n\nPrice $220");
fitrec.setFont(font);
fitrec.setCharacterSize(12);
fitrec.setFillColor(sf::Color::Black);
bubeach.setString("BU\nBeach\n\nPrice $240");
bubeach.setFont(font);
bubeach.setCharacterSize(12);
bubeach.setFillColor(sf::Color::Black);
baystateroad.setString("The Bay\nState \nRoad\n\nPrice $260");
baystateroad.setFont(font);
baystateroad.setCharacterSize(12);
baystateroad.setFillColor(sf::Color::Black);
southcamp.setString("South\nCampus\n\nPrice $260");
southcamp.setFont(font);
southcamp.setCharacterSize(12);
southcamp.setFillColor(sf::Color::Black);
stuvi1.setString("The\nStuvi 1\n\nPrice $280");
stuvi1.setFont(font);
stuvi1.setCharacterSize(12);
stuvi1.setFillColor(sf::Color::Black);
marciano.setString("Marciano\n\nPrice $300");
marciano.setFont(font);
marciano.setCharacterSize(12);
marciano.setFillColor(sf::Color::Black);
kilachand.setString("Kilachand \nScience\nBuilding\n\nPrice $300");
kilachand.setFont(font);
kilachand.setCharacterSize(12);
kilachand.setFillColor(sf::Color::Black);
questrom.setString("Questrom\n\nPrice $320");
questrom.setFont(font);
questrom.setCharacterSize(12);
questrom.setFillColor(sf::Color::Black);
myleshall.setString("Myles\nHall\n\nPrice $350");
myleshall.setFont(font);
myleshall.setCharacterSize(12);
myleshall.setFillColor(sf::Color::Black);
stuvi2.setString("The\nStuvi 2\n\nPrice $400");
stuvi2.setFont(font);
stuvi2.setCharacterSize(12);
stuvi2.setFillColor(sf::Color::Black);
blanford.setString("Blanford\n\nPrice $200");
blanford.setFont(font);
blanford.setCharacterSize(12);
blanford.setFillColor(sf::Color::Black);
bueast.setString("BU East\n\nPrice $200");
bueast.setFont(font);
bueast.setCharacterSize(12);
bueast.setFillColor(sf::Color::Black);
bucentral.setString("BU\nCentral\n\nPrice $200");
bucentral.setFont(font);
bucentral.setCharacterSize(12);
bucentral.setFillColor(sf::Color::Black);
buwest.setString("BU West\n\nPrice $200");
buwest.setFont(font);
buwest.setCharacterSize(12);
buwest.setFillColor(sf::Color::Black);
electric.setString("BU\nElectric\n\nPrice $150");
electric.setFont(font);
electric.setCharacterSize(12);
electric.setFillColor(sf::Color::Black);
buboathouse.setString("The BU\nBoathouse\nPrice $150");
buboathouse.setFont(font);
buboathouse.setCharacterSize(12);
buboathouse.setFillColor(sf::Color::Black);
chancee1.setString("Chance");
chancee1.setFont(font);
chancee1.setCharacterSize(12);
chancee1.setFillColor(sf::Color::Black);
chancee2.setString("Chance");
chancee2.setFont(font);
chancee2.setCharacterSize(12);
chancee2.setFillColor(sf::Color::Black);
chancee3.setString("Chance");
chancee3.setFont(font);
chancee3.setCharacterSize(12);
chancee3.setFillColor(sf::Color::Black);
commchest1.setString("Community\nChest");
commchest1.setFont(font);
commchest1.setCharacterSize(12);
commchest1.setFillColor(sf::Color::Black);
commchest2.setString("Community\nChest");
commchest2.setFont(font);
commchest2.setCharacterSize(12);
commchest2.setFillColor(sf::Color::Black);
commchest3.setString("Community\nChest");
commchest3.setFont(font);
commchest3.setCharacterSize(12);
commchest3.setFillColor(sf::Color::Black);
go.setString("GO");
go.setFont(font);
go.setCharacterSize(20);
go.setFillColor(sf::Color::Red);
luxurytax.setString("Luxury\nTax");
luxurytax.setFont(font);
luxurytax.setCharacterSize(12);
luxurytax.setFillColor(sf::Color::Black);
incometax.setString("Income\nTax");
incometax.setFont(font);
incometax.setCharacterSize(12);
incometax.setFillColor(sf::Color::Black);
jail.setString("JAIL");
jail.setFont(font);
jail.setCharacterSize(20);
jail.setFillColor(sf::Color::Black);
free.setString("FREE\nPARKING");
free.setFont(font);
free.setCharacterSize(20);
free.setFillColor(sf::Color::Black);
gto.setString("GO TO \n JAIL");
gto.setFont(font);
gto.setCharacterSize(20);
gto.setFillColor(sf::Color::Black);
bumono.setString("BU MONOPOLY");
bumono.setFont(font);
bumono.setCharacterSize(70);
bumono.setFillColor(sf::Color::Red);

// Initializing Sprites for Players //
sf::Image BUshuttle, BUterrier, PresBrown, BUseal;
BUshuttle.create(10,10,sf::Color::Yellow);
BUshuttle.loadFromFile("BUbus.png");
// Initializing textures for players above // 
sf::Texture BUshuttletexture;
BUshuttletexture.loadFromImage(BUshuttle);
sf::Sprite shuttle;
shuttle.setTexture(BUshuttletexture);
shuttle.setOrigin(BUshuttletexture.getSize().x/2,BUshuttletexture.getSize().y/2);

BUterrier.create(10,10,sf::Color::Yellow);
BUterrier.loadFromFile("BUterrier.jpeg");
// Initializing textures for players above // 
sf::Texture BUterriertexture;
BUterriertexture.loadFromImage(BUterrier);
sf::Sprite terrier;
terrier.setTexture(BUterriertexture);
terrier.setOrigin(BUterriertexture.getSize().x/2,BUterriertexture.getSize().y/2);

BUseal.create(10,10,sf::Color::Yellow);
BUseal.loadFromFile("BUseal.png");
// Initializing textures for players above // 
sf::Texture BUsealtexture;
BUsealtexture.loadFromImage(BUseal);
sf::Sprite seal;
seal.setTexture(BUsealtexture);
seal.setOrigin(BUsealtexture.getSize().x/2,BUsealtexture.getSize().y/2);

PresBrown.create(10,10,sf::Color::Yellow);
PresBrown.loadFromFile("PresidentBrown.jpeg");
// Initializing textures for players above // 
sf::Texture PresBrowntexture;
PresBrowntexture.loadFromImage(PresBrown);
sf::Sprite president;
president.setTexture(PresBrowntexture);
president.setOrigin(PresBrowntexture.getSize().x/2,BUshuttletexture.getSize().y/2);




// Initializing window + color //
sf::RenderWindow window(sf::VideoMode(900, 900), "BU MONOPOLY!");
window.setFramerateLimit(300);
window.clear(sf::Color::White);

// Create size of shapes & Outline + Color//
sf::RectangleShape monopolyboard(sf::Vector2f(0, 0));
sf::RectangleShape square1(sf::Vector2f(140,140));  // Top Left
square1.setOutlineThickness(3);
square1.setOutlineColor(sf::Color::Black);
sf::RectangleShape square2(sf::Vector2f(69,140));
square2.setOutlineThickness(3);
square2.setOutlineColor(sf::Color::Black);
sf::RectangleShape square3(sf::Vector2f(69,140));
square3.setOutlineThickness(3);
square3.setOutlineColor(sf::Color::Black);
sf::RectangleShape square4(sf::Vector2f(69,140));
square4.setOutlineThickness(3);
square4.setOutlineColor(sf::Color::Black);
sf::RectangleShape square5(sf::Vector2f(69,140));
square5.setOutlineThickness(3);
square5.setOutlineColor(sf::Color::Black);
sf::RectangleShape square6(sf::Vector2f(69,140));
square6.setOutlineThickness(3);
square6.setOutlineColor(sf::Color::Black);
sf::RectangleShape square7(sf::Vector2f(69,140));
square7.setOutlineThickness(3);
square7.setOutlineColor(sf::Color::Black);
sf::RectangleShape square8(sf::Vector2f(69,140));
square8.setOutlineThickness(3);
square8.setOutlineColor(sf::Color::Black);
sf::RectangleShape square9(sf::Vector2f(69,140));
square9.setOutlineThickness(3);
square9.setOutlineColor(sf::Color::Black);
sf::RectangleShape square10(sf::Vector2f(69,140));
square10.setOutlineThickness(3);
square10.setOutlineColor(sf::Color::Black);
sf::RectangleShape square11(sf::Vector2f(140,140));  // Top Right
square11.setOutlineThickness(3);
square11.setOutlineColor(sf::Color::Black);

sf::RectangleShape square12(sf::Vector2f(69,140));
square12.setOutlineThickness(3);
square12.setOutlineColor(sf::Color::Black);
sf::RectangleShape square13(sf::Vector2f(69,140));
square13.setOutlineThickness(3);
square13.setOutlineColor(sf::Color::Black);
sf::RectangleShape square14(sf::Vector2f(69,140));
square14.setOutlineThickness(3);
square14.setOutlineColor(sf::Color::Black);
sf::RectangleShape square15(sf::Vector2f(69,140));
square15.setOutlineThickness(3);
square15.setOutlineColor(sf::Color::Black);
sf::RectangleShape square16(sf::Vector2f(69,140));
square16.setOutlineThickness(3);
square16.setOutlineColor(sf::Color::Black);
sf::RectangleShape square17(sf::Vector2f(69,140));
square17.setOutlineThickness(3);
square17.setOutlineColor(sf::Color::Black);
sf::RectangleShape square18(sf::Vector2f(69,140));
square18.setOutlineThickness(3);
square18.setOutlineColor(sf::Color::Black);
sf::RectangleShape square19(sf::Vector2f(69,140));
square19.setOutlineThickness(3);
square19.setOutlineColor(sf::Color::Black);
sf::RectangleShape square20(sf::Vector2f(69,140));
square20.setOutlineThickness(3);
square20.setOutlineColor(sf::Color::Black);
sf::RectangleShape square21(sf::Vector2f(140,140));  // Bottom Right
square21.setOutlineThickness(3);
square21.setOutlineColor(sf::Color::Black);

sf::RectangleShape square22(sf::Vector2f(69,140));
square22.setOutlineThickness(3);
square22.setOutlineColor(sf::Color::Black);
sf::RectangleShape square23(sf::Vector2f(69,140));
square23.setOutlineThickness(3);
square23.setOutlineColor(sf::Color::Black);
sf::RectangleShape square24(sf::Vector2f(69,140));
square24.setOutlineThickness(3);
square24.setOutlineColor(sf::Color::Black);
sf::RectangleShape square25(sf::Vector2f(69,140));
square25.setOutlineThickness(3);
square25.setOutlineColor(sf::Color::Black);
sf::RectangleShape square26(sf::Vector2f(69,140));
square26.setOutlineThickness(3);
square26.setOutlineColor(sf::Color::Black);
sf::RectangleShape square27(sf::Vector2f(69,140));
square27.setOutlineThickness(3);
square27.setOutlineColor(sf::Color::Black);
sf::RectangleShape square28(sf::Vector2f(69,140));
square28.setOutlineThickness(3);
square28.setOutlineColor(sf::Color::Black);
sf::RectangleShape square29(sf::Vector2f(69,140));
square29.setOutlineThickness(3);
square29.setOutlineColor(sf::Color::Black);
sf::RectangleShape square30(sf::Vector2f(69,140));
square30.setOutlineThickness(3);
square30.setOutlineColor(sf::Color::Black);
sf::RectangleShape square31(sf::Vector2f(140,140));  // Bottom Left
square31.setOutlineThickness(3);
square31.setOutlineColor(sf::Color::Black); 

sf::RectangleShape square32(sf::Vector2f(69,140));
square32.setOutlineThickness(3);
square32.setOutlineColor(sf::Color::Black);
sf::RectangleShape square33(sf::Vector2f(69,140));
square33.setOutlineThickness(3);
square33.setOutlineColor(sf::Color::Black);
sf::RectangleShape square34(sf::Vector2f(69,140));
square34.setOutlineThickness(3);
square34.setOutlineColor(sf::Color::Black);
sf::RectangleShape square35(sf::Vector2f(69,140));
square35.setOutlineThickness(3);
square35.setOutlineColor(sf::Color::Black);
sf::RectangleShape square36(sf::Vector2f(69,140));
square36.setOutlineThickness(3);
square36.setOutlineColor(sf::Color::Black);
sf::RectangleShape square37(sf::Vector2f(69,140));
square37.setOutlineThickness(3);
square37.setOutlineColor(sf::Color::Black);
sf::RectangleShape square38(sf::Vector2f(69,140));
square38.setOutlineThickness(3);
square38.setOutlineColor(sf::Color::Black);
sf::RectangleShape square39(sf::Vector2f(69,140));
square39.setOutlineThickness(3);
square39.setOutlineColor(sf::Color::Black);
sf::RectangleShape square40(sf::Vector2f(69,140));
square40.setOutlineThickness(3);
square40.setOutlineColor(sf::Color::Black);

// Create size of Community Chest and Chance & Outline + Color //
sf::RectangleShape communitychest(sf::Vector2f(69,140));
communitychest.setOutlineThickness(3);
communitychest.setOutlineColor(sf::Color::Black);
sf::RectangleShape chance(sf::Vector2f(69,140));
chance.setOutlineThickness(3);
chance.setOutlineColor(sf::Color::Black);

// Create size of colors of properties & Outline + Color //
sf::RectangleShape brown1(sf::Vector2f(66,25));
brown1.setOutlineThickness(3);
brown1.setOutlineColor(sf::Color::Black);
sf::RectangleShape brown2(sf::Vector2f(69,25));
brown2.setOutlineThickness(3);
brown2.setOutlineColor(sf::Color::Black);
sf::RectangleShape lblue1(sf::Vector2f(66,25));
lblue1.setOutlineThickness(3);
lblue1.setOutlineColor(sf::Color::Black);
sf::RectangleShape lblue2(sf::Vector2f(66,25));
lblue2.setOutlineThickness(3);
lblue2.setOutlineColor(sf::Color::Black);
sf::RectangleShape lblue3(sf::Vector2f(66,25));
lblue3.setOutlineThickness(3);
lblue3.setOutlineColor(sf::Color::Black);
sf::RectangleShape pink1(sf::Vector2f(66,25));
pink1.setOutlineThickness(3);
pink1.setOutlineColor(sf::Color::Black);
sf::RectangleShape pink2(sf::Vector2f(66,25));
pink2.setOutlineThickness(3);
pink2.setOutlineColor(sf::Color::Black);
sf::RectangleShape pink3(sf::Vector2f(66,25));
pink3.setOutlineThickness(3);
pink3.setOutlineColor(sf::Color::Black);
sf::RectangleShape orange1(sf::Vector2f(66,25));
orange1.setOutlineThickness(3);
orange1.setOutlineColor(sf::Color::Black);
sf::RectangleShape orange2(sf::Vector2f(66,25));
orange2.setOutlineThickness(3);
orange2.setOutlineColor(sf::Color::Black);
sf::RectangleShape orange3(sf::Vector2f(66,25));
orange3.setOutlineThickness(3);
orange3.setOutlineColor(sf::Color::Black);
sf::RectangleShape red1(sf::Vector2f(66,25));
red1.setOutlineThickness(3);
red1.setOutlineColor(sf::Color::Black);
sf::RectangleShape red2(sf::Vector2f(66,25));
red2.setOutlineThickness(3);
red2.setOutlineColor(sf::Color::Black);
sf::RectangleShape red3(sf::Vector2f(66,25));
red3.setOutlineThickness(3);
red3.setOutlineColor(sf::Color::Black);
sf::RectangleShape yellow1(sf::Vector2f(66,25));
yellow1.setOutlineThickness(3);
yellow1.setOutlineColor(sf::Color::Black);
sf::RectangleShape yellow2(sf::Vector2f(66,25));
yellow2.setOutlineThickness(3);
yellow2.setOutlineColor(sf::Color::Black);
sf::RectangleShape yellow3(sf::Vector2f(66,25));
yellow3.setOutlineThickness(3);
yellow3.setOutlineColor(sf::Color::Black);
sf::RectangleShape green1(sf::Vector2f(66,25));
green1.setOutlineThickness(3);
green1.setOutlineColor(sf::Color::Black);
sf::RectangleShape green2(sf::Vector2f(66,25));
green2.setOutlineThickness(3);
green2.setOutlineColor(sf::Color::Black);
sf::RectangleShape green3(sf::Vector2f(66,25));
green3.setOutlineThickness(3);
green3.setOutlineColor(sf::Color::Black);
sf::RectangleShape blue1(sf::Vector2f(66,25));
blue1.setOutlineThickness(3);
blue1.setOutlineColor(sf::Color::Black);
sf::RectangleShape blue2(sf::Vector2f(66,25));
blue2.setOutlineThickness(3);
blue2.setOutlineColor(sf::Color::Black);




// Rotate some Shapes // 
square12.setRotation(90);
square13.setRotation(90);
square14.setRotation(90);
square15.setRotation(90);
square16.setRotation(90);
square17.setRotation(90);
square18.setRotation(90);
square19.setRotation(90);
square20.setRotation(90);

square32.setRotation(90);
square33.setRotation(90);
square34.setRotation(90);
square35.setRotation(90);
square36.setRotation(90);
square37.setRotation(90);
square38.setRotation(90);
square39.setRotation(90);
square40.setRotation(90);

communitychest.setRotation(45);
chance.setRotation(45);

pink1.setRotation(90);
pink2.setRotation(90);
pink3.setRotation(90);
orange1.setRotation(90);
orange2.setRotation(90);
orange3.setRotation(90);
green1.setRotation(90);
green2.setRotation(90);
green3.setRotation(90);
blue1.setRotation(90);
blue2.setRotation(90);

sth.setRotation(90);
com.setRotation(90);
cas.setRotation(90);
sci.setRotation(90);
eng.setRotation(90);
pho.setRotation(90);
bueast.setRotation(90);
electric.setRotation(90);
buchapel.setRotation(180);
fitrec.setRotation(180);
bubeach.setRotation(180);
baystateroad.setRotation(180);
southcamp.setRotation(180);
stuvi1.setRotation(180);
bucentral.setRotation(180);
buboathouse.setRotation(180);
marciano.setRotation(270);
kilachand.setRotation(270);
questrom.setRotation(270);
myleshall.setRotation(270);
stuvi2.setRotation(270);
buwest.setRotation(270);

go.setRotation(-45);
jail.setRotation(45);
free.setRotation(135);
gto.setRotation(-135);
commchest2.setRotation(90);
commchest3.setRotation(270);
chancee2.setRotation(180);
chancee3.setRotation(270);
luxurytax.setRotation(270);
bumono.setRotation(-45);

// Colors of shapes // 
square1.setFillColor(sf::Color::White);  // Top Left
square2.setFillColor(sf::Color::White);
square3.setFillColor(sf::Color::White);
square4.setFillColor(sf::Color::White);
square5.setFillColor(sf::Color::White);
square6.setFillColor(sf::Color::White);
square7.setFillColor(sf::Color::White);
square8.setFillColor(sf::Color::White);
square9.setFillColor(sf::Color::White);
square10.setFillColor(sf::Color::White);
square11.setFillColor(sf::Color::White);  // Top Right

square12.setFillColor(sf::Color::White);
square13.setFillColor(sf::Color::White);
square14.setFillColor(sf::Color::White);
square15.setFillColor(sf::Color::White);
square16.setFillColor(sf::Color::White);
square17.setFillColor(sf::Color::White);
square18.setFillColor(sf::Color::White);
square19.setFillColor(sf::Color::White);
square20.setFillColor(sf::Color::White);
square21.setFillColor(sf::Color::White);  // Bottom Right

square22.setFillColor(sf::Color::White);
square23.setFillColor(sf::Color::White);
square24.setFillColor(sf::Color::White);
square25.setFillColor(sf::Color::White);
square26.setFillColor(sf::Color::White);
square27.setFillColor(sf::Color::White);
square28.setFillColor(sf::Color::White);
square29.setFillColor(sf::Color::White);
square30.setFillColor(sf::Color::White);
square31.setFillColor(sf::Color::White);  // Bottom Left

square32.setFillColor(sf::Color::White);
square33.setFillColor(sf::Color::White);
square34.setFillColor(sf::Color::White);
square35.setFillColor(sf::Color::White);
square36.setFillColor(sf::Color::White);
square37.setFillColor(sf::Color::White);
square38.setFillColor(sf::Color::White);
square39.setFillColor(sf::Color::White);
square40.setFillColor(sf::Color::White); 

communitychest.setFillColor(sf::Color::Blue);
chance.setFillColor(sf::Color(250,150,100));

brown1.setFillColor(sf::Color(165,42,42));
brown2.setFillColor(sf::Color(165,42,42));
lblue1.setFillColor(sf::Color(113,93,254));
lblue2.setFillColor(sf::Color(113,93,254));
lblue3.setFillColor(sf::Color(113,93,254));
pink1.setFillColor(sf::Color(255,192,203));
pink2.setFillColor(sf::Color(255,192,203));
pink3.setFillColor(sf::Color(255,192,203));
orange1.setFillColor(sf::Color(250,150,100));
orange2.setFillColor(sf::Color(250,150,100));
orange3.setFillColor(sf::Color(250,150,100));
red1.setFillColor(sf::Color::Red);
red2.setFillColor(sf::Color::Red);
red3.setFillColor(sf::Color::Red);
yellow1.setFillColor(sf::Color::Yellow);
yellow2.setFillColor(sf::Color::Yellow);
yellow3.setFillColor(sf::Color::Yellow);
green1.setFillColor(sf::Color::Green);
green2.setFillColor(sf::Color::Green);
green3.setFillColor(sf::Color::Green);
blue1.setFillColor(sf::Color::Blue);
blue2.setFillColor(sf::Color::Blue);


// Position of board pieces + scale //
shuttle.setScale(0.02,0.06);
terrier.setScale(0.05,0.05);
seal.setScale(0.04,0.04);
president.setScale(0.02,0.02);
shuttle.setPosition(790,780);
terrier.setPosition(850,780);
seal.setPosition(790,860);
president.setPosition(850,860);

// Position of shapes on window // 
square1.setPosition(0,0);  // Top Left
square2.setPosition(140,0);
square3.setPosition(209,0);
square4.setPosition(278,0);
square5.setPosition(347,0);
square6.setPosition(416,0);
square7.setPosition(485,0);
square8.setPosition(554,0);
square9.setPosition(623,0);
square10.setPosition(692,0);
square11.setPosition(761,0);  // Top Right

square12.setPosition(900,140);
square13.setPosition(900,209);
square14.setPosition(900,278);
square15.setPosition(900,347);
square16.setPosition(900,416);
square17.setPosition(900,485);
square18.setPosition(900,554);
square19.setPosition(900,623);
square20.setPosition(900,692);
square21.setPosition(760,760);  // Bottom  Right

square22.setPosition(691,760); 
square23.setPosition(622,760);
square24.setPosition(553,760);
square25.setPosition(484,760);
square26.setPosition(415,760);
square27.setPosition(346,760);
square28.setPosition(277,760);
square29.setPosition(208,760);
square30.setPosition(139,760);
square31.setPosition(0,760);  // Bottom Left

square32.setPosition(140,692);
square33.setPosition(140,623);
square34.setPosition(140,554);
square35.setPosition(140,485);
square36.setPosition(140,416);
square37.setPosition(140,347);
square38.setPosition(140,278);
square39.setPosition(140,209);
square40.setPosition(140,140);

communitychest.setPosition(300, 210);
chance.setPosition(660,560);

brown1.setPosition(694,760);
brown2.setPosition(555,760);
lblue1.setPosition(349,760);
lblue2.setPosition(211,760);
lblue3.setPosition(142,760);
pink1.setPosition(140,695);
pink2.setPosition(140,557);
pink3.setPosition(140,488);
orange1.setPosition(140,350);
orange2.setPosition(140,212);
orange3.setPosition(140,141);
red1.setPosition(140,115);
red2.setPosition(278,115);
red3.setPosition(347,115);
yellow1.setPosition(485,115);
yellow2.setPosition(554,115);
yellow3.setPosition(692,115);
green1.setPosition(785,140);
green2.setPosition(785,209);
green3.setPosition(785, 347);
blue1.setPosition(785,554);
blue2.setPosition(785, 691);

hojo.setPosition(700,800);
towers.setPosition(558,800);
warren.setPosition(353,800);
westcamp.setPosition(216,800);
cgs.setPosition(149,800);
sth.setPosition(110,701);
com.setPosition(110,563);
cas.setPosition(110,494);
sci.setPosition(110,356);
eng.setPosition(110,218);
pho.setPosition(110,149);
buchapel.setPosition(200,106);
fitrec.setPosition(340,106);
bubeach.setPosition(410,106);
baystateroad.setPosition(610,106);
southcamp.setPosition(545,106);
stuvi1.setPosition(758,106);
marciano.setPosition(790,204);
kilachand.setPosition(790,273);
questrom.setPosition(790,414);
myleshall.setPosition(790,618);
stuvi2.setPosition(790,750);
blanford.setPosition(420,800);
bueast.setPosition(110,425);
bucentral.setPosition(480,106);
buwest.setPosition(790,480);
electric.setPosition(130,632);
buboathouse.setPosition(689,106);

chancee1.setPosition(283,800);
chancee2.setPosition(270,106);
chancee3.setPosition(790, 550);
commchest1.setPosition(625,800);
commchest2.setPosition(110, 285);
commchest3.setPosition(790,345);
gto.setPosition(830,100);
free.setPosition(120,70);
jail.setPosition(80,800);
go.setPosition(790,820);
luxurytax.setPosition(790,685);
incometax.setPosition(490,800);
bumono.setPosition(240,580);





while (window.isOpen())
{
  sf::Event event;
  while (window.pollEvent(event))
  {
    if (event.type == sf::Event::Closed)
      window.close();
    // If statement below is used for User input: if key R onkeyboard is for roll dice
    // call diceroll() from dice.cpp header (dice.h)]
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::R){

    // userinput == 2 means if this is a 2 player game // 
      if (userinput == 2){
      moveTracker++;
      if (moveTracker == 1){
      sealinfo = printPosition(sealinitialPos, sealinitialBalance);  // returns {position, balance}
      sealinitialPos = sealinfo.at(0);
      sealinitialBalance = sealinfo.at(1);
      cccout = cccards(sealinitialPos, sealinitialBalance);  // check if we landed on a chance or cc card
      sealinitialPos = cccout.at(0);  // return update position and balance below
      sealinitialBalance = cccout.at(1);
      jailout = jaill(sealWaitJailCounter, sealinitialPos, sealinitialBalance, sealJailCardBalance);  // checks if we're in jail
      sealWaitJailCounter = jailout.at(0);
      sealinitialPos = jailout.at(1);
      sealinitialBalance = jailout.at(2);
      sealJailCardBalance = jailout.at(3);
      if (sealinitialBalance < 0) {  // checks if seal is bankrupt
        cout << "!!!!!     TERRIER IS THE WINNER     !!!!!\n";
        return 0;
      }
       cout <<"************************************************TERRIER'S TURN************************************************\n";
      xy = coordinate(sealinitialPos);  
      seal.setPosition(xy.at(0), xy.at(1));  // use most recent position to move seal to right place
      window.draw(seal);
      }
      if (moveTracker == 2){
        moveTracker = 0;
        terrierinfo = printPosition(terrierinitialPos, terrierinitialBalance);  // returns {position, balance}
        terrierinitialPos = terrierinfo.at(0);
        terrierinitialBalance = terrierinfo.at(1);
        cccout = cccards(terrierinitialPos, terrierinitialBalance);  // check if we landed on a chance or cc card
        terrierinitialPos = cccout.at(0);
        terrierinitialBalance = cccout.at(1);
        jailout = jaill(terrierWaitJailCounter, terrierinitialPos, terrierinitialBalance, terrierJailCardBalance);  // checks is we're in jail
        terrierWaitJailCounter = jailout.at(0);
        terrierinitialPos = jailout.at(1);
        terrierinitialBalance = jailout.at(2);
        terrierJailCardBalance = jailout.at(3);
        if (terrierinitialBalance < 0) {
          cout << "!!!!!     SEAL IS THE WINNER     !!!!!\n";
          return 0;
        }
        cout << "************************************************SEAL'S TURN************************************************\n";
        xy = coordinate(terrierinitialPos);
        terrier.setPosition(xy.at(0), xy.at(1));  // use most recent position to move terrier to right place
        window.draw(terrier);
        }}

// if udername == 3 means if this is a 3 player game
    if (userinput == 3){
        moveTracker++;
        int pos;
        int tokenSUM = sealSkipToken + presidentSkipToken + terrierSkipToken;
        cout << "************************************************SEAL'S TURN************************************************\n";
        if (moveTracker == 1 && sealSkipToken == 0){
        sealinfo = printPosition(sealinitialPos, sealinitialBalance);
        sealinitialPos = sealinfo.at(0);
        sealinitialBalance = sealinfo.at(1);
        cccout = cccards(sealinitialPos, sealinitialBalance);
        sealinitialPos = cccout.at(0);
        sealinitialBalance = cccout.at(1);
        jailout = jaill(sealWaitJailCounter, sealinitialPos, sealinitialBalance, sealJailCardBalance);
        sealWaitJailCounter = jailout.at(0);
        sealinitialPos = jailout.at(1);
        sealinitialBalance = jailout.at(2);
        sealJailCardBalance = jailout.at(3);
        if (sealinitialBalance < 0){
          sealSkipToken = 1;
          cout << "!!!!! SEAL IS OUT     !!!!!\n";
        }
        cout <<"************************************************TERRIER'S TURN************************************************\n";
        xy = coordinate(sealinitialPos);
        seal.setPosition(xy.at(0), xy.at(1));
        window.draw(seal);
      }else if (moveTracker == 1 && sealSkipToken == 1){  // else statement skips seal's turn and moves to next player
        moveTracker = 2;
      }
        if (moveTracker == 2 && terrierSkipToken == 0){
         terrierinfo = printPosition(terrierinitialPos, terrierinitialBalance);  
         terrierinitialPos = terrierinfo.at(0); 
         terrierinitialBalance = terrierinfo.at(1);
         cccout = cccards(terrierinitialPos, terrierinitialBalance);
          terrierinitialPos = cccout.at(0);
          terrierinitialBalance = cccout.at(1);
          jailout = jaill(terrierWaitJailCounter, terrierinitialPos, terrierinitialBalance, terrierJailCardBalance);
          terrierWaitJailCounter = jailout.at(0);
          terrierinitialPos = jailout.at(1);
          terrierinitialBalance = jailout.at(2);
          terrierJailCardBalance = jailout.at(3);
         if (terrierinitialBalance < 0){
           terrierSkipToken = 1;
          cout << "!!!!!     TERRIER IS OUT     !!!!!\n";
         }
         cout <<"************************************************PRESIDENT BROWN'S TURN************************************************\n";
        xy = coordinate(terrierinitialPos);
        terrier.setPosition(xy.at(0), xy.at(1));
        window.draw(terrier);
      }else if (moveTracker == 2 && terrierSkipToken == 1){  // else statement skips terrier and moves to next player
        moveTracker = 3;
      }
      
      if (moveTracker == 3 && presidentSkipToken == 0){
        moveTracker = 0;
        presidentinfo = printPosition(presidentinitialPos, presidentinitialBalance);
        presidentinitialPos = presidentinfo.at(0);
        presidentinitialBalance = presidentinfo.at(1);
        cccout = cccards(presidentinitialPos, presidentinitialBalance);
        presidentinitialPos = cccout.at(0);
        presidentinitialBalance = cccout.at(1);
        jailout = jaill(presidentWaitJailCounter, presidentinitialPos, presidentinitialBalance, presidentJailCardBalance);
        presidentWaitJailCounter = jailout.at(0);
        presidentinitialPos = jailout.at(1);
        presidentinitialBalance = jailout.at(2);
        presidentJailCardBalance = jailout.at(3);
        if (presidentinitialBalance < 0){
          presidentSkipToken = 1;
          cout << "!!!!!     PRESIDENT BROWN IS OUT     !!!!!\n";
        }
        cout <<"************************************************SEAL'S TURN************************************************\n";
        xy = coordinate(presidentinitialPos);
        president.setPosition(xy.at(0), xy.at(1));
        window.draw(president);
      }else if (moveTracker == 3 && presidentSkipToken == 1){  // else statement skips president and moves to next plater
        moveTracker = 0;
      }
      // code below checks winning states based on SKIP TOKEN counts // 
      if (tokenSUM == 2){
        if (sealSkipToken == 1 && terrierSkipToken == 1){
          cout << "!!!!!     PRESIDENT BROWN IS THE WINNER     !!!!!\n";
          return 0;
        }
        if (terrierSkipToken == 1 && presidentSkipToken == 1){
          cout << "!!!!!     SEAL IS THE WINNER     !!!!!\n";
          return 0;
        }
        if (sealSkipToken == 1 && presidentSkipToken == 1){
          cout << "!!!!!     TERRIER IS THE WINNER     !!!!!\n";
          return 0;
        }
      }
      }

// if user input == 4 means if this is a 4 player game // 
    if (userinput == 4){
        moveTracker++;
        int tokenSUM = sealSkipToken + presidentSkipToken + terrierSkipToken + shuttleSkipToken;  // check how many players are out of the game
        if (moveTracker == 1 && sealSkipToken == 0){
        sealinfo = printPosition(sealinitialPos, sealinitialBalance);  // rolls dice and return new position
        sealinitialPos = sealinfo.at(0);
        sealinitialBalance = sealinfo.at(1);
        cccout = cccards(sealinitialPos, sealinitialBalance);
        sealinitialPos = cccout.at(0);
        sealinitialBalance = cccout.at(1);
        jailout = jaill(sealWaitJailCounter, sealinitialPos, sealinitialBalance, sealJailCardBalance);
        sealWaitJailCounter = jailout.at(0);
        sealinitialPos = jailout.at(1);
        sealinitialBalance = jailout.at(2);
        sealJailCardBalance = jailout.at(3);
        if (sealinitialBalance < 0){
          sealSkipToken = 1;
          cout << "!!!!! SEAL IS OUT     !!!!!\n";
        }
        cout <<"************************************************TERRIER'S TURN************************************************\n";
        xy = coordinate(sealinitialPos);
        seal.setPosition(xy.at(0), xy.at(1));
        window.draw(seal);
      }else if (moveTracker == 1 && sealSkipToken == 1){  // else statement skips seal's turn and moves to next player
        moveTracker = 2;
      }
        if (moveTracker == 2 && terrierSkipToken == 0){
         terrierinfo = printPosition(terrierinitialPos, terrierinitialBalance);  // rolls dice and return new position  
         terrierinitialPos = terrierinfo.at(0); 
         terrierinitialBalance = terrierinfo.at(1);
         cccout = cccards(terrierinitialPos, terrierinitialBalance);
          terrierinitialPos = cccout.at(0);
          terrierinitialBalance = cccout.at(1);
          jailout = jaill(terrierWaitJailCounter, terrierinitialPos, terrierinitialBalance, terrierJailCardBalance);
          terrierWaitJailCounter = jailout.at(0);
          terrierinitialPos = jailout.at(1);
          terrierinitialBalance = jailout.at(2);
          terrierJailCardBalance = jailout.at(3);
         if (terrierinitialBalance < 0){
           terrierSkipToken = 1;
          cout << "!!!!!     TERRIER IS OUT     !!!!!\n";
         }
         cout <<"************************************************PRESIDENT BROWN'S TURN************************************************\n";
        xy = coordinate(terrierinitialPos);
        terrier.setPosition(xy.at(0), xy.at(1));
        window.draw(terrier);
      }else if (moveTracker == 2 && terrierSkipToken == 1){  // else statement skips terrier and moves to next player
        moveTracker = 3;
      }
      
      if (moveTracker == 3 && presidentSkipToken == 0){

        presidentinfo = printPosition(presidentinitialPos, presidentinitialBalance);  // rolls dice and return new position
        presidentinitialPos = presidentinfo.at(0);
        presidentinitialBalance = presidentinfo.at(1);
        cccout = cccards(presidentinitialPos, presidentinitialBalance);
        presidentinitialPos = cccout.at(0);
        presidentinitialBalance = cccout.at(1);
        jailout = jaill(presidentWaitJailCounter, presidentinitialPos, presidentinitialBalance, presidentJailCardBalance);
        presidentWaitJailCounter = jailout.at(0);
        presidentinitialPos = jailout.at(1);
        presidentinitialBalance = jailout.at(2);
        presidentJailCardBalance = jailout.at(3);
        if (presidentinitialBalance < 0){
          presidentSkipToken = 1;
          cout << "!!!!!     PRESIDENT BROWN IS OUT     !!!!!\n";
        }
        cout <<"************************************************SHUTTLE'S TURN************************************************\n";
        xy = coordinate(presidentinitialPos);
        president.setPosition(xy.at(0), xy.at(1));
        window.draw(president);
      }else if (moveTracker == 3 && presidentSkipToken == 1){  // else statement skips president and moves to next player
        moveTracker = 0;
      }
      if (moveTracker == 4 && shuttleSkipToken == 0){
        moveTracker = 0;
        shuttleinfo = printPosition(shuttleinitialPos, shuttleinitialBalance);  // rolls dice and return new position
        shuttleinitialPos = shuttleinfo.at(0);
        shuttleinitialBalance = shuttleinfo.at(1);
        jailout = jaill(shuttleWaitJailCounter, shuttleinitialPos, shuttleinitialBalance, shuttleJailCardBalance);
        shuttleWaitJailCounter = jailout.at(0);
        shuttleinitialPos = jailout.at(1);
        shuttleinitialBalance = jailout.at(2);
        shuttleJailCardBalance = jailout.at(3);
        if (shuttleinitialBalance < 0){
          shuttleSkipToken = 1;
          cout << "!!!!!     BU SHUTTLE IS OUT     !!!!!\n";
        }
        cout <<"************************************************SEAL'S TURN************************************************\n";
        xy = coordinate(shuttleinitialPos);
        shuttle.setPosition(xy.at(0), xy.at(1));
        window.draw(shuttle);
        }
      // code below checks winning states based on SKIP TOKEN counts // 
      if (tokenSUM == 3){
        if (sealSkipToken == 1 && terrierSkipToken == 1 && shuttleSkipToken == 1){
          cout << "!!!!!     PRESIDENT BROWN IS THE WINNER     !!!!!\n";
          return 0;
        }
        if (terrierSkipToken == 1 && presidentSkipToken == 1 && shuttleSkipToken == 1){
          cout << "!!!!!     SEAL IS THE WINNER     !!!!!\n";
          return 0;
        }
        if (sealSkipToken == 1 && presidentSkipToken == 1 && shuttleSkipToken == 1){
          cout << "!!!!!     TERRIER IS THE WINNER     !!!!!\n";
          return 0;
        }
        if (sealSkipToken == 1 && presidentSkipToken == 1 && terrierSkipToken == 1){
          cout << "!!!!!     SHUTTLE IS THE WINNER     !!!!!\n";
          return 0;
        }
      }
      }
    

    }
    }

    // Draw the elements to create monoploy on window // 
    window.draw(monopolyboard);
    window.draw(square1);
    window.draw(square2);
    window.draw(square3);
    window.draw(square4);
    window.draw(square5);
    window.draw(square6);
    window.draw(square7);
    window.draw(square8);
    window.draw(square9);
    window.draw(square10);
    window.draw(square11);
    window.draw(square12);
    window.draw(square13);
    window.draw(square14);
    window.draw(square15);
    window.draw(square16);
    window.draw(square17);
    window.draw(square18);
    window.draw(square19);
    window.draw(square20);
    window.draw(square21);
    window.draw(square22);
    window.draw(square23);
    window.draw(square24);
    window.draw(square25);
    window.draw(square26);
    window.draw(square27);
    window.draw(square28);
    window.draw(square29);
    window.draw(square30);
    window.draw(square31);
    window.draw(square32);
    window.draw(square33);
    window.draw(square34);
    window.draw(square35);
    window.draw(square36);
    window.draw(square37);
    window.draw(square38);
    window.draw(square39);
    window.draw(square40);
    window.draw(communitychest);
    window.draw(chance);
    window.draw(brown1);
    window.draw(brown2);
    window.draw(lblue1);
    window.draw(lblue2);
    window.draw(lblue3);
    window.draw(pink1);
    window.draw(pink2);
    window.draw(pink3);
    window.draw(orange1);
    window.draw(orange2);
    window.draw(orange3);
    window.draw(red1);
    window.draw(red2);
    window.draw(red3);
    window.draw(yellow1);
    window.draw(yellow2);
    window.draw(yellow3);
    window.draw(green1);
    window.draw(green2);
    window.draw(green3);
    window.draw(blue1);
    window.draw(blue2);
    window.draw(hojo);
    window.draw(towers);
    window.draw(warren);
    window.draw(westcamp);
    window.draw(cgs);
    window.draw(sth);
    window.draw(com);
    window.draw(cas);
    window.draw(sci);
    window.draw(eng);
    window.draw(pho);
    window.draw(buchapel);
    window.draw(fitrec);
    window.draw(bubeach);
    window.draw(baystateroad);
    window.draw(southcamp);
    window.draw(stuvi1);
    window.draw(marciano);
    window.draw(kilachand);
    window.draw(questrom);
    window.draw(myleshall);
    window.draw(stuvi2);
    window.draw(bueast);
    window.draw(blanford);
    window.draw(bucentral);
    window.draw(buwest);
    window.draw(electric);
    window.draw(buboathouse);
    window.draw(chancee1);
    window.draw(chancee2);
    window.draw(chancee3);
    window.draw(commchest1);
    window.draw(commchest2);
    window.draw(commchest3);
    window.draw(gto);
    window.draw(go);
    window.draw(free);
    window.draw(jail);
    window.draw(luxurytax);
    window.draw(incometax);
    window.draw(bumono);
    // code below initializes pieces based on user input number of players //
    if (userinput <= 1 || userinput > 4){
      return 1;
    }
    if (userinput == 2){
      window.draw(seal);
      window.draw(terrier);
    }
    if (userinput == 3){
        window.draw(terrier);
        window.draw(seal);
        window.draw(president);
    }
    if (userinput == 4){
        window.draw(shuttle);
        window.draw(terrier);
        window.draw(seal);
        window.draw(president);
    }

    window.display();
  }

    return 0;
}
