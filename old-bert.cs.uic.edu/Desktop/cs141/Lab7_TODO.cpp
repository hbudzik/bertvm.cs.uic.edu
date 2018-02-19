/*
Arrays of Structs
You'll note that the code below does not actually use arrays of structs.  You will be correcting this deficiency.
Follow my instruction step by step, so that you could get high score and learn knowledge.

1. Compile, run and play this program, get the general idea of what this program tries to do.
 
2. Read through the code, get to know the structure, i.e. the function decomposition of this program. 

3. search "TODO_1" in this code. Finish the definition of Person_struct. 
   Note: Please do use typedef together with struct. This allows you to use the definition "Person" 
   in place of "struct Person_struct" which you will use in other C programs.
   
   Reference: Zybooks, Participation Activity7.1.2: A struct enables creating a variable with data members.
   
4. search "TODO_2" in this code. Change the original readInValues() function as readInValues_old()
   Refer to origial readInValues(), replace the corresponding parts using struct type, or struct data member. 
   The parameter of the function as already given, you do not need to change them. 

   Reference: Zybooks,  Figure 7.3.1: An array of struct items rather than two arrays of more basic types.

   For now, stage 1 is finished, you could get 1 points. 

5. search "TODO_3" in this code. Change the original displayValues() function as displayValues_old()
   Refer to original displayValues(), replace the corresponding parts using struct type, or struct data member.

   Reference: Zybooks,  Figure 7.3.1: An array of struct items rather than two arrays of more basic types.

6. change corresponding parts of the main() function, so that you could call the two function you created just 
   now correctly. 
   if it works exactly the same as original program, stage 2 is finished, you could get 2 points. 

7. Extra Credit:
   If you could use any sort algorithm to make displayValues() function to display in alphabetical order (You 
   could search online for sample code you would like to use), you get 3 points for this lab. Gook Luck !!
*/

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <ctype.h>


// TODO_1 : use typedef to define Person_struct as Person below
//          For the max length of name, you could use const int NAME_LENGTH;


typedef struct Person_struct{
	char name[15];
	char gender;
	int age;	
}Person;


//TODO_2
int readInValues(Person personList[], int pCount){
	
	if (pCount > 3){
		printf("School is full.  Try next year.");
		return -1;
	}
	
	printf("Please enter your first name: ");
 	scanf(" %s", personList[pCount].name);  //If you are wondering, the 14 is a maximum width specifier.
  
 	printf("\nPlease enter a gender(M or F): ");
  	scanf(" %c", &personList[pCount].gender);
 
	printf("\nPlease enter an age: ");
	scanf(" %d", &personList[pCount].age);
	
	return 0;
}

/* Function : readInValues
 * --------------------------------------------------------------------------------
 * Takes in a given name, gender, and age and adds them to the three given arrays.
 * 
 * nameArr : array that stores name
 * genderArr :  array that stores gender
 * ageArr : array that stores age
 * pCount : the index of student in the array, which will increase by one, each time an entry is inserted.
 */
/*
int readInValues_old(char nameArr[][15], char genderArr[], int ageArr[], int pCount){
 
  if(pCount > 3){
    printf("School is full.  Try next year.");
    return -1;
  }
  
  printf("Please enter your first name: ");
  scanf(" %14s", &nameArr[pCount][0]);  //If you are wondering, the 14 is a maximum width specifier.
  
  printf("\nPlease enter a gender(M or F): ");
  scanf(" %c", &genderArr[pCount]);
 
  printf("\nPlease enter an age: ");
  scanf(" %d", &ageArr[pCount]);
  
  return 0;
 }//end  readInValues()
*/

//TODO_3
void displayValues(int numStudents, Person personList[]){
	
	int i;
	printf("\nCurrent Students:\n");
	for (i = 0; i < numStudents; ++i){
		
		printf("\n%d: ", i);
		printf(" Name: %s,", personList[i].name);
		printf(" Gender: %c,", personList[i].gender);
		printf(" Age: %d,", personList[i].age);
		printf("\n");
		
		printf("First letter of this name is: %c", personList[i].name[1]);
		
			
	}
	
}
//********** display alpha
void displayValuesAlpha(int numStudents, Person personList[]){
	int i, j;
	char t[50];

   for (i = 1; i < numStudents + 1; i++) {
      for (j = 1; j < 5; j++) {
         if (strcmp(personList[j - 1], personList[j]) > 0) {
            strcpy(t, personlist[j - 1]);
            strcpy(personList[j - 1], personList[j]);
            strcpy(personList[j], t);
         }
      }
   }
	
}

  char s[5][20], t[20];
   int i, j;
   clrscr();
 
   printf("\nEnter any five strings : ");
   for (i = 0; i < 5; i++)
      scanf("%s", s[i]);
 
   for (i = 1; i < 5; i++) {
      for (j = 1; j < 5; j++) {
         if (strcmp(s[j - 1], s[j]) > 0) {
            strcpy(t, s[j - 1]);
            strcpy(s[j - 1], s[j]);
            strcpy(s[j], t);
         }
      }
   }

/* Function : displayValues
 * ----------------------------
 * Displays all stored values
 
void displayValues_old(int numStudents, char nameArr[][15], char genderArr[], int ageArr[]){
   int i;
   printf("\nCurrent Students:");
   for(i = 0; i < numStudents; ++i){
      printf("\n%d . Name: %s, Gender: %c, Age: %d", i,  nameArr[i], genderArr[i], ageArr[i]);   
   }
}//end displayValues()
*/

int main(){ 
  
  //Parallel arrays.  If only we knew how to use an array of structs instead.
  // suppose the system could only contain 4 data entries.
  /*char firstName[4][15];
  char gender[4];
  int age[4];
  
  */
  Person personList[4];
  char quit = '_';
   
  int i = 0;
  while(i < 4 && quit != 'Q'){
     readInValues(personList, i);
     ++i;
     
     displayValues(i, personList);
     //displayValuesAlpha(i, personList);
     printf("\npress 'Q' to quit, or 'C' to input another student.");
     scanf(" %c", &quit);
  }
 // displayValuesAlpha(4, personList);
  
  
  return 0;
}
