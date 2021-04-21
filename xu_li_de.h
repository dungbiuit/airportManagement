#pragma once
#include "ctdl.h"
void AddSubject(SubjectList &list);
void PrintSubjectList(SubjectList list);

//------------------
void menu(){
	
	SubjectList subjectList;
	
	bool check = true;
	while(check){
		cout<<"1. Add Subject" << endl;
		cout<<"2. Print Subject List"<<endl;
		cout<<"0. Exit"<<endl;
		
		int select;
		cout<<"Your select is : ";
		cin>>select;
		
		switch(select){
			case 1:
				AddSubject(subjectList);
				break;
			case 2:
				PrintSubjectList(subjectList);
				break;
			case 0:
				check = false;
				break;
				
		}
	}	
}

void AddSubject(SubjectList &list){
	Subject subject;
	cout<<"Input ID : ";
	cin.ignore();
	getline(cin, subject.subjectID);
	cout<<"Input Name : ";
	getline(cin, subject.subjectName);
	list.subjectList[list.index] = subject;
	list.index++;
}

void PrintSubjectList(SubjectList list){
	for(int i = 0; i < list.index; i++){
		cout<<"Subject "<<i+1<<endl;
		cout<<"  ID : "<<list.subjectList[i].subjectID<<endl;
		cout<<"  Name : "<<list.subjectList[i].subjectName<<endl;
		cout<<"-------------"<<endl;
	}
}



