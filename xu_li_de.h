#pragma once
#include "ctdl.h"

//------------------
string ReturnSubjectIDInput(){
	string subjectIDReturn;
	do{
		cout<<"Input subject ID: ";
		cin.ignore();
		getline(cin, subjectIDReturn);	
		if(subjectIDReturn.length() > MAX_SUBJECT_ID_LENGTH)
			cout<<"\nID reached limited 15 characters, please type again!!!\n";	
	}while(subjectIDReturn.length() > MAX_SUBJECT_ID_LENGTH); 	
	return subjectIDReturn;
}

string ReturnClassIDInput(){
	string classIDReturn;
		cout<<"Input class ID: ";
		cin.ignore();
		getline(cin, classIDReturn);	 	
	return classIDReturn;
}


void LimitID_Exceed(string ID_ToCheck){
	if(ID_ToCheck.length() > MAX_SUBJECT_ID_LENGTH){
		cout<<"ID reached limited 15 characters";
	}
}

bool CheckExistSubject(SubjectList listToCheck, string subject_ID_ToCheck){
	for(int i = 0; i < listToCheck.index; i++){
		if(listToCheck.subjectList[i].subjectID == subject_ID_ToCheck)
			return true;
	}
	return false;
}

bool CheckExistClass(ClassList listToCheck, string class_ID_ToCheck){
	for(int i = 0; i < listToCheck.index; i++){
		if(listToCheck.classList[i]->classID == class_ID_ToCheck)
			return true;
	}
	return false;
}


void AddSubject(SubjectList &list){
	Subject subject;
	subject.subjectID = ReturnSubjectIDInput();
	if(CheckExistSubject(list, subject.subjectID)){
		cout<<"Sorry, ID existed"<<endl;
		return;
	}
	cout<<"Input subject name : ";
	getline(cin, subject.subjectName);
	
		if(list.index > MAX_SUBJECT) return;
	list.subjectList[list.index] = subject;
	list.index++;
}

int GetSubjectIndexBySubjectID(SubjectList list, string subjectIDToFind){
	for(int i = 0; i < list.index; i++){
		if(list.subjectList[i].subjectID == subjectIDToFind)
			return i;
	}
	return -1;
}

int GetClassIndexByClassID(ClassList list, string classIDToFind){
	for(int i = 0; i < list.index; i++){
		if(list.classList[i]->classID == classIDToFind)
			return i;
	}
	return -1;
}

void DeleteSubject(SubjectList &listToChange, int indexToDelete){
	if(indexToDelete == -1){
		cout<<"\nID not Existed, can't delete !!!\n";
		return;
	}
	
	for(int i = indexToDelete + 1; i < listToChange.index; i++){
		listToChange.subjectList[i-1] = listToChange.subjectList[i];
	}
	
	listToChange.index--;
}

void DeleteClass(ClassList &listToChange, int indexToDelete){
	if(indexToDelete == -1){
		cout<<"\nID not Existed, can't delete !!!\n";
		return;
	}
	for(int i = indexToDelete + 1; i < listToChange.index; i++){
		listToChange.classList[i-1] = listToChange.classList[i];
	}
	listToChange.index--;
}

void PrintSubjectList(SubjectList list){
	for(int i = 0; i < list.index; i++){
		cout<<"Subject "<<i+1<<endl;
		cout<<"  ID : "<<list.subjectList[i].subjectID<<endl;
		cout<<"  Name : "<<list.subjectList[i].subjectName<<endl;
		cout<<"-------------"<<endl;
	}
}

void AddClass(ClassList &classListChange){
	Class *classPointer = new Class;
	classPointer->classID = ReturnClassIDInput();
	if(CheckExistClass(classListChange, classPointer->classID)){
		cout<<"Sorry, ID existed"<<endl;
		return;
	}
	cout<<"Input class name : ";
	getline(cin, classPointer->className);
	
		if(classListChange.index > MAX_CLASS) return;
	classListChange.classList[classListChange.index] = classPointer;
	classListChange.index++;
}

void PrintClassList(ClassList list){
	for(int i = 0; i < list.index; i++){
		cout<<"Subject "<<i+1<<endl;
		cout<<"  ID : "<<list.classList[i]->classID<<endl;
		cout<<"  Name : "<<list.classList[i]->className<<endl;
		cout<<"-------------"<<endl;
	}
}


void menu(){
	
	SubjectList subjectList;
	ClassList classList;
	bool check = true;
	while(check){
		cout<<"\n1. Add Subject" << endl;
		cout<<"2. Delete Subject" << endl;
		cout<<"3. Print Subject List"<<endl;
		cout<<"\n4. Add Class" << endl;
		cout<<"5. Delete Class" << endl;
		cout<<"6. Print Class List"<<endl;
		cout<<"0. Exit"<<endl;
		
		int select;
		cout<<"Your select is : ";
		cin>>select;
		
		switch(select){
			case 1:
				AddSubject(subjectList);
				break;
			case 2:{
				string ID_ToCheck = ReturnSubjectIDInput();
				int indexOfSubjectID = GetSubjectIndexBySubjectID(subjectList, ID_ToCheck);
				DeleteSubject(subjectList, indexOfSubjectID);			
				break;
			}
				
			case 3:
				PrintSubjectList(subjectList);
				break;
			
			case 4:{
				AddClass(classList);
				break;
			}
			case 5:{
				string ID_ToCheck = ReturnClassIDInput();
				int indexOfClassID = GetClassIndexByClassID(classList, ID_ToCheck);
				DeleteClass(classList, indexOfClassID);			
				break;
			}
			case 6:{
				PrintClassList(classList);
				break;
			}
			
			case 0:
				check = false;
				break;
				
		}
	}	
}







