#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

int main (void)

{


int player1Score=0;
int player2Score=0;
char choice[10], userch;
int i, a=0, n, usernumber, comp2, act_value,rounds;
int sum;
int rounds_count = 0;
int input_trail_count;
int player1_winamount;
int player2_winamount;
n = 1;
time_t t;
//********************************************************
int Q = 0;
int userfingers[100];
int pcfingers[100];
int count = 0;
//********************************************************

//int roundsamount;
//int p1score_table[10];
//int p2score_table[10];

FILE* p;

///Welcome Message and Team Choice
//Fullrepeat:
 // p = fopen("score_mandu.txt","w");


 // printf("\tRound %d \t\tPlayer1 score:\t Player2 score:\n",  player1Score[a], player2Score);
    //for(a=0; a<10; a++){
   // fprintf(p,"\tRound\t\tPlayer1 score %d:\t Player2 %dscore:\n",  player1Score[a], player2Score[a]);
   // }

do{
	printf("Welcome to the Morra Game!");

	do{

           input_trail_count = 0;
	printf("\nWould you like to be an Even or Odd player?\n");
	scanf("%s", choice);

          printf("\nYou are player 1(%s)", choice);
        if (strcmp(choice, "Even")==0)
        {

                printf("\nComputer is player 2(Odd)\n");
                printf("Points: Player one= %d", player1Score);
                printf("\n        Player two= %d\n", player2Score);
        }

        else
        {
                printf("\nComputer is player 2(Even)\n");
                printf("Points: Player one= %d", player1Score);
                printf("\n        Player two= %d\n", player2Score);
        }



///Number selection and Random Number Generator
repeat:
	printf("\nPlease enter a number between 1-10:");
	scanf("%d", &usernumber);

    //********************************************************
	userfingers[Q] = usernumber;
	Q++;
	count++;
    //********************************************************

	//player1Score[a] = usernumber;
    //a++;
///Stops the user to putting a number over 10
   if((usernumber) > 10)
   {
                printf("Must be lower than 10!\n");
                //terminate the loop using break statement
                goto repeat;
   }
   srand((unsigned) time(&t));
   for( i = 0 ; i < n ; i++ )

   {
	   comp2 = rand() % 11;
	   printf("Computer choice is %d\n", &comp2);
        printf("\n");

   }
    //********************************************************
    pcfingers[Q] = comp2;
    //********************************************************

      sum = comp2 + usernumber;
      printf("Sum equals: %d", sum);



///If and Else Code for Winner of the Round
               if (sum % 2 == 0)
               printf("\n %d is even. \nEven player is the winner.", sum);
               else
               printf("\n %d is odd. \nOdd player is the winner.", sum);



///Decleration of the winner maybe include in if and else
                if(strcmp(choice, "Even") == 0)
                if (sum % 2==0)
                {
                 player1Score= player1Score + 2, player1Score;


                    printf("\nPoints: Player 1= %d", player1Score);
                    printf("\n        Player 2= %d", player2Score);
                }
                else
                {
                     player2Score= player2Score + 2, player2Score;

                    printf("\nPoints: Player 1= %d", player1Score);
                    printf("\n        Player 2= %d", player2Score);
                }
                else

                if(strcmp(choice, "Odd") == 0)
                if (sum % 2==1)
                {
                  player1Score= player1Score + 2, player1Score;

                    printf("\nPoints: Player 1= %d", player1Score);
                    printf("\n        Player 2= %d", player2Score);
                }
                else
                {
                     player2Score= player2Score + 2, player2Score;

                    printf("\nPoints: Player 1= %d", player1Score);
                    printf("\n        Player 2= %d", player2Score);
                }
                else
                ++rounds_count;


 if((player1Score) >= 6)
 {
    printf("\nYou win! :)\n");
player1_winamount= player1_winamount+1;


   printf("    %d" ,player1Score);
    printf("    %d" ,player2Score);

     break;
 }


  if((player1Score) < 6)
  if((player2Score)>= 6 )
  {

    printf("\nYou lost :(\n");

    printf("Game Number.    Player1 Scores.    Player2 Scores.\n");


    printf("    %d" ,i+1);
    printf("                   %d" ,player1Score);
    printf("                     %d" ,player2Score);



      break;
  }
  ++rounds_count;

	}
while (player1Score!=6||player2Score!=6);

/*int p1score_table[10];
for (index = 0; index < 5; index++)
vals[index] = 0;
*/




    printf ("\n\nDo you want to play again Y/N: \n");
    scanf (" %c", &userch);

    player2Score=0;
    player1Score=0;


}
while (userch== 'Y' || userch == 'y');
fflush(p);

 fclose(p);
//********************************************************
 printf("user fingers history \n");
for(int i = 0; i < count; i++)
{
    printf("%d \n", userfingers[i]);
}

 printf("pc fingers history \n");
for(int i = 0; i < count; i++)
{
    printf("%d \n", pcfingers[i]);
    //********************************************************
}

return(0);
}







