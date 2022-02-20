/****************************************************************
(▀̿Ĺ̯▀̿ ̿)
Referring code made by SFMSupersanta, my friend Arcahv and SonBEO1907
Program:RUSSIAN ROULETTE THE GAME
version 3.1
****************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//#include <conio.h>
#include <ctype.h>
#include <string.h>

/* clear empties input buffer */ 
void clear_buffer (void)
{
    char c;
    while ((c=getchar()) != '\n'&&c!=EOF);
}

long long GetInt(char msg[], long long min, long long max) 
{
     long long value, rc;
     int keeptrying = 1;
     char excess;

     do 
     {
         printf("%s ", msg);
         rc = scanf("%lld%c", &value, &excess);
         if (rc == 0) 
         {
             printf("**No input accepted!**\n\n");
             clear_buffer();
         } 
         else if (excess != '\n') 
         {
             printf("**Trailing characters!**\n\n"); 
             clear_buffer();
         } 
         else if (value < min || value > max) 
         {
             printf("**Out of range!**\n\n");
         } 
         else
             keeptrying = 0;
         } 
     while (keeptrying == 1);
     
     return value;
 }

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
  
  int randomNum;
  int players;
  char TempString[255];                                  //temp string to store a line of string in before dup to player name string
  char player_name[4][255];                                  //player name string

  players= GetInt("2 players: type 2 \t\t3 players: type 3 \t\t4 players: type 4 \t\t5 players: type 5 \nYour choice: ",2,5);
  
  for(int i = 0; i < players; i++)
  { 
    printf("Type in #%d player's name: ", i+1);
    fgets(TempString,255,stdin);                     //fgets(str[],int size,streamtaken)

    int cnt=0;
    while(TempString[cnt]!='\0')
    {
      player_name[i][cnt]=TempString[cnt];
      cnt ++;
    }
    player_name[i][cnt-1]= '\0';
  }

  int again=1;                                           // initialize the value to start the game
  while(again == 1)
  {

    randomNum = rand() % 6;                             //ran number created is from 0 to 5(6 in total)    
    //printf("The radnum is: %d\n", randomNum);                //check code for dev only 
    int temp_player = 0;                                        //variable for displaying player's name
    int eliminated_player;                                    //variable for eliminated player
    for(int i = 1; i < 5 ; i++) 
    {
      printf(" Player %s's Turn \nPress ENTER to test your luck!\n", player_name[temp_player]);
      eliminated_player = temp_player;
      
      temp_player++;
      if(temp_player >= players) 
        temp_player = 0;
      //printf("Press enter to continue!\n");
      while(getchar()!='\n');
      if (i - 1 == randomNum)
      {
        printf("\tYOU DIED\n\t-------- \n\n Player %s has been eliminated!\n The others players wins\n", player_name[eliminated_player]);
        again = GetInt("\nEnter 1 to continue, 0 to return to main menu: ",0,1);   
        i = 6; 
                                                  
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

  
  // printf("The radnum is: %d\n", randomNum);                //check code for dev only
  int reset=1;

  while (reset==1)
  { 

    int randomNum = rand() % 6;                             //ran number created is from 0 to 5(6 in total)
    for(int i = 0; i < 6; i++) 
    {
              
      printf(" Turn %d \nPress ENTER to test your luck!\n", i+1);
      
      if(i == 4 && i != randomNum)
      
      { 
        reset=GetInt("\nCONGRATULATIONS, YOU WON.\nYou have survied 5 times this day!\nRenember this as your luckiest day.\n\nEnter 1 to continue, 0 to return to main menu: ",0,1);
        i = 6;
      }

      while(getchar()!='\n'); 
      
      if (i == randomNum)
      {
        printf("\tYOU DIED\n\t-------- \n\nYou have survied %d times this day! ", i+1);
        
        if(i < 4) 
        {
          reset =GetInt("Your luck sucks, go do sth good then try again\n\nEnter 1 to continue, 0 to return to main menu: ",0,1);
        }  
        if(i == 4)
        {
          reset =GetInt("Almost there, just a tiny bit more you win but sadly, RNGesus doesn't exist.\n\nEnter 1 to continue, 0 to return to main menu: ",0,1);
        }
        
        i = 6;
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
  
  int game=GetInt("Single-player: Type 1  Multi-player: Type 2\nYour choice: ",1,2);
  
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
    input = GetInt("\n\n\t----------------------------------------------------\n\tEnter 1 to try your luck, Enter 0 if you are a wimp: ",0,1); 
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
  while(getchar()!='\n');                                           //pause program until the user press a button

  return 0;

}

//last editor: Arcahv
/*
DONE: -Fix multiplayer function where there is 2 players
      -Multiplayer loop. Entering names each play is annoying as fuck
      -Add retry to single-player function
      -Add more lines to print when player is alive
      -Fixed bug in single player function
Changelog: added input validation
           remove conio.h lib
           makes code a bit easier to read
           re organized code to better understand how it works
*/