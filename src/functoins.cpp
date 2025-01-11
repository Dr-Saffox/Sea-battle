// Sea Battle for 2 players
// Created by Saffox (from school years)

#include <iostream>
#include "head.h"

void ClearScreen( )  {
  HANDLE                     hStdOut;
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  DWORD                      count;
  DWORD                      cellCount;
  COORD                      homeCoords = { 0, 0 };

  hStdOut = GetStdHandle( STD_OUTPUT_HANDLE );
  if (hStdOut == INVALID_HANDLE_VALUE) return;

  /* Get the number of cells in the current buffer */
  if (!GetConsoleScreenBufferInfo( hStdOut, &csbi )) return;
  cellCount = csbi.dwSize.X *csbi.dwSize.Y;

  /* Fill the entire buffer with spaces */
  if (!FillConsoleOutputCharacter(
    hStdOut,
    (TCHAR) ' ',
    cellCount,
    homeCoords,
    &count
    )) return;

  /* Fill the entire buffer with the current colors and attributes */
  if (!FillConsoleOutputAttribute(
    hStdOut,
    csbi.wAttributes,
    cellCount,
    homeCoords,
    &count
    )) return;

  /* Move the cursor home */
  SetConsoleCursorPosition( hStdOut, homeCoords );
  }

void SetColor( int text, int background )  {
        HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

void show( string table1[21][21], string table2[21][21], int table_1[21][21], int table_2[21][21] ) {
string alfabet="    A B C D E F G H I J           A B C D E F G H I J   ";
 string Player="     pole for PLAYER 1             pole for PLAYER 2    ";
SetColor(0,15);
cout<<Player;
cout<<endl<<alfabet<<endl;
int q=1; // for number

for(short i=0; i<21; ++i)
{
    if(i%2!=0)
    { if(q<10)
      {SetColor(15,15); cout<<" ";
       SetColor(0,15); cout<<q;
       SetColor(15,15); cout<<" ";}
      else
      {SetColor(0,15); cout<<q;
       SetColor(15,15); cout<<" ";}
    }
    else {SetColor(15,15); cout<<"  ";
          SetColor(15,15); cout<<" ";}

  for(short j=0; j<21; ++j)
  {
      if(table_1[i][j] == 3) {SetColor(12,9); cout<<table1[i][j];} // 3 - ÏÎÏÀÄÀÍÈÅ
 else if(table_1[i][j] == 4) {SetColor(15,9); cout<<table1[i][j];} // 4 - ÏÐÎÌÀÕ
 else {SetColor(0,9); cout<<table1[i][j];}
  }

  if(i%2!=0)
  { if(q<10)
    {SetColor(15,15); cout<<"       ";
     SetColor(0,15); cout<<q;
     SetColor(15,15); cout<<" ";}
    else
    {SetColor(15,15); cout<<"      ";
     SetColor(0,15); cout<<q;
     SetColor(15,15); cout<<" ";}
    q++;
  }
  else {SetColor(15,15); cout<<"         ";}

  for(short j=0; j<21; ++j)
  {
      if(table_2[i][j] == 3) {SetColor(12,9); cout<<table2[i][j];} // 3 - ÏÎÏÀÄÀÍÈÅ
 else if(table_2[i][j] == 4) {SetColor(15,9); cout<<table2[i][j];} // 4 - ÏÐÎÌÀÕ
 else {SetColor(0,9); cout<<table2[i][j];}
  }

   SetColor(15,15);
   cout<<"  "<<endl;
}
SetColor(15,0);
cout<<endl;
}

void start_tables( string table1[21][21], string table2[21][21], int table_1[21][21], int table_2[21][21] ) {

for(short i=0; i<21; ++i)
{ for(short j=0; j<21; ++j)
  {
    if(i%2!=0 && j%2!=0)
    {table_1[i][j] = 0;
     table_2[i][j] = 0;}
    else
    {table_1[i][j] = 1;
     table_2[i][j] = 1;}
  }
}


for(short i=0; i<21; ++i)
{for(short j=0; j<21; ++j)
 {   if(i%2==0 && j%2==0)
     {table1[i][j] = char(197);
      table2[i][j] = char(197);}
else if(i%2!=0 && j%2!=0)
     {table1[i][j] = ' ';
      table2[i][j] = ' ';}
else if(i%2==0 && j%2!=0)
     {table1[i][j] = char(196);
      table2[i][j] = char(196);}
else
     {table1[i][j] = char(179);
      table2[i][j] = char(179);}
 }
}
}

void show_for_start ( string table[21][21], int tablee[21][21] ) {
string alfabet="    A B C D E F G H I J   ";
SetColor(0,15);
cout<<endl<<alfabet<<endl;
int q=1; // for number

for(short i=0; i<21; ++i)
{
    if(i%2!=0)
    { if(q<10)
      {SetColor(15,15); cout<<" ";
       SetColor(0,15); cout<<q; q++;
       SetColor(15,15); cout<<" ";}
      else
      {SetColor(0,15); cout<<q; q++;
       SetColor(15,15); cout<<" ";}
    }
    else {SetColor(15,15); cout<<"  ";
          SetColor(15,15); cout<<" ";}

  for(short j=0; j<21; ++j)
  {
      if(tablee[i][j] == 3)
      {SetColor(4,9); cout<<table[i][j];}
      else
      {SetColor(0,9); cout<<table[i][j];}

  }
SetColor(15,15);
cout<<"  "<<endl;
}
SetColor(15,0);
}

void clean_tables ( string table1[21][21], string table2[21][21] ) {
for(short i=0; i<21; ++i)
{for(short j=0; j<21; ++j)
 {   if(i%2==0 && j%2==0)
     {table1[i][j] = char(197);
      table2[i][j] = char(197);}
else if(i%2!=0 && j%2!=0)
     {table1[i][j] = ' ';
      table2[i][j] = ' ';}
else if(i%2==0 && j%2!=0)
     {table1[i][j] = char(196);
      table2[i][j] = char(196);}
else
     {table1[i][j] = char(179);
      table2[i][j] = char(179);}
 }
}
}

void show_bool ( int table_1[21][21], int table_2[21][21] ) { // background ships tables player1 and player2

string alfabet="    A B C D E F G H I J       ";
cout<<alfabet<<alfabet<<endl;
int q=1; // for numbers
for(short i=0; i<21; ++i)
{
    if(i%2!=0)
    { if(q<10) {cout<<" "<<q<<" ";}
      else {cout<<q<<" ";}
    }
    else {cout<<"   ";}


  for(short j=0; j<21; ++j)
  {cout<<table_1[i][j];}

 if(i%2!=0)
  { if(q<10) {cout<<"       "<<q<<" ";}
    else {cout<<"      "<<q<<" ";}
    q++;
  }
  else {cout<<"         ";}


  for(short j=0; j<21; ++j)
  {cout<<table_2[i][j];}

cout<<endl;
}

}

string get_x ( string in ) {

string str="";
str = in.substr(0, 1);
     if (str[0] == 'A') {str = "1";}
else if (str[0] == 'B') {str = "3";}
else if (str[0] == 'C') {str = "5";}
else if (str[0] == 'D') {str = "7";}
else if (str[0] == 'E') {str = "9";}
else if (str[0] == 'F') {str = "11";}
else if (str[0] == 'G') {str = "13";}
else if (str[0] == 'H') {str = "15";}
else if (str[0] == 'I') {str = "17";}
else if (str[0] == 'J') {str = "19";}

return str;
}

string get_y ( string in ) {

string str="";
str = in.substr(1, in.length()-1);

return str;
}

int is_alive1 ( int alive1, int table_1[21][21] ) {
int q=0; // for "BOOL"
for(short i=0; i<21; ++i)
{for(short j=0; j<21; ++j)
 {
    if(table_1[i][j] == 2) {q++;}
 }
}

if(q==0) {alive1 = 1;}
else {alive1 = 0;}

return alive1;
}

int is_alive2 ( int alive2, int table_2[21][21] ) {
int q=0;// for "BOOL"
for(short i=0; i<21; ++i)
{for(short j=0; j<21; ++j)
 {
    if(table_2[i][j] == 2) {q++;}
 }
}

if(q==0) {alive2 = 1;}
else {alive2 = 0;}

return alive2;
}

void conditions ( short x, short y, int tablee[21][21], string table[21][21] ) {
tablee[y][x] = 2;
table[y][x] = char(249);
}

void game_over ( string table1[21][21], string table2[21][21], int table_1[21][21], int table_2[21][21] ) {

for(short i=0; i<21; ++i)
{for(short j=0; j<21; ++j)
 {
     if(table_1[i][j] == 2) {table_1[i][j] = 3; table1[i][j] = char(249);}
     if(table_2[i][j] == 2) {table_2[i][j] = 3; table2[i][j] = char(249);}
 }
}

}
