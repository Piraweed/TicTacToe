#ifndef TICTACTOE_H
#define TICTACTOE_H

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include <unistd.h>
 
void display_party(char cases[9]);
void player_trun(char simbol, char cases[9]);
int no_cheat(int choice, char cases[9]);
void bot_player(char simbol, char cases[9]);
int check_win(char simbols[2], char cases[9]);
void run_party(char simbol1, char simbol2);
void display_result(char simbols[2], char cases[9]);

#endif //TICTACTOE_H