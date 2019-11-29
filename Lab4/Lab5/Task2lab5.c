#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
int main()
{
    int clients, i ;
    float average,total ;
     printf("Welcome to the Ticket Machine\n");

    /* input */
    printf("How many people bought tickets ?\n");
    scanf("%d", &clients);
    int tickets[clients];

    for (i=0; i<clients; i++){
    printf("Please enter the number of tickets  %d bought", clients);
    scanf("%d", &tickets[i]);
    total =total+tickets[i];


    }
    printf("Client No. \t No. Tickets\n");
    for (i=0; i<clients; i++){
    printf("    %d\t\t",i+1);
    printf("    %d\n", tickets[i]);
    }
    average = total/clients;
    printf("The average number of tickets is %1.3f\n", average);

    printf("Thank you for using my code!");

    return(EXIT_SUCCESS);

}
