#include<conio.h>
#include<string.h>
#include<stdlib.h>
using namespace std;
int main()
{
    int point;
    int player1=0,player2=0;
    string name1,name2;
    cout<<"Enter first player name ";
    cin>>name1;
    cout<<"Enter the second player name ";
    cin>>name2;
    system("cls");
     
    cout<<"If "<<name1<<" wins a point press 1";
    cout<<"\nIf "<<name2<<" wins a point press 2";
    getch();
     
    system("cls");
    cout<<"Scoreboard"<<endl;
    cout<<name1<<setw(5)<<name2<<endl;
    cout<<player1<<setw(5)<<player2<<endl;
    getch();
     
    getch();
    system("cls");
    while((player1==11&&player2<10)||(player2==11&&player1<10));
    {
    cout<<"Enter point won by ";
    cin>>point;
    if(point==1)
    player1++;
    if(point==2)
    player2++;  
    cout<<"Scoreboard"<<endl;
    cout<<name1<<setw(5)<<name2<<endl;
    cout<<player1<<setw(5)<<player2<<endl;
    }
getch();
}
