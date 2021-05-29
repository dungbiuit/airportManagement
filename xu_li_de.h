#pragma once
#include "ctdl.h"

//=================
void chuan_hoa_chu(string &a)
{
	/*int a = a.length();*/
	// |...tU...lAnh....|
	// |TU LANH|
	//xu li khoang trang dau
	while (a[0] == ' ')
	{
		a.erase(a.begin() + 0);
	}
	//xu li khoang trang cuoi
	if (a[a.length() > 1])
	{
		while (a[a.length() - 1] == ' ')
		{
			a.erase(a.begin() + a.length() - 1);
		}
	}
	//xu li khoang trang giua
	for (int i = 0; i < a.length(); i++)
	{
		if (a[i] == ' ' && a[i + 1] == ' ')
		{
			a.erase(a.begin() + i + 1);
			i--;
		}
	}
	//in hoa cac ki tu
	for (int i = 0; i < a.length(); i++)
	{
		if (a[i] >= 97 && a[i] <= 122)
		{
			a[i] -= 32;
		}
	}
}
void up_case_char(char &a)
{
	if (a >= 97 && a <= 122)
	{
		a -= 32;
	}
}

void ClassList_Liberate(ClassList &classList)
{
	for (int i = 0; i < classList.index; i++)
	{
		delete classList.classList[i];
	}
}
//=======================
//------------------
string ReturnSubjectIDInput()
{
	string subjectIDReturn;
	do
	{
		cout << "Input subject ID: ";
		cin.ignore();
		getline(cin, subjectIDReturn);
		if (subjectIDReturn.length() > MAX_SUBJECT_ID_LENGTH)
			cout << "\nID reached limited 15 characters, please type again!!!\n";
	} while (subjectIDReturn.length() > MAX_SUBJECT_ID_LENGTH);
	return subjectIDReturn;
}

string ReturnClassIDInput()
{
	string classIDReturn;
	cout << "Input class ID: ";
	cin.ignore();
	getline(cin, classIDReturn);
	return classIDReturn;
}

void LimitID_Exceed(string ID_ToCheck)
{
	if (ID_ToCheck.length() > MAX_SUBJECT_ID_LENGTH)
	{
		cout << "ID reached limited 15 characters";
	}
}

bool CheckExistSubject(SubjectList listToCheck, string subject_ID_ToCheck)
{
	for (int i = 0; i < listToCheck.index; i++)
	{
		if (listToCheck.subjectList[i].subjectID == subject_ID_ToCheck)
			return true;
	}
	return false;
}

bool CheckExistClass(ClassList listToCheck, string class_ID_ToCheck)
{
	for (int i = 0; i < listToCheck.index; i++)
	{
		if (listToCheck.classList[i]->classID == class_ID_ToCheck)
			return true;
	}
	return false;
}

void AddSubject(SubjectList &list)
{
	Subject subject;
	subject.subjectID = ReturnSubjectIDInput();
	if (CheckExistSubject(list, subject.subjectID))
	{
		cout << "Sorry, ID existed" << endl;
		return;
	}
	cout << "Input subject name : ";
	getline(cin, subject.subjectName);

	if (list.index > MAX_SUBJECT)
		return;
	list.subjectList[list.index] = subject;
	list.index++;
}

int GetSubjectIndexBySubjectID(SubjectList list, string subjectIDToFind)
{
	for (int i = 0; i < list.index; i++)
	{
		if (list.subjectList[i].subjectID == subjectIDToFind)
			return i;
	}
	return -1;
}

int GetClassIndexByClassID(ClassList list, string classIDToFind)
{
	for (int i = 0; i < list.index; i++)
	{
		if (list.classList[i]->classID == classIDToFind)
			return i;
	}
	return -1;
}

void DeleteSubject(SubjectList &listToChange, int indexToDelete)
{
	if (indexToDelete == -1)
	{
		cout << "\nID not Existed, can't delete !!!\n";
		return;
	}

	for (int i = indexToDelete + 1; i < listToChange.index; i++)
	{
		listToChange.subjectList[i - 1] = listToChange.subjectList[i];
	}

	listToChange.index--;
}

void DeleteClass(ClassList &listToChange, int indexToDelete)
{
	if (indexToDelete == -1)
	{
		cout << "\nID not Existed, can't delete !!!\n";
		return;
	}
	for (int i = indexToDelete + 1; i < listToChange.index; i++)
	{
		listToChange.classList[i - 1] = listToChange.classList[i];
	}
	listToChange.index--;
}

void PrintSubjectList(SubjectList list)
{
	for (int i = 0; i < list.index; i++)
	{
		cout << "Subject " << i + 1 << endl;
		cout << "  ID : " << list.subjectList[i].subjectID << endl;
		cout << "  Name : " << list.subjectList[i].subjectName << endl;
		cout << "-------------" << endl;
	}
}

void AddClass(ClassList &classListChange)
{
	Class *classPointer = new Class;
	classPointer->classID = ReturnClassIDInput();
	if (CheckExistClass(classListChange, classPointer->classID))
	{
		cout << "Sorry, ID existed" << endl;
		return;
	}
	cout << "Input class name : ";
	getline(cin, classPointer->className);

	if (classListChange.index > MAX_CLASS)
		return;
	classListChange.classList[classListChange.index] = classPointer;
	classListChange.index++;
}

void PrintClassList(ClassList list)
{
	for (int i = 0; i < list.index; i++)
	{
		cout << "Subject " << i + 1 << endl;
		cout << "  ID : " << list.classList[i]->classID << endl;
		cout << "  Name : " << list.classList[i]->className << endl;
		cout << "-------------" << endl;
	}
}

void menu()
{

	SubjectList subjectList;
	ClassList classList;
	bool check = true;
	while (check)
	{
		cout << "\n1. Add Subject" << endl;
		cout << "2. Delete Subject" << endl;
		cout << "3. Print Subject List" << endl;
		cout << "\n4. Add Class" << endl;
		cout << "5. Delete Class" << endl;
		cout << "6. Print Class List" << endl;
		cout << "0. Exit" << endl;

		int select;
		cout << "Your select is : ";
		cin >> select;

		switch (select)
		{
		case 1:
			AddSubject(subjectList);
			break;
		case 2:
		{
			string ID_ToCheck = ReturnSubjectIDInput();
			int indexOfSubjectID = GetSubjectIndexBySubjectID(subjectList, ID_ToCheck);
			DeleteSubject(subjectList, indexOfSubjectID);
			break;
		}

		case 3:
			PrintSubjectList(subjectList);
			break;

		case 4:
		{
			AddClass(classList);
			break;
		}
		case 5:
		{
			string ID_ToCheck = ReturnClassIDInput();
			int indexOfClassID = GetClassIndexByClassID(classList, ID_ToCheck);
			DeleteClass(classList, indexOfClassID);
			break;
		}
		case 6:
		{
			PrintClassList(classList);
			break;
		}

		case 0:
			check = false;
			break;
		}
	}
}

//===================SUBJECT===================
int ktra_trung_mon(string a, SubjectList subjectList)
{
	for (int i = 0; i < subjectList.index; i++)
	{
		if (subjectList.subjectList[i].subjectID == a)
		{
			return i;
		}
	}
	return -1;
}

void sap_xep_chen(SubjectList subjectList) // insertionSort();
{
	int index;
	string value_ma, value_ten;
	for (int i = 1; i < subjectList.index; i++)
	{
		index = i;
		value_ma = subjectList.subjectList[i].subjectID;
		value_ten = subjectList.subjectList[i].subjectName;
		while (index > 0 && subjectList.subjectList[index - 1].subjectID > value_ma)
		{
			subjectList.subjectList[index].subjectID = subjectList.subjectList[index - 1].subjectID;
			subjectList.subjectList[index].subjectName = subjectList.subjectList[index - 1].subjectName;
			index--;
		}
		subjectList.subjectList[index].subjectID = value_ma;
		subjectList.subjectList[index].subjectName = value_ten;
	}
}

void Subject_Add(SubjectList &subjectList)
{ // Struct_action

	Subject subject;
	cout << "\nNhap thong tin mon hoc : ";
	do
	{
		cout << "\nMa mon : ";
		cin.ignore();
		getline(cin, subject.subjectID);
		chuan_hoa_chu(subject.subjectID);
		if (subject.subjectID.length() > 15)
		{
			cout << "\nVuot qua 15 ki tu, nhap lai.";
		}

		while (ktra_trung_mon(subject.subjectID, subjectList) >= 0)
		{
			cout << "\nMa mon trung, xin nhap lai.";
			getline(cin, subject.subjectID);
		}
	} while (subject.subjectID.length() > 15);

	do
	{
		cout << "Ten Mon : ";
		getline(cin, subject.subjectName);
		chuan_hoa_chu(subject.subjectName);
		if (subject.subjectName.length() > 50)
		{
			cout << "\nDo dai vuot qua 50, nhap lai.";
		}
	} while (subject.subjectName.length() > 50);

	cout << "\nNhap thanh cong";
	subjectList.subjectList[subjectList.index] = subject;
	subjectList.index++;
}

void Subject_Delete(SubjectList &subjectList)
{
	string a;
	cout << "\nNHAP MA MON HOC BAN MUON XOA: ";
	cin.ignore();
	getline(cin, a);
	chuan_hoa_chu(a);
	int ktra_a = ktra_trung_mon(a, subjectList);
	if (ktra_a < 0)
	{
		cout << "\nMa mon khong ton tai";
	}
	else
	{
		for (int i = ktra_a; i < subjectList.index - 1; i++)
		{
			subjectList.subjectList[i].subjectID = subjectList.subjectList[i + 1].subjectID;
			subjectList.subjectList[i].subjectName = subjectList.subjectList[i + 1].subjectName;
		}
		subjectList.index--;
		cout << "\nXOA THANH CONG!";
	}
}

void Subject_Edit(SubjectList &subjectList)
{
	string a;
	cout << "\nNHAP MA MON BAN CAN HIEU CHINH: ";
	cin.ignore();
	getline(cin, a);
	chuan_hoa_chu(a);
	int ktra = ktra_trung_mon(a, subjectList);
	if (ktra < 0)
	{

		cout << "\nMA MON KHONG TON TAI!" << endl;
	}
	else
	{
		// ============== hieu chinh =================
		cout << "NHAP TEN MON: ";
		getline(cin, subjectList.subjectList[ktra].subjectName);
		chuan_hoa_chu(subjectList.subjectList[ktra].subjectID);
		chuan_hoa_chu(subjectList.subjectList[ktra].subjectName);
		cout << "DA~ THAY DOI THONG TIN MON HOC.";
		sap_xep_chen(subjectList);
	}
}

void Subject_Print(SubjectList subjectList)
{
	cout << "\nDANH SACH MON HOC";
	cout << "\n=======================================";
	for (int i = 0; i < subjectList.index; i++)
	{
		cout << "\n MA MON   :   " << subjectList.subjectList[i].subjectID;
		cout << "\n TEN MON  :   " << subjectList.subjectList[i].subjectName;
		cout << "\n---------------------------------------";
	}
}

void Subject_Menu(SubjectList &subjectList)
{
	bool kt = true;
	while (kt == true)
	{
		int lua_chon;
		system("cls");
		cout << "1. Them mon hoc. " << endl;
		cout << "2. Xoa mon hoc." << endl;
		cout << "3. Hieu chinh mon hoc." << endl;
		cout << "4. Xuat danh sach mon hoc." << endl;
		cout << "0. Thoat." << endl;
		cout << "Nhap lua chon: ";
		cin >> lua_chon;
		switch (lua_chon)
		{
		case 1:
		{
			if (subjectList.index >= MAX_SUBJECT)
			{
				cout << "So luong mon hoc vuot qua so luong cko phep (300), hay xoa bot truoc khi them vao!";
				system("pause");
			}
			else
			{
				system("cls");
				Subject_Add(subjectList);
				sap_xep_chen(subjectList); // sắp xếp mã môn học ngay sau khi nhập
				system("pause");
			}
			break;
		}
		case 2:
		{
			system("cls");
			Subject_Delete(subjectList);
			system("pause");
			break;
		}
		case 3:
		{
			system("cls");
			Subject_Edit(subjectList);
			system("pause");
			break;
		}
		case 4:
		{
			system("cls");
			Subject_Print(subjectList);
			system("pause");
			break;
		}
		case 0:
		{
			kt = false;
			break;
		}
		default:
			break;
		}
	}
}

//Student
void Student_Input(Student &studentToAdd)
{
	cout << "\nInput Student ID";
	cin >> studentToAdd.studentID;
	cout << "\nStudent last Name: ";
	cin >> studentToAdd.studentLastName;
	cout << "\nStudent first Name: ";
	cin >> studentToAdd.studentFirstName;
	cout << "\nType gender: ";
	cin >> studentToAdd.gender;
	studentToAdd.password = "123456";
}

void Student_Print(Student studentToPrint)
{
	cout << "\nStudent ID: " << studentToPrint.studentID;
	cout << "\nStudent last Name: " << studentToPrint.studentLastName;
	cout << "\nStudent first Name: " << studentToPrint.studentFirstName;
	cout << "\nStudent gender: " << studentToPrint.gender;
	cout << "\nStudent password: " << studentToPrint.password;
}

NodeStudent *Student_CreateNode()
{
	NodeStudent *newNodeStudent = new NodeStudent;
	if (newNodeStudent == NULL)
	{ // not enough RAM
		return NULL;
	}
	Student_Input(newNodeStudent->data);
	newNodeStudent->pNext = NULL;
	return newNodeStudent;
}

void Student_AddNodeToHeadList(NodeStudent *&pHead, NodeStudent *NodeToAdd)
{
	if (pHead->pNext == NULL)
	{
		pHead = NodeToAdd;
	}
	else
	{
		NodeToAdd->pNext = pHead;
		pHead = NodeToAdd;
	}
}

void Student_AddNodeToTailList(NodeStudent *&pHead, NodeStudent *NodeToAdd)
{
	if (pHead->pNext == NULL)
	{
		pHead = NodeToAdd;
	}
	else
	{
		for (NodeStudent *pTraverse = pHead;; pTraverse = pTraverse->pNext)
		{
			if (pTraverse->pNext == NULL)
			{
				pTraverse->pNext = NodeToAdd;
			}
		}
	}
}

void StudentList_PrintStudentList(NodeStudent *pHead)
{
	for (NodeStudent *pTraverse = pHead; pTraverse != NULL; pTraverse = pTraverse->pNext)
	{
		Student_Print(pTraverse->data);
		cout << endl;
	}
}

void StudentList_ShowMenu(){
	cout<<"1.Add a student : "<<"\n";
	cout<<"2.Print student list: "<<"\n";
	cout<<"3.Back";
}

void StudentList_RunMenu(StudentList listOfStudents){
	int selection = 0;
	while(selection != 0){
		switch (selection)
		{
		case 1:{
			Student newStudentToAdd;
			Student_Input(newStudentToAdd);
			break;
		}
		case 2:{
			StudentList 
			break;
		}
		
		default:
			break;
		}
	}
}
