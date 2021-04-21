#pragma once
#include <iostream>
#include <string>
#include <conio.h>
#include <stdio.h>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MAX_SUBJECT = 300;
const int MAX_CLASS = 500;

//============Subject============
struct Subject{
	string subjectID; //key // only 15 characters
	string subjectName;
};

struct SubjectList{
	Subject subjectList[MAX_SUBJECT];	
	int index = 0;
};

//============Score============
struct Score{
	string subjectID; //key
	float score;
};

struct NodeScore{
	Score data;
	NodeScore *pNext;
};

struct ScoreList{
	NodeScore *pHead = NULL;
	int index = 0;
};

//============Student============
struct Student{
	string studentID; //key
	string studentLastName;
	string studentFirstName;
	string gender;
	string password;
	ScoreList scoreList;	// <=> use pHead to go to each node in List
};

struct NodeStudent{
	Student data;
	NodeStudent *pNext;
};

struct StudentList{
	NodeStudent *pHead = NULL;
	int index = 0;
};

//============Class============
struct Class{
	string classID; //key
	string className;
	StudentList studentList; // struct already has pointer
};

struct ClassList{
	Class *classList[MAX_CLASS];
	int index = 0;
};

//============Questionnaire============
struct Questionnaire{
	int questionnaireID;
	string subjectID;
	string content;
	string answerA;
	string answerB;
	string answerC;
	string answerD;
	char answerCorrect;
};

struct NodeQuestionnaire{
	Questionnaire data;
	NodeQuestionnaire *pLeft;
	NodeQuestionnaire *pRight;
};

struct QuestionnaireList{
	NodeQuestionnaire *tree = NULL;
	int index = 0;
};


