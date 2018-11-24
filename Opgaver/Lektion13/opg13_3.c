#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 100
#define MAX_GROUP_SIZE 100

typedef struct person {
	char name[MAX_NAME];
	int age;
	char sex;
} person;

/* Function prototypes */
void print_person(person *p, FILE *ofp, int num);
person *read_person(FILE *ifp);
person *make_person(person *p, int index, char *name, int age, char sex);
int count_lines(FILE *ifp);

int main(void){
	/* Declaring FILE output pointer and input pointer */
  FILE *ofp;
  FILE *ifp;

  /* Gruppe til at opbevare personer i */
  person write_group[MAX_GROUP_SIZE];

  make_person(write_group, 0, "Christoffer", 19, 'M');
  make_person(write_group, 1, "Noemi", 19, 'F');
  make_person(write_group, 2, "Jens", 24, 'M');
  make_person(write_group, 3, "Torben", 50, 'M');
  make_person(write_group, 4, "Signe", 20, 'F');

 	print_person(write_group, ofp, 5);

 	read_person(ifp);

  return EXIT_SUCCESS;
}

/* Writes people to a txt file */
void print_person(person *p, FILE *ofp, int num){

 /* Laver en fil som hedder personer.txt */ 
	ofp = fopen("personer.txt", "w");

	int i;

		for (i = 0; i < num; ++i)
		{
			fprintf(ofp, "Name:%s Age:%d Sex:%c\n", p[i].name, p[i].age, p[i].sex);
		}
		
	fclose(ofp);
}

/* Reads people from a txt file */
person *read_person(FILE *ifp){

	ifp = fopen("personer.txt", "r");

	if(ifp != NULL){
		/* num_lines skal læses ud fra filen */
			int num_lines = 0;
			num_lines = count_lines(ifp);

			char str1[MAX_NAME];
			int age;
			char sex;

			person read_group[MAX_GROUP_SIZE];

			int i;

			/* Scanning people */
			for (int i = 0; i < num_lines; ++i)
			{
				fscanf(ifp, " Name:%s Age:%d Sex:%c", str1, &age, &sex);
				make_person(read_group, i, str1, age, sex);
			}

			/* Printing people */
			for (int i = 0; i < num_lines; ++i)
			{
				printf("Name:%s Age:%d Sex:%c\n", read_group[i].name, read_group[i].age, read_group[i].sex);
			}
	}else{
		printf("Couldn't find the file personer.txt");
	}

	fclose(ifp);
	


}

person *make_person(person *p, int index, char *name, int age, char sex){

	strcpy(p[index].name, name);
	p[index].age = age;
	p[index].sex = sex;

	return p;

}

int count_lines(FILE *ifp){

int lines = 0;
int ch;

while(!feof(ifp)){
  ch = fgetc(ifp);
	  if(ch == '\n')
	  {
	    lines++;
	  }
}

/* Rewinding file so we get back */
rewind(ifp);

return lines;

}