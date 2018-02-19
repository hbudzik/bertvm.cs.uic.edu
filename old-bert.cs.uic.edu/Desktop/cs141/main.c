/* Write your functions here. Do not use string.h functions.*/
#include <stdio.h>
/*
 Split Strings
 
 Announcements
 
 There will be 5 minutes’ quiz available on Blackboard at the beginning of each of the lab session. Please sign in to your Blackboard account and finish the quiz individually. Most of your time should be focused on finishing the lab activity question.
 
 You must work with a single partner i.e., in a group of 2 (If there are an odd-number of students in the class, your TA will make an adjustment). You must take turns being the “driver” and the “navigator” while working on the lab activity.
 
 Lab Grading policy 
 
 You must work with a partner for credit. 
 
 There are 3 questions. The maximum score is 2, where each question is worth 1 point. Question 3 is extra credit. To get a grade, you must get graded by the TA in the lab before the lab ends. TAs will not be grading after the 50 minutes of the lab session are over. Once you finish your work, please raise your hand and show your work to the TA during the last 10 minutes of lab or whenever you finish, the earlier of the two.
 
 
 Lab Activity Overview
 
 You are required to implement "Split Function" from scratch. In many programming languages, to split a sentence into a word list, you just need to use split() function. 
 For instance in Python:
 
 sent = "The quick brown fox jumped over the lazy dog"
 word_list = sent.split()  ## comment: word_list is ['The', 'quick', 'brown', 'fox', 'jumpled', 'over', 'the', 'lazy', 'dog']
 
 Python as a more higher level script language, it is written in C language. Today, we will explore how to explore how to do similar work of split function from scratch. Note that, our way of implement split() function might not be the best way. Maybe it is not efficient in both speed and memory. We just explore one way of implementation.
 
 Tasks:
 
 1. Print each word of the original string on one line.
 You could use whatever method to traverse the string which is a char array to achieve this goal to get 1 point. 
 You might need length() function, which returns the length of a string. You could refer to the solution of Lab-8 for length() function.
 
 2. Write a split function that takes the string as one parameter, returns a 2-D array, which stores each word at each row. Store words in a 2-D array, remembering to add '\0' character at the last of the string
 to indicate the end of each word.
 
 3. Using the 2-D array which stores a word in each row to find out the longest word.
 
 Please search TODO in the attached C file to find the functions which need to be finished. Please use the required parameters without changing it.  
 
 Please download the attached C code and start building on it to finish today's lab.
 */
#define MAX_WORD_SIZE 30

//int countWords(char board[]);

int length(char* sent) {
    int i = 0;
    for (i = 0; sent[i] != '\0'; i++);
    return i;
}

/*
 TODO Task 1.
 @param: sent is the first pointer of the char array
 */
void printWords(char* sent) {
	int i;
	
	for (i = 0; i < 100; i++) {
		
		if (sent[i] == '\0') {
			break;
		}
		printf("%c", sent[i]);
		
		if (sent[i] == ' ') {
			printf("\n");
		}
	}
	
	
}


/*
 TODO Helper function of Task 2.
 @Return: the number of words in a sentence. 
 
 Notes: You could assume that the sentence is will written, all words are seperated by a single space.
 Just do experiment on the sentence given in the main function. 
 */
int countWordsOfSent(char* sent) {
	int i;
	int count = 1;
	printf("\n");
	
	for (i = 0; i < 100; i++) {
		
		if (sent[i] == '\0') {
			break;
		}
		
		if (sent[i] == ' ') {
			count++;
		}
	}
	
	return count;
	
}


/*
 TODO Task 2.
 Do not change the parameter of this function.
 Store the splitted words in the 2-D array, which is named words.
 Remember to add '\0' to the last word.
 */
void split(char* sent, char words[][MAX_WORD_SIZE]) {
	// int count = countWordsOfSent(sent);
	int i = 0; 
	int j = 0;
	int row = 0;
	for (i = 0; i < 100; i++) {
		if (sent[i] == ' ') {
			words[row][j] = '\0';
			row++;
			j=0;
		}
		
		else {
			words[row][j] = sent[i];
			j = j+1;
		}
		
		if (sent[i] == '\0') {
			break;
		}
				
	}
		
}


/*
 Helper function of the Task 2. 
 You could use it to verify if task 2 is correctly implemented. 
 */
void print2DWords(int wordNum, char array[][MAX_WORD_SIZE]) {
    int i; 
    for (i = 0; i < wordNum; i++) {
        printf("%s\n", array[i]);
    }
}


/*
 TODO: Task 3
 You do not need to return the longest word. Just print it out in this function. 
 */
void displayLongestWord(int wordNum, char word[][MAX_WORD_SIZE]) {
	int i;
	int j;
	int maxLetters = 0;
	int maxLettersIndex = 0;
	int counter = 0;
	for (i = 0; i < wordNum; i++) {
		counter = 0;
		j=0;
		while (word[i][j] != '\0') {
			counter++;
			j++;
			
			if (counter >= maxLetters) {
				maxLetters = counter;
				maxLettersIndex = i;
			}
		}
		

	}

	printf("Longest word is: %s\n", word[maxLettersIndex]);
	
}

int main() {
    char sent[] = "The quick brown fox jumped over the lazy dog";
    printf("%s\n", sent);
    printWords(sent);
	int wordNum = countWordsOfSent(sent);
    printf("There are %d words.\n", wordNum);
	
    // Define the 2-D array to store word at each row with character '\0' as the last character. 
    // You could assume that the maximum word lenght is MAX_WORD_SIZE.
    char words[wordNum][MAX_WORD_SIZE];  
	split(sent, words);
    print2DWords(wordNum, words);
    displayLongestWord(wordNum, words);
	
	return 0;
}