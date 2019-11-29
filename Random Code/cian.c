#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
int main()

{
/*decleration*/
int i, n, codefinger, playerchoice, playerfinger, rows, columns, x, y, z, playagain;
int total = 0;

int pfarray[5];
int cfarray[5];
int sum[5];
int userpoints = 0, computerpoints = 0;
int b = 0, c = 0, k = 0;


/*introduction*/
printf("Welcome to the best Morra Game EVER!!!\n");


/*odd or even*/
while(b < 1)
{
while(k < 1)
{

printf("Please select whether you would like to be an odd or even number below.\nRemember, 1 = Odd and 2 = Even!\n");
scanf("%d", &playerchoice);

    if(playerchoice == 1)
        {
        printf("Okay then, I am Even and you are Odd\n");
        k++;
        }
        else if(playerchoice == 2)
            {
            printf("Okay then, I am Odd and you are Even\n");
            k++;
            }
        else
            {
            printf("You must choose either 1 or 2\n");
            k = k + 0;
            }
}
    for(x=0; x <= 5; x++)
    {
    for(y=0; y <= 5; y++)
    {
    for(z=0; z <= 5; z++)
    {

    /*finger choices*/
while(c < 1)
    {
    printf("\nPlease enter the amount of fingers you're holding up between 1 and 10 below:\n");
    scanf("%d", &pfarray[x]);


    srand(time(NULL));
    cfarray[y] = rand() %10+1;
    printf("\nMy number of fingers are %d!\n", cfarray[y]);


    /*sum of fingers*/
    sum[z] = cfarray[y] + pfarray[x];
    printf("\nThe sum of the fingers are: %d\n", sum[z]);


    /* loop */
    if (playerchoice == 1)
        if(sum[z] % 2 == 0)
        {
            printf("\nThe winner is me!\n");
                if(pfarray[x] > cfarray[x])
                printf("I get 2 points\nYou get 1 point");
                else
                printf("I get 3 points\n");
        }
        else
        {
            printf("\nThe winner is you!\n");
                if(pfarray[x] > cfarray[x])
                printf("You get 3 points\n");
                else
                printf("You get 2 points\nI get 1 point");
        }

    else if(playerchoice == 2)
        if (sum[z] % 2 == 0)
        {
            printf("\nThe winner is you!\n");
                if(pfarray[x] > cfarray[x])
                printf("You get 3 points\n");
                else
                printf("You get 2 points\nIget 1 point");
        }
        else
        {
            printf("\nThe winner is me!\n");
                if(pfarray[x] > cfarray[x])
                printf("I get 2 points\nYou get 1 point");
                else
                printf("I get 3 points\n");
        }
    if(playerchoice == 2)
            {
            if(sum[z] % 2 == 0)
            {
            userpoints += 2;
            }
            else
            {
            computerpoints +=2;
            }
            }
            else
            {
            if(sum[z] % 2 == 0)
            {
            computerpoints += 2;
            }
            else
            {
            userpoints +=2;
            }

            }
            if(pfarray[x] > cfarray[y])
            {
            userpoints++;
            }
            else if(pfarray[x] < cfarray[y])
            {
            computerpoints++;
            }

 //scoreboard layout//
        printf("\n\t\t\t\t   SCOREBOARD\n------------------------------------------------------------------------------------\n");
        for (rows=1; rows<=1; rows++)
        {
            for (columns=1; columns<=1; columns++)
            {
                printf("round %d ",columns);
            }
            printf("\nNo. of fingers the player held up: %d", pfarray[x]);
            printf("\tNo. of fingers the computer held up: %d", cfarray[y]);
            printf("\nNo. of points scored by player: %d", userpoints);
            printf("\tNo. of points scored by computer: %d\n------------------------------------------------------------------------------------\n", computerpoints);


        }
        if(userpoints >= 6 || computerpoints >= 6)
        {
        c = 1;
        }
        else
        {
        c = 0;
        }
    }
    }



    if(userpoints >= 6)
    {
        printf("YOU WIN! CONGRATULATIONS\n");
    }
    else
    {
        printf("I win... Hard Luck\n");
    }



printf("Would you like to play again? Enter 1 for YES or 2 for NO:\n");
    scanf("%d", &playagain);
    printf("\n\n\n");
    if(playagain == 1)
        {
        b = 0;
        c = 0;
        userpoints = 0;
        computerpoints = 0;
        x=0;
        y=0;
        z=0;
        playagain = 0;
        }
        else
        {
        b = 1;
        printf("Thank you for playing our game!");
        return(0);
        }
}
}


{
return(EXIT_SUCCESS);
}
}
}

