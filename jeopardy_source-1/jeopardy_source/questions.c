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
    
    strcpy(questions[1].category, categories[1]);
    strcpy(questions[1].question, "What is the complexity of Merge Sort");
    strcpy(questions[1].answer, "O(nlogn)");
    questions[1].value = 600;
    questions[1].answered = false;
    numQuestionsDefined++;
}

// Displays each of the remaining categories and question dollar values that have not been answered
void display_categories(void)
{
    // print categories and dollar values for each unanswered question in questions array
    for (int i = 0; i < numQuestionsDefined; i++){
    	if(!questions[i].answered){
    		printf("%s - $%d\n\n", questions[i].category, questions[i].value);
    	}
    }
    
}

// Displays the question for the category and dollar value
void display_question(char *category, int value)
{	
	int questionIndex = 0;
	for (int i = 0; i < numQuestionsDefined; i++){
		if (strcmp(questions[i].category, category) == 0 && questions[i].value == value){
			printf("%s - $%d\n", questions[i].question, value);
			break;
		}
	}
}

// Returns true if the answer is correct for the question for that category and dollar value
bool valid_answer(char *category, int value, char *answer)
{
	for (int i = 0; i < numQuestionsDefined; i++){
		if (strcmp(questions[i].category, category) == 0 && questions[i].value == value){
			if(strcmp(questions[i].answer, answer) == 0){
				questions[i].answered = true;
				numQuestionsAnswered++;
				return true;
			}
			questions[i].answered = true;
			printf ("Answer: %s", questions[i].answer);
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