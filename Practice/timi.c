#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct employee_type_tag{

char name[20];
char surname[20];
char PPS[20];
char nationality[20];
int age;
int married;
int children;

} employee_type;

typedef struct benefit_type_tag{

char PPS[20];
int salary;
int pension;
int health;
int allowance;

} benefit_type;


void read_files();

int read_employee_file();

int read_benefit_file();

void apply_allowance();

int search_forPPSe();

int search_forPPSb();

void search_PPS();

 void print_screen();

void write_file();



int main()
{

employee_type employee[1000];
benefit_type benefit[1000];

int noemployee=0;
int nobenefit=0;

int ans=1;

printf("Welcome to my programme\n");

while(ans !=6)
{
printf("Menu\n");

printf("1-Read data from files\n");
printf("2-Apply allowance\n");
printf("3-Search\n");
printf("4-Print to screen\n");
printf("5-Write data in file\n");

scanf("%d", &ans);

switch(ans){

case 1: read_files();

case 2: search_PPS();

case 3: print_screen();

case 4: write_file();

case 5: printf("hey");
}
}

printf("Goodbye\n");


}


void read_files(employee_type employee[], int noemployee, benefit_type benefit[], int nobenefit)
{
    char name[20];
if (noemployee==0){
      printf("Enter the input file name:\n");
        scanf("%s", name);
    noemployee= read_employee_file("employee.txt", employee);
    nobenefit= read_benefit_file("benefit.txt", benefit);

}
else
{printf("Enter the input file name:\n");
        scanf("%s", name);
    noemployee= read_employee_file("employee.txt", employee);
    nobenefit= read_benefit_file("benefit.txt", benefit);}
}


int read_employee_file(char* file_name, employee_type employee[])
{

FILE* fp;
int noemployee=0;
char ch;

fp= fopen(file_name, "r");

while(!feof(fp))
{
    fscanf(fp,"%s%c%s%c%s%c%s%c%d%c%d%c%d%c",

           employee[noemployee].name, &ch,
           employee[noemployee].surname, &ch,
           employee[noemployee].PPS, &ch,
           employee[noemployee].nationality, &ch,
           employee[noemployee].age, &ch,
           employee[noemployee].married, &ch,
           employee[noemployee].children, &ch);
           noemployee++;
}
fclose(fp);

read_benefit_file();
}

int read_benefit_file(char* file_name, benefit_type benefit[]){

FILE* fp;
int nobenefit=0;
char ch;

fp= fopen(file_name, "r");

while(!feof(fp))
{
    fscanf(fp,"%s%c%d%c%d%c%d%c%d%c",
           benefit[nobenefit].PPS, &ch,
           benefit[nobenefit].salary, &ch,
           benefit[nobenefit].health, &ch,
           benefit[nobenefit].pension, &ch,
           benefit[nobenefit].allowance, &ch);
           nobenefit++;
}
fclose(fp);

}

void apply_allowance(employee_type employee[], int noemployee, int nobenefit, benefit_type benefit[], int size)
{
    int i;
    for(i=0; i<size; i++)
    {
        if (benefit[i].pension !=20){ benefit[i].pension=20;}
        if (benefit[i].health !=10){ benefit[i].health=10;}

      int pos= search_forPPSe(employee, noemployee, benefit[i].PPS);

        if (pos == -1)
        {printf("Employee not found \n");}
        else
        {
            if (employee[pos].age > 60)
                {
                    benefit[i].health +=7;
                    benefit[i].allowance +=5;
                }
                if(employee[pos].married == 1)
                {
                    benefit[i].allowance += 10;
                }
            if(employee[pos].children > 0)
            {
                benefit[i].allowance += 5*employee[pos].children;
            }
        }
    }
}

int search_forPPSe(employee_type employee[], int size, char PPS[])
{
    int i;
    for(i=0; i<size; i++){
        if (strcmp(employee[i].PPS, PPS)==0)
        {return i;}
    }
    return -1;
}

int search_forPPSb(benefit_type benefit[], int size, char PPS[])
{
        int i;
    for(i=0; i<size; i++){
        if (strcmp(benefit[i].PPS, PPS)==0)
        {return i;}
    }
    return -1;
}

void search_PPS(benefit_type benefit[], int nobenefit, employee_type employee[], int noemployee)
{
 char PPS[20];
 int pose, posb;

 printf("Input the PPS sought: ");
 scanf("%s", PPS);

 pose= search_forPPSe(employee, noemployee, PPS);
 posb= search_forPPSb(benefit, nobenefit, PPS);

 if(pose == -1 || posb == -1)
    printf("Employee not found");
 else
 {
     printf("Updating new record\n");

     printf("Enter new nationality\n");
     scanf("%s", employee[pose].nationality);

     printf("Enter new age \n");
     scanf("%d", &employee[pose].age);

     printf("Enter marriahge status (1/0) \n");
     scanf("%d", &employee[pose].married);

     printf("Enter new salary \n");
     scanf("%d", &benefit[posb].salary);

     printf("Enter new pension (%) \n");
     scanf("%d", &benefit[posb].pension);
 }
 }

 void print_screen( employee_type employee[], benefit_type benefit[], int nobenefit, int noemployee)
{
    int i, posb;
    char letter, ch;

    printf("Please enter the first letter \n");
    scanf("%c%c", &letter, &ch);

    printf("| Name | Surname | PPS | Nationality | Age | Marriage | Children | Benefit \n");
    for(i=0; i<noemployee; i++){
        if (employee[i].surname[0] == letter )
        {
            posb= search_forPPSb(benefit, nobenefit, employee[i].PPS);

            printf("%6s|%7s|%9s|%9s|%6s|%6d|%6d|%6d| \n",
                   employee[i].name, employee[i].surname, employee[i].PPS, employee[i].nationality, employee[i].age, employee[i].married,
                    employee[i].children, benefit[posb].pension);
        }
    }
}

void write_file(employee_type employee[],int noemployee, benefit_type benefit[], int nobenefit ){

int i, posb;

char* filename[20];

printf("Please enter filename \n");
scanf("%s", filename);
FILE*fc;
fc=fopen(filename, "w");

for(i=0; i<noemployee; i++){
    posb= search_forPPSb(benefit, nobenefit, employee[i].PPS);

    fprintf(fc, "%6s,%7s,%9s,%9s,%6s,%6d,%6d,%6d \n", employee[i].name, employee[i].surname, employee[i].PPS, employee[i].nationality, employee[i].age, employee[i].married,
                    employee[i].children, benefit[posb].pension);
}
fclose(fc);
}
