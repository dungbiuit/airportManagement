#include <iostream>
#include<string>
using namespace std;

const int MAX_SUBJECT = 300;
const int MAX_CLASS = 500;


struct Subject{
	string subjectID; //key // only 15 characters
	string subjectName;
};

struct SubjectArray{
	Subject subjectArray[MAX_SUBJECT];	
	int numberOfCurrentSubjects = 0;
};

struct StudentName{
	string lastName;
	string firstName;
};


struct Student{
	string studentID; //key
	StudentName nameOfStudent;
	string gender;
	string password;
	ScoreList scorePointer;	// <=> use pHead to go to each node in List
};

struct NodeStudent{
	Student studentData;
	nodeStudent *pNext;
};

struct StudentList{
	nodeStudent *pHead = NULL;
	nodeStudent *pTail;
};

struct Class{
	string classID; //key
	string className;
	StudentList listOfStudents; // struct already has pointer
};

struct ClassList{
	Class *classPointerArray[MAX_CLASS];
	int numberOfCurrentClasses = 0;
};

struct Score{
	string subjectID; //key
	float score;
};

struct NodeScore{
	Score score;
	nodeScore *pNext;
};

struct ScoreList{
	nodeScore *pHead = NULL;
	nodeScore *pTail;
};

struct Questionnaire{
	int questionID; // key
	string subjectID;
	string content;
	string A, B , C, D;	// Content of each answers
	char answer;
};

int main(int argc, char** argv) {
	
	SubjectArray anArray;
	ClassList listOfClass;
	ScoreList listOfScore;
	
	
	return 0;
}
