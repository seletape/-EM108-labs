#include <stdio.h>
#include <stdlib.h>
/* structured type definition */
typedef struct stud_type_tag
{
int id;
int em108;
int em105;
float avg;
} stud_type;
/* declarations */
/* function that reads data from a file, stores it in
an array and returns the number of records read*/
int read_records (char* file_name, stud_type stud[]);
/* function that computes the average for each
student given the array with stud info and stores the
results in the same array */
void compute_average (stud_type stud[], int size);
/* function that writes data taken from the array
into a file */
void write_records (char* file_name,
stud_type stud[], int size);
/* function that prints the studentIDs, grades and
their average marks */
void print_results (stud_type stud[], int size);
EE108 Section 5 Structures page 22 of 24
EM108: Software Development for Engineers
/* main function */
int main()
{
/* 1-dimensional array that stores student
related data for all registered students */
stud_type stud[5000];
/* no current registered students (no records) */
int norecs = 0;
/* welcome message */
printf(“Welcome to the program!\n”);
/* read records */
norecs = read_records(“grades.txt”, stud);
/* compute the averages */
compute_average(stud, norecs);
/* write data to a file */
write_records(“results.txt”, stud, norecs);
/* print results */
print_results(stud, norecs);
printf(“Goodbye!\n”);
return (EXIT_SUCCESS);
}
EE108 Section 5 Structures page 23 of 24
EM108: Software Development for Engineers
/* function definitions */
int read_records (char* file_name, stud_type stud[])
{
FILE* fp;
int norecs = 0;
char ch;
/* open file */
fp = fopen(file_name, “r”);
while(!feof(fp))
{
/* read on record from file */
fscanf(fp, “%d%c%d%c%d%c”,
&stud[norecs].id, &ch,
&stud[norecs].em108, &ch,
&stud[norecs].em105, &ch);
/* increase the number of records read */
norecs++;
}
/* close file */
fclose(fp);
return norecs;
}
void compute_average (stud_type stud[], int size)
{
int i;
/* parse grades and compute the average */
for (i = 0; i < size; i++)
stud[i].avg = (stud[i].em108 +
stud[i].em105)/2.0;
}


void write_records (char* file_name,
stud_type stud[], int size)
{
FILE* fp;
int i;
/* open file */
fp = fopen(file_name, “w”);
for (i = 0; i < size; i++)
/* read on record from file */
fprintf(fp, “%d %d %d %f\n”,
stud[i].id, stud[i].ee102,
stud[i].ee105, stud[i].avg);
/* flush content into file */
fflush(fp);
/* close file */
fclose(fp);
}
void print_results (stud_type stud[], int size)
{
int i;
printf(“| StudID |ee102|ee105| Avg |\n”);
/* parse data and print grades and average */
for (i = 0; i < size; i++)
printf(“|%8d|%5d|%5d|%5.2f|\n”,
stud[i].id, stud[i].ee102,
stud[i].ee105, stud[i].avg);
}
