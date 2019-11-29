#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct employees
{
    char name[20];
    char surname[20];
    char PPScode1[20];
    char nationality[20];
    int age;
    int married;
    int children;
    int money;
    int money1;
    int money2;
    int money3;
    int totalmoney;
    int deduction;

}employees_type;

typedef struct benefits
{
    char PPScode2[20];
    int salary;
    int pension;
    int health;
    int allowance;
}benefits_type;

void user_menu();
int money(benefits_type benefits17[], employees_type employees17[], int i, int j);

benefits_type benefits17[10];
employees_type employees17[10];

int i;
int j;



int main()
{
    int option;

    printf("Welcome to the enterprise computer program!!!\n");
    printf("Choose one of the following options...\n");
/* SELE added a while loop so your menu would be repeated after the user selects an option*/
    while(option != 5){
    printf("Option 1: Read all employee benefits and information.\n");
    printf("Option 2: See all employee allowance benefits.\n");
    printf("Option 3: Update employee benefits and information.\n");
    printf("Option 4: Use easy information search.\n");
    printf("Option 5: \n");
    printf("Please enter the option which you have selected as a number...\n");
    scanf("%d", &option);

    switch(option){

    case 1:
    printf("You have chosen option 1.\n");
    printf("\nBelow is the file containing the employee information:\n");

    FILE*employees;
    employees=fopen("employees.txt", "r");
    char singleline1[150];

    while(!feof(employees)){
        fgets(singleline1, 150, employees);
        puts(singleline1);
    }

    fclose(employees);

    printf("\nBelow is the file containing the employee benefits:\n");

    FILE*benefits;
    benefits=fopen("benefits.txt", "r");
    char singleline2[150];

    while(!feof(benefits)){
        fgets(singleline2, 150, benefits);
        puts(singleline2);
    }

    fclose(benefits);
   break;
    }







    case 2: printf("You have chosen option 2.\n");
    fscanf(benefits, "%s %d %d %d %d", &benefits17[i].PPScode2,benefits17[i].salary,benefits17[i].pension,benefits17[i].health,&benefits17[i].allowance);
    fscanf(employees, "%s %s %s %s %d %d %d", &employees17[j].name,employees17[j].surname,employees17[j].PPScode1,employees17[j].nationality,employees17[j].age,employees17[j].married,&employees17[j].children);

    int money(benefits_type benefits17[], employees_type employees17[], int i, int j)
    {
        if(employees17[j].age>60){
            employees17[j].money1=((benefits17[i].salary*5/100)+benefits17[i].salary)+((benefits17[i].salary*7/100)+benefits17[i].salary);
        }

        if(strcmp(employees17[j].married,"1")==0)
        employees17[j].money2=(benefits17[i].salary*10/100)+benefits17[i].salary;

        if(employees17[j].children>0){
            employees17[j].money3=((benefits17[i].salary*5/100)+benefits17[i].salary)*employees17[j].children;
        }

        employees17[j].deduction=employees17[j].money1+employees17[j].money2+employees17[j].money3;
        employees17[j].totalmoney=benefits17[i].salary-employees17[j].deduction;

        return employees17[j].totalmoney;

    }

            for(i=0;i<10;i++){
            printf("Employee %d has a salary of %d euro annually.\n", i+1, employees17[i].money);
            }

            break;




    case 3: printf("You have chosen option 3.\n");

    break;

    case 4: printf("You have chosen option 4.\n");
    char firstletter[1];

    printf("Please enter the first letter of the employee's name:\n");
    scanf("%s", &firstletter);

    if(firstletter==employees17[j].name){
        printf("|Name \t|Surname \t|PPS \t|Salary \t|Deductions \t|Allowance|\n");
        printf("|%s \t|%s \t|%s \t|%d \t|%d \t|%d", employees17[j].name, employees17[j].surname, employees17[j].PPScode1, employees17[j].deduction, employees17[j].totalmoney);
    }
    }



    break;

//    case 5:
        printf("You have chosen option 5.\n");

  break;

// default:
       printf("You have chosen a non-existent option...");



}



