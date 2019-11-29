#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

int main (void)

{
///int points1[4]={0,2,4,6};
///int points2[4]={0,2,4,6};
int player1Score=0;
int player2Score=0;
///int points11, points12;
char choice[10];
int i, n, usernumber, comp2, act_value,rounds;
int sum;
int rounds_count = 0;
int input_trail_count;
n = 1;
time_t t;

///Welcome Message and Team Choice
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
	   comp2 = rand() % 10;
	   printf("Computer choice is %d\n", comp2);
        printf("\n");

   }
      sum = comp2 + usernumber;
      printf("Sum equals: %d", sum);



///If and Else Code for Winner of the Round
if (sum % 2 == 0)
        printf("\n %d is even. \nEven player is the winner.", sum);
    else
        printf("\n %d is odd. \nOdd player is the winner.", sum);



///Decleration of the winner maybe include in if and else
                if(strcmp(choice, "Even") == 0)
                {
                  player1Score= player1Score + 2;

                    printf("\nPoints: Player 1= %d", player1Score);
                    printf("\n        Player 2= %d", player2Score);
                }
                else
                {
                     player2Score= player2Score + 2;

                    printf("\nPoints: Player 1= %d", player1Score);
                    printf("\n        Player 2= %d", player2Score);
                }
                ++rounds_count;

}
while (player1Score!=6||player2Score!=6);
return(0);
}



