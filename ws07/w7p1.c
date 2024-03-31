/*/////////////////////////////////////////////////////////////////////////
			  Workshop - #7 (P1)
Full Name  : Aydin Ghorbani
Student ID#: 124170226
Email      : aghorbani8@myseneca.ca
Section    : ZBB

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS
#define SET 5
#define MAX_LIVES 10
#define MIN_LIVES 1
#define MAX_LENGTH 70
#define MIN_LENGTH 10
#include <stdio.h>


typedef struct 
{
   char name;
   int lives;
   int treasure;
   int history;
}PlayerInfo; 

typedef struct 
{
  int pathLength;
  int moves;
  int bombs[MAX_LENGTH];
  int treasure[MAX_LENGTH];
} GameInfo;



int main(void)
{
    GameInfo game = {0, 0, {0}, {0}};
    PlayerInfo player = {0, 0 , 0 , 0};
    int flag = 1;
    int i = 0;
    int j = 0;
    const int maxMoves = 26;
    const int minMoves = 3;


printf("================================\n"
"         Treasure Hunt!\n"
"================================\n\n");

printf("PLAYER Configuration\n"
       "--------------------\n");

    printf("Enter a single character to represent the player: ");
    scanf("%1c" , &player.name);

 while (flag != 0)
 {
    printf("Set the number of lives: ");
    scanf(" %d" , &player.lives);

      if (player.lives < MIN_LIVES || player.lives > MAX_LIVES)
      {
	printf("     Must be between 1 and 10!\n");
      }
      else
      {
	printf("Player configuration set-up is complete\n\n") ;
	flag = 0;
      } 
 }
 flag = 1;   

printf("GAME Configuration\n"
       "------------------\n");

while (flag)
{
    printf("Set the path length (a multiple of 5 between 10-70): ");
    scanf(" %d", &game.pathLength);

    if (game.pathLength < MIN_LENGTH || game.pathLength > MAX_LENGTH || game.pathLength % SET != 0)
    {
	printf("     Must be a multiple of 5 and between 10-70!!!\n");
    }
    else
    {
	flag = 0;
    }
}
 
flag = 1;
while (flag != 0)
{
    printf("Set the limit for number of moves allowed: ");
    scanf("%d" , &game.moves);

    if (game.moves < minMoves || game.moves > maxMoves)
    {
	printf("    Value must be between 3 and 26\n");
    }
    else flag = 0;
}
 flag = 1; 

printf("\nBOMB Placement\n"
       "--------------\n"
       "Enter the bomb positions in sets of 5 where a value\n"
       "of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n"
       "(Example: 1 0 0 1 1) NOTE: there are %d to set!\n" , game.pathLength);
    
for (i = 0; i < game.pathLength; i += SET)
{
   printf("   Positions [%2d-%2d]: " , i + 1 , i + SET);

   for (j = i; j <  i + SET ; j++)
   {
    scanf("%d" , &game.bombs[j]);
   }
   

}
printf("BOMB placement set\n\n");

printf("TREASURE Placement\n"
"------------------\n"
"Enter the treasure placements in sets of 5 where a value\n"
"of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n"
"(Example: 1 0 0 1 1) NOTE: there are %d to set!\n" , game.pathLength);

for (i = 0; i < game.pathLength; i += SET)
{
   printf("   Positions [%2d-%2d]: " , i + 1 , i + SET);

   for (j = i; j <  i + SET ; j++)
   {
    scanf("%d" , &game.treasure[j]);
   }
}
printf("TREASURE placement set\n");
printf("\nGAME configuration set-up is complete...\n\n");
printf("------------------------------------\n"
"TREASURE HUNT Configuration Settings\n"
"------------------------------------\n");
printf("Player:\n"
   "   Symbol     : %c\n" 
   "   Lives      : %d\n" 
   "   Treasure   : %s\n"
   "   History    : %s\n\n"
"Game:\n"
"   Path Length: %d\n", player.name ,  player.lives , "[ready for gameplay]" , "[ready for gameplay]" , game.pathLength);
printf("   Bombs      : ");
    for (i = 0; i < game.pathLength; i++) 
	{
	    printf("%d",game.bombs[i]);
	}
printf("\n");

    printf("   Treasure   : ");
	for (i = 0; i < game.pathLength; i++)
	{
	    printf("%d",game.treasure[i]);
	}
    printf("\n\n====================================\n"
	   "~ Get ready to play TREASURE HUNT! ~\n"
	   "====================================\n");

    return 0;
}
