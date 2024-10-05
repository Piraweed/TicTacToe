#include "tic-tac-toe.h"

int victory_condition[7][3] = {
   {0, 1, 2},
   {0, 3, 6},
   {0, 4, 8},
   {1, 4, 7},
   {3, 4, 5},
   {2, 5, 8},
   {6, 7, 8}
};

void display_result(char simbols[2], char cases[9]){
   int winer = check_win(simbols, cases);
   if(winer!= 0){
      printf("VICTOIRE DE : jouer %d\n", winer);
   }else{
      printf("Match nulle\n");
   }
}


void run_party(char simbol1, char simbol2){
   char cases[9] = "         ";
   char simbols[2] = {simbol1, simbol2};
   int turn = 0;
   display_party(cases);
   while(check_win(simbols, cases)==0 && turn <= 9){
      if(turn%2 == 0){
         player_trun(simbol1, cases);
      }else{
         sleep(1);
         bot_player(simbol2, cases);
      }
      turn ++;
      display_party(cases);
      printf("\n\n");
   }
   display_result(simbols, cases);
}


int check_win(char simbols[2], char cases[9]){
   int i, j;
   char simbol;
   for(i=1; i <= 2; i++){
      simbol = simbols[i-1];
      for(j= 0; j<7; j++){
         if(cases[victory_condition[j][0]] == simbol && cases[victory_condition[j][1]] == simbol && cases[victory_condition[j][2]] == simbol){
            return i;
         }
      }
   }
   return 0;
}


int no_cheat(int choice, char cases[9]){
   if(cases[choice-1] == ' ' && choice < 10 && choice >0){
      return 0;
   }else{
      return 1;
   }
}


void bot_player(char simbol, char cases[9]){
   int choice;
   do{
      choice = rand() % 9 + 1;
   } while( no_cheat(choice, cases)!=0);
   cases[choice-1]= simbol;
}


void player_trun(char simbol, char cases[9]){
   int choice, attempt = 0;
   do{
      if(attempt >0){
         printf("Choix impossible !\n");
      }
      printf("Choisissez oû jouer :\n");
      scanf("%d",&choice);
      attempt ++;
   } while( no_cheat(choice, cases)!=0);
   cases[choice-1]= simbol;
   printf("\n");
}


void display_party(char cases[9]){
   int i;
   for(i = 1; i <= 9; i++){
      printf("%c", cases[i-1]);
      if(i % 3 == 0 && i != 9 ){
         printf("\n---------\n");
      }else if( i != 9) {
         printf(" | ");
      }
   }
   printf("\n");
}