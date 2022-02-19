/*
 * Tutorial 3 Jeopardy Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2015, <GROUP MEMBERS>
 * All rights reserved.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "questions.h"

// Initializes the array of questions for the game
void initialize_game(void)
{
    // initialize each question struct and assign it to the questions array
    strcpy(questions[0].category, categories[0]);
    strcpy(questions[0].question, "What does OOP stand for?");
    strcpy(questions[0].answer, "Object Oriented Programming");
    questions[0].value = 400;
    questions[0].answered = false;
    numQuestionsDefined++;

	strcpy(questions[1].category, categories[0]);
    strcpy(questions[1].question, "What is a loop that never ends called?");
    strcpy(questions[1].answer, "Infinite Loop");
    questions[1].value = 600;
    questions[1].answered = false;
    numQuestionsDefined++;

	strcpy(questions[2].category, categories[0]);
    strcpy(questions[2].question, "What technique is used for breaking a problem down into subproblems?");
    strcpy(questions[2].answer, "Recursion");
    questions[2].value = 800;
    questions[2].answered = false;
    numQuestionsDefined++;
    
    strcpy(questions[3].category, categories[1]);
    strcpy(questions[3].question, "What is the complexity of Merge Sort?");
    strcpy(questions[3].answer, "O(nlogn)");
    questions[3].value = 400;
    questions[3].answered = false;
    numQuestionsDefined++;

	strcpy(questions[4].category, categories[1]);
    strcpy(questions[4].question, "What is the search efficiency of a Hash Table?");
    strcpy(questions[4].answer, "O(1)");
    questions[4].value = 600;
    questions[4].answered = false;
    numQuestionsDefined++;

	strcpy(questions[5].category, categories[1]);
    strcpy(questions[5].question, "Which sorting algorithm uses a pivot element to partition an unsorted list?");
    strcpy(questions[5].answer, "Quick Sort");
    questions[5].value = 800;
    questions[5].answered = false;
    numQuestionsDefined++;

	strcpy(questions[6].category, categories[2]);
    strcpy(questions[6].question, "What is the name of the search process in a database?");
    strcpy(questions[6].answer, "Query");
    questions[6].value = 400;
    questions[6].answered = false;
    numQuestionsDefined++;

	strcpy(questions[7].category, categories[2]);
    strcpy(questions[7].question, "What is a required field that makes each record unique?");
    strcpy(questions[7].answer, "Primary Key");
    questions[7].value = 600;
    questions[7].answered = false;
    numQuestionsDefined++;

	strcpy(questions[8].category, categories[2]);
    strcpy(questions[8].question, "What is generally used for performing tasks such as creating/deleting relations?");
    strcpy(questions[8].answer, "Data Definition Language");
    questions[8].value = 800;
    questions[8].answered = false;
    numQuestionsDefined++;
}

// Displays each of the remaining categories and question dollar values that have not been answered
void display_categories(void)
{
    // print categories and dollar values for each unanswered question in questions array
    for (int i = 0; i < numQuestionsDefined; i++){
    	if(!questions[i].answered){
    		printf("%s - $%d\n", questions[i].category, questions[i].value);
    	}
    }
    
}

// Displays the question for the category and dollar value
bool display_question(char *category, int value)
{	
	int questionIndex = 0;
	for (int i = 0; i < numQuestionsDefined; i++){
		if (strcmp(questions[i].category, category) == 0 && questions[i].value == value && questions[i].answered == false){
			printf("%s - $%d\n", questions[i].question, value);
			return true;
		}
	}
	printf("Incorrect input\n");
	return false;
}

// Returns true if the answer is correct for the question for that category and dollar value
bool valid_answer(char *category, int value, char *answer)
{
	for (int i = 0; i < numQuestionsDefined; i++){
		if (strcmp(questions[i].category, category) == 0 && questions[i].value == value){
			questions[i].answered = true;
			numQuestionsAnswered++;
			if(strcmp(questions[i].answer, answer) == 0){
				return true;
			}
			printf ("Answer: %s\n", questions[i].answer);
			return false;
		}
	}
    return false;
}

// Returns true if the question has already been answered
bool already_answered(char *category, int value)
{
	for (int i = 0; i < numQuestionsDefined; i++){
		if (strcmp(questions[i].category, category) == 0 && questions[i].value == value){
			return questions[i].answered;
		}
	}
    	return false;
}

bool allQuestionsAnswered(void) 
{
	if (numQuestionsAnswered == numQuestionsDefined) {
		return true;
	}
	return false;
}