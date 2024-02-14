/*
Name: 
Muhammad Muzammil Ashraf

Roll No: 
bcsf21m009

Project Name:
Tic Tac Toe Game

Description: 
First I add Menu for the Game in which i add how you can start the game. I forced user to press 'Enter' to start the game
if he enterd other key then Message will be dispalyed to enter the valid key then I am performing Toss for which if 
Heads will come then Player 1 will got the first turn and if Tail will come then the Player 2 will get the first turn
Then a Function Will call that show darwBoard on which the will be played. Then the Function would be called, I  used
a loop for all turns of the game and i start the loop from 2 and taking mode to shuffle the turns between the palyers,
after each turn the bord will display by clearing screen with the changing after each turn, and as same the conditions
will be checked on every iteration to give the Result that which player have Won the Game, MEssages will be displayed on Winning.
and if the no condition satisfied then the control goes to last condition for which the Game has been drawed!! 
Then users will be asked to play again to decide thee winner, if they would say Yes then game will be played as same as above....

*/

#include <stdio.h>  // for input Output
#include <stdlib.h>  // for clear screen and colors adding 
#include<time.h> // taken for performing Toss

// Fuctions
void game_menu();
void drawboard();
void play_game();
void show_board(char[]);

int x, y;    // these are the players

int main()
{

    system("color B");  // for adding color for beauty of the game...
    game_menu();
}
void game_menu()
{
    char play;

    // Menu for the Game
    printf("\n\t\t   _____________________________________________________________________________");
    printf("\n\t\t ||                              GAME                                           ||");
    printf("\n\t\t ||                   <----TIC----TAC----TOE---->                               ||");
    printf("\n\t\t ||        Welcome to the Game develpoed By Muzammil Ashraf 'bcsf21m009'        ||\n");
    printf("\t\t || Head (0) has been Selected For Toss by Player 1 and Palyer 2 select Tail (1)||");
    printf("\n\t\t ||                  Press Enter to start the game                              ||");
    printf("\n\t\t  ______________________________________________________________________________\n\t\t");
    
    

    int guess;
    
     
    srand(time(NULL));   // fuction to generate a random number.
    guess=rand()%2;  //  if 0 it means Head so the player 1 will get first turn 
    // if 1 it means Player 2 will get the first Turn.


    scanf("%c", &play);

    if (play == '\n')      // To start the game 
    {
        if(guess==0)    // it means head
    {
        printf("\n\t\t Here we go For the Toss And It Heads");
        printf("\n\t\t Player 1 got the First Turn");
        x=1;
        y=2;
    }
    else if(guess==1)
    {
        printf("\n\t\t Here we go For the Toss And it Tails");
        printf("\n\t\t Player 2 got the First Turn");
    
        x=2;
        y=1;
    }

        printf("\n\n\t\t\tplayer %d(X)\n\n\t\t\tplayer %d(O)", x, y);
        drawboard();
        play_game();
    }

    if(play != '\n')
    {
        printf("\n\n\t\tInvalid key!Press a valid key");   // validation on the starting of the game
        game_menu();    // again call to the menu Function
    }


}

void drawboard()
{
    // print the drawboard here on which the game would be play

    printf("\n\n");
    printf("\t\t\t        |       |       \n");
    printf("\t\t\t        |       |       \n");
    printf("\t\t\t  1     |  2    |  3     \n");
    printf("\t\t\t        |       |       \n");
    printf("\t\t\t_________________________\n");
    printf("\t\t\t        |       |       \n");
    printf("\t\t\t        |       |       \n");
    printf("\t\t\t  4     |  5    |  6     \n");
    printf("\t\t\t        |       |       \n");
    printf("\t\t\t_________________________\n");
    printf("\t\t\t        |       |       \n");
    printf("\t\t\t        |       |       \n");
    printf("\t\t\t  7     |  8    |  9     \n");
    printf("\t\t\t        |       |       \n");


}


void play_game()
{

    int i;
    char choice[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'}; // values from which you decide to select the place to enter
    // above values will be overWrite by the Players turns
    for (i = 2; i < 11; i++)
    {
        int place=0;
        if ((i % 2) == 0)    // for shuffling turns between the players
        {
            
            printf("\n\n\t\t\tplayer %d turn : ", x);
            scanf("%d", &place); 
            while(place<1||place>9)
            {
                printf("\t\t Invalid\n\t\t ReEnter: ");    // validation on the places
                scanf("%d", &place);   
            }

            if(choice[place-1]!= 'X'&& choice[place-1]!='O')  // validation on previously entered for player 1 the place that has been filled can`t be reWrite
            {
                choice[place - 1] = 'X';
    
            }
            else if(choice[place-1]== 'X'|| choice[place-1]=='O')   // ReEnter if Already filled
            {
                printf("\n\t\t\tPls ReEnter on the place that  will have not been already filled: ");
                scanf("%d", &place);
                choice[place - 1] = 'X';
            }
            
        }
        else
        {
        
            printf("\n\n\t\t\tplayer %d turn : ", y);
            scanf("%d", &place);
            while(place<1||place>9)
            
            {
                printf("\t\t Invalid\n\t\t ReEnter: ");      // vaidation on the places
                scanf("%d", &place);   
            }

            if(choice[place-1]!= 'X'&& choice[place-1]!='O')     // validation on previously entered  for player 2
            {
                choice[place - 1] = 'O';
                
            }
            else if(choice[place-1]== 'X' || choice[place-1]=='O')  // ReEnter if already filled 
            {
                printf("\n\t\t\tPls ReEnter on the place that will not hv been already filled: ");
                scanf("%d", &place);
                choice[place - 1] = 'O';
                
            }
    
        }
        show_board(choice);
        
        // condition chking after printing GameBoard with 
        if (choice[0] == choice[1] && choice[1] == choice[2] && choice[2] == 'X')
        {
            printf("\n\t\t\tPLAYER %d WON", x);
            printf("\n\t\t\tYour Game has completed\n");
            printf("\n\t\t\tThank You For Playing");
            break;
        }

        else if (choice[3] == choice[4] && choice[4] == choice[5] && choice[5] == 'X')
        {
            printf("\n\t\t\tPLAYER %d WON", x);
            printf("\n\t\t\tYour Game has completed\n");
            printf("\n\t\t\tThank You For Playing");
            break;
        }

        else if (choice[6] == choice[7] && choice[7] == choice[8] && choice[8] == 'X')
        {
            printf("\n\t\t\tPLAYER %d WON", x);
            printf("\n\t\t\tYour Game has completed\n");
            printf("\n\t\t\tThank You For Playing");
            break;
        }

        else if (choice[0] == choice[4] && choice[4] == choice[8] && choice[8] == 'X')
        {
            printf("\n\t\t\tPLAYER %d WON", x);
            printf("\n\t\t\tYour Game has completed\n");
            printf("\n\t\t\tThank You For Playing");
            break;
        }

        else if (choice[2] == choice[4] && choice[4] == choice[6] && choice[6] == 'X')
        {
            printf("\n\t\t\tPLAYER %d WON", x);
            printf("\n\t\t\tYour Game has completed\n");
            printf("\n\t\t\tThank You For Playing");
            break;
        }

        else if (choice[0] == choice[3] && choice[3] == choice[6] && choice[6] == 'X')
        {
            printf("\n\t\t\tPLAYER %d WON", x);
            printf("\n\t\t\tYour Game has completed\n");
            printf("\n\t\t\tThank You For Playing");
            break;
        }

        else if (choice[1] == choice[4] && choice[4] == choice[7] && choice[7] == 'X')
        {
            printf("\n\t\t\tPLAYER %d WON", x);
            printf("\n\t\t\tYour Game has completed\n");
            printf("\n\t\t\tThank You For Playing");
            break;
        }

        else if (choice[2] == choice[5] && choice[5] == choice[8] && choice[8] == 'X')
        {
            printf("\n\t\t\tPLAYER %d WON", x);
            printf("\n\t\t\tYour Game has completed\n");
            printf("\n\t\t\tThank You For Playing");
            break;
        }

        else if (choice[0] == choice[1] && choice[1] == choice[2] && choice[2] == 'O')
        {
            printf("\n\t\t\tPLAYER %d WON", y);
            printf("\n\t\t\tYour Game has completed\n");
            printf("\n\t\t\tThank You For Playing");
            break;
        }

        else if (choice[3] == choice[4] && choice[4] == choice[5] && choice[5] == 'O')
        {
            printf("\n\t\t\tPLAYER %d WON", y);
            printf("\n\t\t\tYour Game has completed\n");
            printf("\n\t\t\tThank You For Playing");
            break;
        }

        else if (choice[6] == choice[7] && choice[7] == choice[8] && choice[8] == 'O')
        {
            printf("\n\t\t\tPLAYER %d WON", y);
            printf("\n\t\t\tYour Game has completed\n");
            printf("\n\t\t\tThank You For Playing");
            break;
        }

        else if (choice[0] == choice[4] && choice[4] == choice[8] && choice[8] == 'O')
        {
            printf("\n\t\t\tPLAYER %d WON", y);
            printf("\n\t\t\tYour Game has completed\n");
            printf("\n\t\t\tThank You For Playing");
            break;
        }

        else if (choice[2] == choice[4] && choice[4] == choice[6] && choice[6] == 'O')
        {
            printf("\n\t\t\tPLAYER %d WON", y);
            printf("\n\t\t\tYour Game has completed\n");
            printf("\n\t\t\tThank You For Playing");
            break;
        }

        else if (choice[0] == choice[3] && choice[3] == choice[6] && choice[6] == 'O')
        {
            printf("\n\t\t\tPLAYER %d WON", y);
            printf("\n\t\t\tYour Game has completed\n");
            printf("\n\t\t\tThank You For Playing");
            break;
        }

        else if (choice[1] == choice[4] && choice[4] == choice[7] && choice[7] == 'O')
        {
            printf("\n\t\t\tPLAYER %d WON", y);
            printf("\n\t\t\tYour Game has completed\n");
            printf("\n\t\t\tThank You For Playing");
            break;
        }

        else if (choice[2] == choice[5] && choice[5] == choice[8] && choice[8] == 'O')
        {
            printf("\n\t\t\tPLAYER %d WON", y);
            printf("\n\t\t\tYour Game has completed\n");
            printf("\n\t\t\tThank You For Playing");
            
            break;
        }

        else if (i == 10)
        {
            printf("\n\t\t\tGAME DRAW");

            printf("\n\t\t\t As the Game draw.Would you want to play Game Again.If you want to play Again Enter 1");
            int num;
            printf("\n\t\t\t Enter the number if u want to play: ");
            scanf("%d", &num);
            if(num==1)
            {
                game_menu();      // if Game Draw then we ask The players if they want to play again....
            
            }
            else
            {
                printf("\n\t\t\tYour Game has completed\n");
                printf("\n\t\t\tThank You For Playing");
                
            }
        }
        
            
    }

}


void show_board(char choice[])
{
    
    system("cls");
    system("cls");

    printf("\t\t\t        |       |       \n");
    printf("\t\t\t        |       |       \n");
    printf("\t\t\t        |       |       \n");
    printf("\t\t\t  %c     |  %c    |  %c     \n", choice[0], choice[1], choice[2]);
    printf("\t\t\t        |       |       \n");
    printf("\t\t\t_________________________\n");
    printf("\t\t\t        |       |       \n");
    printf("\t\t\t        |       |       \n");
    printf("\t\t\t  %c     |  %c    |  %c     \n", choice[3], choice[4], choice[5]);
    printf("\t\t\t        |       |       \n");
    printf("\t\t\t_________________________\n");
    printf("\t\t\t        |       |       \n");
    printf("\t\t\t        |       |       \n");
    printf("\t\t\t  %c     |  %c    |  %c     \n", choice[6], choice[7], choice[8]);
    printf("\t\t\t        |       |       \n");
    printf("\t\t\t        |       |       \n");
}
