/****************************************************************
(▀̿Ĺ̯▀̿ ̿)
Referring code made by SFMSupersanta, my friend Arcahv and SonBEO1907
Program:RUSSIAN ROULETTE THE GAME
version 2.1
****************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <conio.h>
#include <ctype.h>

void multi_play()                                          //multi_play function
{
  printf("2 players: type 2 \t\t3 players: type 3 \t\t4 players: type 4 \t\t5 players: type 5 \n");

  printf("Your choice: ");                 //number of players (1)

  int randomNum;
  int players =1;
  char player_name[4][255];

while (players==1)
{
scanf("%d", &players) ;
if (players<=5)                         //enter player's name 
  { 
  for(int i = 0; i < players; i++)
  {
    printf("Type in the number %d player's name: ", i+1);
    scanf("%s",&player_name[i]) ;  
  }
  } else 
    {
        printf("No more than 5 people allowed, please enter a valid number if you want to take the challenge:\n");
        players=1;
    }  
}
  int again=1;                                           // initialize the value to start the game
  while(again == 1)
  {
  //mpstart:
  randomNum = rand() % 6;                             //ran number created is from 0 to 5(6 in total)    
      //printf("The radnum is: %d\n", randomNum);                //check code for dev only 
      int temp_player = 0;                                        //variable for displaying player's name
      int eliminated_player;                                    //variable for eliminated player

      for(int i = 1; i <= 6; i++) 
      {
        printf(" Player %s's Turn \nPress ENTER to test your luck!\n", player_name[temp_player]);
        eliminated_player = temp_player;
        temp_player++;

        if(temp_player >= players) 
          temp_player = 0;
          _getch();                                             //pause program until the user press a button

        if (i - 1 == randomNum)
        {
          printf("\tYOU DIED\n\t-------- \n\n Player %s has been eliminated!\n The others players wins\n", player_name[eliminated_player]);
          printf("\nEnter 1 to continue, any other number to return to main menu: ");
          scanf("%d", &again);  
                      
          break;  
            /********************************  
              int again;
              scanf("%d", &again);
            
              switch (again)
              {
                case 1: 
                goto mpstart;

                default: 
                printf("\nGG\n\n"); 
                break;
              
              }
            ********************************/                                           
        }

            
        printf("Still alive eh? \n");
         
      }
  }

}

void play_single()                                        //single-play function
{
  int randomNum = rand() % 6;                             //ran number created is from 0 to 5(6 in total)
     // printf("The radnum is: %d\n", randomNum);                //check code for dev only
    int reset=1;
    while (reset==1)
    {  
      for(int i = 1; i <= 6; i++) 
      {
        printf(" Turn %d \nPress ENTER to test your lucks!\n", i);
        _getch();                                             //pause program until the user press a button
        
        if (i - 1 == randomNum)
        {
          printf("\tYOU DIED\n\t-------- \n\nYou have survied %d times this day!", i);

          if(i <= 5) 
              {
              printf("your luck sucks, go do sth good then try again\n");
              printf("\nEnter 1 to continue, any other number to return to main menu: ");
              scanf("%d",&reset);
              }  
          else if(i > 5)
              { 
              printf("CONGRATULATIONS, YOU WON.");
              printf("\nEnter 1 to continue, any other number to return to main menu: ");
              scanf("%d",&reset);
              }
          break;                                              //basicly the whole function
        }
        printf("Still alive eh? \n");
      }
    }
}

void russianroulette()
{
  printf("Single-player: Type 1  multi-player: Type 0\nYour choice: ");
  
  int game;
  scanf("%d", &game);
  
  switch(game)
  {
    case 1:
      play_single();
      break;
    
    case 0:
      multi_play();
    break;
  }
}
  
int main()
{  
  printf("\n\t\t\tRUSSIAN ROULETTE THE GAME");
  
  int input;
  
  srand(time(NULL));                                    //need to initialize the time value form the begining                                       
  
  do                                                    //do-while loop
  {
    printf("\n\n\t----------------------------------------------------\n\tEnter 1 to try your luck, Enter 0 if you are a wimp: ");
    scanf("%d", &input);
    printf("\n\n");

    switch(input)
    {
      case 0:
        printf("GTFO you weak ass mf \n");
        printf("Press ENTER to get tf outta here");

        _getch();                                             //pause program until the user press a button
        break;
      
      case 1:
        russianroulette();
        break;
    }
  }
  while(input!=0);
  return 0;

}
//(1/13/2022)mm/dd//yyyy
//last editor: SFMSupersanta (Arcahv)
/*
Todo: -Add retry to single-player function
      -And more lines to print when player is alive
DONE: -Fix multiplayer funtion where there is 2 players
      -Multiplayer loop. Entering names each play is annoying as fuck
Changelog: makes code a bit easier to read
*/