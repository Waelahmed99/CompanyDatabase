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
	cout << "Enter name : "; cin >> name;
    cout << "Enter department : "; cin >> department;
}
