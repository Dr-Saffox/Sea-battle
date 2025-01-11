// Sea Battle for 2 players
// Created by Saffox (from school years)

#ifndef HEAD_H_INCLUDED
#define HEAD_H_INCLUDED

#include <iostream>
#include <Windows.h>
#include <bits/stdc++.h>

using namespace std;

void ClearScreen( );
void SetColor( int text, int background );
void show( string table1[21][21], string table2[21][21], int table_1[21][21], int table_2[21][21] );
void start_tables( string table1[21][21], string table2[21][21], int table_1[21][21], int table_2[21][21] );
void show_for_start ( string table[21][21], int tablee[21][21] );
void clean_tables ( string table1[21][21], string table2[21][21] );
void show_bool ( int table_1[21][21], int table_2[21][21] );
string get_x ( string in );
string get_y ( string in );
int is_alive1 ( int alive1, int table_1[21][21] );
int is_alive2 ( int alive2, int table_2[21][21] );
void game_over ( string table1[21][21], string table2[21][21], int table_1[21][21], int table_2[21][21] );
void conditions ( short x, short y, int tablee[21][21], string table[21][21] );

#endif // HEAD_H_INCLUDED
