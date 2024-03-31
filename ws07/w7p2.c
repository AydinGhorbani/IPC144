/*/////////////////////////////////////////////////////////////////////////
			  Workshop - #7 (P2)
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
   int playerInput[MAX_LENGTH];
   int input;
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
   PlayerInfo player = {0, 0 , 0 ,{0},0};
    int flag = 1;
    int i = 0;
    int j = 0;
    const int maxMoves = 15;
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
     printf("    Value must be between 3 and 15\n");
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
     player.input=-1;
     player.treasure=0;
     i=0;
     for (i=0; i<game.pathLength; i++) {
	player.playerInput[i]=0;
    }
    
    
    do{
	
	if(player.input !=-1 ){
	    int i=0;
	    for (i=0; i<=player.input+1; i++) {
		printf(" ");
	    }
	    printf("%c",player.name);
	}
	
	printf("\n  ");
	
	int i=0;
	for (i=0; i<game.pathLength; i++) {
	    if(player.playerInput[i]==0){
		printf("-");
	    }else{
	    if(game.bombs[i]==1 && game.treasure[i]==1){
	    printf("&");
	    }else if (game.bombs[i]==1){
	    printf("!");
	    }else if (game.treasure[i]==1){
	    printf("$");
	    }else{
	    printf(".");
	    }
	    }
	}
	
	printf("\n  ");
	
	
	
	for(i=1;i<=game.pathLength;i++){
	    if(i%10==0){
		printf("%d",i/10);
	    }else{
		printf("|");
	    }
	}
	printf("\n  ");
	
	for(i=1; i<=game.pathLength;i++){
	    printf("%d",i%10);
	}
	printf("\n");
	
	
	printf("+---------------------------------------------------+\n");
	printf("  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n",player.lives,player.treasure,game.moves);
	printf("+---------------------------------------------------+\n");
	
	do{
	    
	    printf("Next Move [1-%d]: ",game.pathLength);
	    scanf("%d",&player.input);
	    if(player.input <1 || player.input >20){
		printf("  Out of Range!!!\n");
	    }
	}while((player.input <1 || player.input >20));
	
	player.input--;
	
	if(player.playerInput[player.input]==1){
	    printf("\n===============> Dope! You've been here before!\n\n");
	}else{
	    game.moves--;
	    player.playerInput[player.input]=1;
	    if(game.treasure[player.input]==1 && game.bombs[player.input]==1){
	    printf("\n===============> [&] !!! BOOOOOM !!! [&]\n");
	    printf("===============> [&] $$$ Life Insurance Payout!!! [&]\n\n");
	    player.lives--;
	    player.treasure++;
	    }else if (game.bombs[player.input]==1){
		printf("\n===============> [!] !!! BOOOOOM !!! [!]\n\n");
		player.lives--;
	    }else if(game.treasure[player.input]==1){
		printf("\n===============> [$] $$$ Found Treasure! $$$ [$]\n\n");
		player.treasure++;
	    }else{
		printf("\n===============> [.] ...Nothing found here... [.]\n\n");
	    }
	}
	if (player.lives==0){
	    printf("No more LIVES remaining!\n\n");
	}
	if(game.moves==0){
	    printf("No more MOVES remaining!\n\n");
	}
    }while(!(player.lives==0 || game.moves ==0));
    
    
    
    
    
    
    for (i=0; i<=player.input+1; i++) {
	printf(" ");
    }
    printf("%c",player.name);
    
    
    printf("\n  ");
    
    
    for (i=0; i<game.pathLength; i++) {
	if(player.playerInput[i]==0){
	    printf("-");
	 }else{
	    if(game.bombs[i]==1 && game.treasure[i]==1)
	    {
	    printf("&");
	    }
	    else if (game.bombs[i]==1)
	    {
	     printf("!");
	    }
	    else if (game.treasure[i]==1)
	    {
	    printf("$");
	    }else{
	    printf(".");
	    }
	    }
	    }
    printf("\n  ");
    for(i=1;i<=game.pathLength;i++){
	if(i%10==0){
	printf("%d",i/10);
	}else{
	printf("|");
	}
    }
    printf("\n  ");
    
    for(i=1; i<=game.pathLength;i++){
	printf("%d",i%10);
    }

    printf("\n+---------------------------------------------------+\n");
    printf("  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n",player.lives,player.treasure,game.moves);
    printf("+---------------------------------------------------+\n\n");
    printf("##################\n");
    printf("#   Game over!   #\n");
    printf("##################\n\n");
    printf("You should play again and try to beat your score!\n");
    
    
    return 0;
}


