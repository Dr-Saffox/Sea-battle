// Sea Battle for 2 players
// Created by Saffox (from school years)

#include <iostream>
#include "functoins.cpp"
#include "head.h"

using namespace std;

int main()
{short x=0,y=0, n=20;    // input
string in="", str="";//  by PLEER
bool flag = true;   // for 1 <-> 2

string table1[21][21];
string table2[21][21];
int table_1[21][21];
int table_2[21][21];

int alive1 = 0; // for end game
int alive2 = 0; // 1 -> you lose

start_tables(table1, table2, table_1, table_2);

while (n>0)
{   show_for_start(table2, table_2);
//////////////////////////////////
cout<<"Player 1 enter coordinate (left - "<<n<<"): ";
cin>>in;
str = get_x( in );        // for X
x = atoi(str.c_str());

str = get_y( in );
y = atoi(str.c_str());    // for Y
y = y + y - 1;
//////////////////////////////////
    conditions(x,y,table_2,table2);
    ClearScreen();
n--;
}

n=20;
while (n>0)
{   show_for_start(table1, table_1);
////////////////////////////////////
cout<<"Player 2 enter coordinate (left - "<<n<<"): ";
cin>>in;
str = get_x( in );        // for X
x = atoi(str.c_str());

str = get_y( in );
y = atoi(str.c_str());    // for Y
y = y + y - 1;
/////////////////////////////////////
    conditions(x,y,table_1,table1);
    ClearScreen();
n--;
}

n=0;
clean_tables(table1, table2);
while (n<500)
{
    ClearScreen();
    show(table1, table2, table_1, table_2);
    //show_bool(table_1, table_2); // Background for "pole"

    if(n%2==0) {cout<<"HOD player1: ";}
    else {cout<<"HOD player2: ";}

////////////////////////////////////
cin>>in;
str = get_x( in );        // for X
x = atoi(str.c_str());

str = get_y( in );
y = atoi(str.c_str());    // for Y
y = y + y - 1;
////////////////////////////////////

    if(n%2==0)  {if(table_1[y][x] == 2) {table_1[y][x] = 3; flag = false;}
                 else {table_1[y][x] = 4; flag = true;}                         // hit p1
                 table1[y][x] = char(249);}

    else  {if(table_2[y][x] == 2) {table_2[y][x] = 3; flag = false;}
           else {table_2[y][x] = 4; flag = true;}                              // hit p2
           table2[y][x] = char(249);}


    if(flag == true) {n++;} // for 1 <-> 2


    alive1 = is_alive1(alive1,table_1);
    alive2 = is_alive2(alive2,table_2);

   if(alive1 == 1)
   {ClearScreen();  // clean console
    game_over(table1,table2,table_1,table_2);
    show(table1, table2, table_1, table_2);
    cout<<"Player 1 is lose. Game over."<<endl;
    return 0;}
   if(alive2 == 1)
   {ClearScreen();  // clean console
    game_over(table1,table2,table_1,table_2);
    show(table1, table2, table_1, table_2);
    cout<<"Player 2 is lose. Game over."<<endl;
    return 0;}
}
}
