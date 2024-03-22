#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
using namespace std;

struct Worker {
	char name[20], surname[20];
	char years[2];
	char number[10];
};

Worker* AddWorker(Worker employees[], int& size) {
	Worker people;

	cout << "Enter name "; cin >> people.name;
	cout << "Enter surname "; cin >> people.surname;
	cout << "Enter years "; cin >> people.years;
	cout << "Enter number "; cin >> people.number;

	size++;

	Worker* employ = new Worker[size];
	for (int i = 0; i < size - 1; i++) {
		strcpy(employ[i].name, employees[i].name);
		strcpy(employ[i].surname, employees[i].surname);
		strcpy(employ[i].years, employees[i].years);
		strcpy(employ[i].number, employees[i].number);
	}
	strcpy(employ[size - 1].name, people.name);
	strcpy(employ[size - 1].surname, people.surname);
	strcpy(employ[size - 1].years, people.years);
	strcpy(employ[size - 1].number, people.number);

	delete[] employees;
	return employ;
}

Worker* ChangeWorker(Worker employees[], int size, int index) {

	for (int i = 0; i < size; i++) {
		if (i = index) {
			cout << "Enter name "; cin >> employees[i].name;
			cout << "Enter surname "; cin >> employees[i].surname;
			cout << "Enter years "; cin >> employees[i].years;
			cout << "Enter number "; cin >> employees[i].number;
		}
	}
	return employees;
}

Worker* DeleteWorker(Worker employees[], int& size, int index) {

	size--; int r = 0;
	Worker* employ = new Worker[size];

	for (int i = 0; i < size + 1; i++) {
		if (i != index) {
			strcpy(employ[r].name, employees[i].name);
			strcpy(employ[r].surname, employees[i].surname);
			strcpy(employ[r].years, employees[i].years);
			strcpy(employ[r].number, employees[i].number);
			r++;
		}
	}
	delete[] employees;
	return employ;
}

Worker SearchingSurname(Worker employees[], int size, char surname[], bool& a) {
	for (int i = 0; i < size; i++) {
		if (strcmp(employees[i].surname, surname) == 0) {
			return employees[i];
		}
	}
	a = false;
	return employees[0];
}

int main() {
	char way[] = { "d:\\Valeria\\file.txt" };
	int size = 0;

	Worker* employees = new Worker[size];
	bool a = true;
	int select = 1, index, c[20]; char surname[20], years[2], s;
	Worker b;
	while (select != 0) {
		cout << "Select\n1 - Add worker\n2 - change worker\n3 - delete worker\n4 - searching with surname\n5 - searchin with years\n6 - print worker with surname\n7 - save in file"; cin >> select;

		if (select == 1) {
			employees = AddWorker(employees, size);
		}
		if (select == 2) {
			cout << "Which worker? "; cin >> index;
			employees = ChangeWorker(employees, size, index - 1);
		}
		if (select == 3) {
			cout << "Which worker? "; cin >> index;
			employees = DeleteWorker(employees, size, index - 1);
		}
		if (select == 4) {
			cout << "Enter surname "; cin >> surname;
			b = SearchingSurname(employees, size, surname, a);
			Print(b, a);
		}
	}
	return 0;
}