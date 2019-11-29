#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct employee_type_tag{
	char name[20];
	char surname[20];
	char PPS[20];
	char Nationality[20];
	int age;
	int marriage;
	int children ;
}employee_type;

typedef struct benefit_type_tag{
    char PPS[20];
    int salary;
	int pension;
	int health;
	int allowance;
}benefit_type;

int read_employee_file(char* filename, employee_type employee[]);
int read_benefit_file(char* filename, benefit_type benefit[]);
int get_contribution(char* PPS,employee_type employee[] , int size);

void apply_contribution(char* PPS, benefit_type benefit[], int size);
/*
char* get_code(char* name, dvd_type dvd[], int size);
void apply_discount_to_merch(char* name, merch_type merch[], int size);
void apply_reduction(char* cat, int year, dvd_type dvd[], int size);
void write_file();
void print_screen(char* cat);*/

employee_type employee[100];
benefit_type benefit[100];

int noemployees = 0; 		//number of dvds in the dvds.txt
int nobenefits = 0;	//number of merchandise in merchs.txt

int main(){

	//This is what caused the problem. In the data structure they have fixed size, while here they don't
	//char* name; char* cat; char* code;
	//so, they should be declared as the following
	char name[20];
	char surname[20];
	char PPS[20];
	char Nationality[20];
	int age;
	int marriage;
	int children ;
	int ans;


	printf("Welcome to the program\n");

	while(ans != 6){
		printf("1. Read from files\n");
		printf("2. Apply discount to merchandise\n");
		printf("3. Apply reduction\n");
		printf("4. Write to file\n");
		printf("5. Print to screen\n");
		printf("6. Exit\n");

		printf("Enter your choice: \n");
		scanf("%d", &ans);

		switch(ans){
			case 1:
				if(noemployees == 0){
					noemployees = read_employee_file("employees.txt", employee);
					nobenefits = read_benefit_file("benefits.txt", benefit);
					printf("noemployees= %d\n", noemployees);
					printf("nobenefits = %d\n", nobenefits);
				}
				else
					printf("Data has already been read from the files\n");
				break;


			case 2:
				printf("Enter your PPS: \n");
				scanf("%s", PPS);
                age=get_contribution(PPS,employee,noemployees);
                apply_contribution(PPS,benefit,nobenefits);

printf("Contribution has been calculated \n");

				break;
						}
	}
	/*
			case 3:
				printf("Enter the category and year: \n");
				scanf("%s %d", cat, &year);
				apply_reduction(cat,year,dvd,nodvd);
				break;
			case 4:
				write_file();
				break;
			case 5:
				printf("Enter Category: \n");
				scanf("%s", cat);
				print_screen(cat);
				break;
		}
*/
	}
int read_employee_file(char* filename,employee_type employee[]){
	FILE *fp;
	int i=0;
	char ch;

	//open the file
	fp = fopen(filename, "r");

	//read line by line
	while(!feof(fp)){
	 	fscanf(fp, "%s%c%s%c%s%c%s%c%d%c%d%c%d%c",
		 employee[i].name, &ch,
		 employee[i].surname, &ch,
		 employee[i].PPS, &ch,
		 employee[i].Nationality, &ch,
        &employee[i].age, &ch,
		&employee[i].marriage, &ch,
		&employee[i].children,&ch);


		 i++;
	}
	fclose(fp);

	return i;
}

int read_benefit_file(char* filename, benefit_type benefit[]){
	FILE *fp;
	int i=0;
	char ch;

	//open the file
	fp = fopen(filename, "r");

	//read line by line
	while(!feof(fp)){
	 	fscanf(fp, "%s%c%d%c%d%c%d%c%d%c",
		 benefit[i].PPS, &ch,
		 &benefit[i].salary, &ch,
        &benefit[i].pension, &ch,
		 &benefit[i].health, &ch,
		 &benefit[i].allowance, &ch);

		 i++;
	}
	fclose(fp);

	return i;

}



int get_contribution(char* PPS,employee_type employee[] , int size){
	int i;
	int age=0;
	int mar = 0;
    int child=0;
	for(i=0; i<size; i++){
		if(strcmp(employee[i].PPS, PPS) == 0){
			age = employee[i].age;
			mar= employee[i].marriage;
			child=employee[i].children;
			break;
		}
	}
	return age;
	return  mar;
	return child;


}
// Change employee array to benefit array*******
void apply_contribution(char* PPS, benefit_type benefit[], int size){
	int age = get_contribution(PPS,employee,noemployees);
	int mar = get_contribution(PPS,employee,noemployees);
	int child = get_contribution(PPS,employee,noemployees);
	//I removed the line below and add it to line 173 in the if statement
	//char* code = get_code(name,dvd,nodvd);
float allow;
float health_c;
float allow_m;
float allow_c;
float pension ;
float health_contribution ;
	int i;


	for(i=0; i<size; i++){
		if(strcmp(employee[i].PPS, get_contribution(PPS,employee,noemployees)) == 0 )
			pension = benefit[i].salary*0.2;
			health_contribution = benefit[i].salary*0.1;

	}
	for(i=0; i<size; i++){
		if(strcmp(employee[i].age, get_contribution(PPS,employee,noemployees)) == 0 && age>60)
			allow = benefit[i].salary*0.05;
			health_c=benefit[i].salary*0.07;
	}
	for(i=0; i<size; i++){
		if(strcmp(employee[i].marriage, mar) == 0 && mar==1)
			allow_m=benefit[i].salary*0.1;

	}

    for(i=0; i<size; i++){
		if(strcmp(employee[i].children, child) == 0)
			allow_c=benefit[i].salary*(child*0.05);

	}
	printf("Contributions calculated\n");
}


