#include "Employee.h"
#include <iostream>

using namespace std;

Employee::Employee() {

}

void Employee::print() {
    cout << "id = " << id << "  " << "name = " << name << "  ";
    cout << "department = " << department << endl << endl;
}

void Employee::getInput() {
    cout << "Enter id : "; cin >> id;
    char x;
    cin.get(x);
	cout << "Enter name : "; cin.getline(name, 20, '\n');
    cout << "Enter department : "; cin.getline(department, 20, '\n');
}
