/****************************************************************
(▀̿Ĺ̯▀̿ ̿)
Referring code made by SFMSupersanta, my friend Arcahv and SonBEO1907
Program:RUSSIAN ROULETTE THE GAME
version 3.0
****************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>

void alive_dialogue()
{
  char *string[10];
  string[0] = "You are still alive? Next shot will be diferent.";
  string[1] = "Your being alive is a waste of oxygen. I hope the next shot will erase your existance.";
  string[2] = "Your useless life depends on your next shot.";
  string[3] = "Nobody loves you, so it's time to die in loneliness. Take the next shot.";
  string[4] = "Nikocado Avocado is waiting for you in his own hell. Come to him by taking the next shot.";
  string[5] = "Come on come on cupcake, EDP445 is waiting to meet you in hell.";
  string[6] = "Others are waiting for you to die. Be a good motherfucker and die , onegai nee~";
  string[7] = "May the RNGesus be with you, but he doesn't exist so please die next time.";
  string[8] = "Which hurts more? Shooting in the head or your tight fuckable dickhole? Try that next time.";
  string[9] = "Suck that big fat juicy gun barrel and die.";
  string[10] = "Have you experienced isekai? Time to try!";


  srand(time(NULL)); 
  int rannum = rand()%10;
  printf("%s",string [rannum]);
  return;
}

void multi_play()                                          //multi_play function
{
  printf("2 players: type 2 \t\t3 players: type 3 \t\t4 players: type 4 \t\t5 players: type 5 \n");

  printf("Your choice: ");                                 //number of players (1)

  int randomNum;
  int players =1;
  char TempString[255];                                  //temp string to store a line of string in before dup to player name string
  char *player_name[4];                                  //player name string

while (players==1)                                       //loop to get answer form 2 to 5
{
scanf("%d", &players) ;
if (players<=5 && players>1)                              //enter player's name 
  { 
  for(int i = 0; i < players; i++)
  {

    printf("Type in #%d player's name: ", i+1);
    scanf(" %[^\n]",&TempString) ;                        //put space before %[^\n] to get a line of strings
    player_name[i] = strdup(TempString); 

  }
  } else 
    {

        printf("At least 2 or more people must join and no more than 5 people allowed, please enter a valid number if you want to take the challenge:\nYour choice: ");  
        players=1;
        
    }  
}
  int again=1;                                           // initialize the value to start the game
  while(again == 1)
  {

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
                                                    
        }

        printf("\n");
        alive_dialogue();
        printf("\n") ;
        printf("\n") ;
         
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
      printf(" Turn %d \nPress ENTER to test your luck!\n", i);
      _getch();                                             //pause program until the user press a button
      
      if (i - 1 == randomNum)
      {

        printf("\tYOU DIED\n\t-------- \n\nYou have survied %d times this day! ", i);

        if(i <= 5) 
            {

            printf("Your luck sucks, go do sth good then try again\n");
            printf("\nEnter 1 to continue, any other number to return to main menu: ");
            scanf("%d",&reset);

            }  
        else if(i > 5)
            { 

            printf("CONGRATULATIONS, YOU WON.");
            printf("\nEnter 1 to continue, any other number to return to main menu: ");
            scanf("%d",&reset);

            }
        break; 
                                                     //basicly the whole function
      }
        printf("\n");
        alive_dialogue();
        printf("\n") ;
        printf("\n") ;

    }

  }

}

void russianroulette()
{
  printf("Single-player: Type 1  Multi-player: Type 2\nYour choice: ");
  
  int game;
  scanf("%d", &game);
  
  switch(game)
  {

    case 1:
      play_single();
      break;
    
    case 2:
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
      {

        printf("If you are scared, come back to your mama and cry harder you little bitch\n");
        break;  

      }  
      case 1:
      {

        russianroulette();
        break;

      }

    }

  }

  while(input!=0);

  printf("Press ENTER to get tf outta here");
  _getch();                                             //pause program until the user press a button

  
  return 0;

}

//last editor: Arcahv
/*
DONE: -Fix multiplayer function where there is 2 players
      -Multiplayer loop. Entering names each play is annoying as fuck
      -Add retry to single-player function
      -Add more lines to print when player is alive
Changelog: makes code a bit easier to read
           re organized code to better understand how it works
*/