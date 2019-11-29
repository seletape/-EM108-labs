#include <stdio.h>
#include <string.h>
int main()
{
int score[5][3], total[5];
int st, sc;
clrscr();
    for(st=0;st<=4;st++)
    {
    total[st]=0;
        for(sc=0;sc<=2;sc++)
        {
        scanf("%i",&score[st][sc]);
        total[st]=total[st]+score[st][sc];
        printf("%i",total[st]);
        }
    }
}
