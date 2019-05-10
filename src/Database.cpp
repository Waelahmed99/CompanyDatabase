#include "Database.h"
#include <iostream>
#include <fstream>
#include "Employee.h"
#include <string.h>

using namespace std;

Database::Database() {
    fileName = "Employees.txt";
}

/* Files operations go here -> */

// Add new employee.
void Database::addEmp() {
	fstream file;
	file.open(fileName, ios::app);
	Employee emp;
	emp.getInput();
	if (!isIdExists(emp.id)) {
        file.write((char*)&emp, sizeof (emp));
        cout << "Employee added successfully\n\n";
	}
    else
        cout << "Id already exists, request denied!\n\n";
    file.close();
}

bool Database::isIdExists(int recId) {
    fstream file;
	file.open(fileName, ios::in);
    Employee emp;
    while (!file.eof()) {
        file.read((char*)&emp, sizeof(emp));
        if (emp.id == recId)
            return true;
    }
    return false;
}

// Show all saved data.
void Database::showAll() {
    fstream file;
    file.open(fileName, ios::in);
    file.seekg(0);
    Employee emp;
    int id = 0;
    bool visited = false;
    while (!file.eof()) {
        file.read((char*)&emp, sizeof(emp));
        if(id != emp.id && emp.id != -1) {
            emp.print();
            id = emp.id;
            visited = true;
        }
    }
    if (!visited)
        cout << "No data\n\n";
    file.close();
}

// Show specific employee.
void Database::showEmp(int mode) {
	fstream file;
	file.open(fileName, ios::in);
	Employee emp;
	int id;
	char name[20];
	char dep[20];
	if (mode == 1) {
        cout << "Enter id you want to search for : "; cin >> id;
    }
	else if (mode == 2) {
        cout << "Enter name you want to search for : "; cin >> name;
    }
    else if (mode == 3) {
	    cout << "Enter department you want to search for : "; cin >> dep;
    }

    int lastId = 0;
    bool visited = false;
	while (!file.eof()) {
		file.read((char*)&emp, sizeof (emp));
		if (mode == 1) {
            if (emp.id == id && emp.id != lastId && emp.id!=-1) {
                emp.print();
                lastId = emp.id;
                visited = true;
            }
		} else if (mode == 2) {
            string s1(emp.name), s2(name);
            if ((strcmp(name, emp.name) == 0 || s1.find(s2) != std::string::npos)
                    && emp.id != lastId && emp.id!=-1) {
                emp.print();
                lastId = emp.id;
                visited = true;
            }
		} else if (mode == 3) {
            if (strcmp(dep, emp.department) == 0 && emp.id != lastId && emp.id!=-1) {
                emp.print();
                lastId = emp.id;
                visited = true;
            }
		}
	}
	if (!visited)
        cout << "No such record\n\n";
	file.close();
};

// Search for an existing employee.
void Database::searchEmp() {
	fstream file;
	Employee emp;
	char name[20];
	file.open(fileName, ios::in);

	cout << "Enter the name you want to search for \n";
	cin >> name;

	bool found = false;
	while (!file.eof()) {
		file.read((char*)&emp, sizeof(emp) );
		if (strcmp(emp.name, name) == 0) {
			emp.print();
			found = true;
			break;
		}
	}
	if (!found) {
		cout << "no such name\n\n";
	}
	file.close();
}

// Update an existing employee.
void Database::updateEmp () {
	fstream file;
	Employee emp;
	int id;
	cout << "Enter id to be updated : \n";
	cin >> id;

	file.open(fileName, ios::in | ios::out);
	while (!file.eof()) {
		file.read((char*)&emp, sizeof (emp) );
		if (emp.id == id && emp.id != -1) {
            char x;
            cin.get(x);
			cout << "\n\nEnter the new name : "; cin.getline(emp.name, 20, '\n');
			cout << "\nEnter the new department : "; cin.getline(emp.department, 20, '\n');
			file.seekp(file.tellg() - sizeof(emp), ios::beg);
			file.write((char*)&emp, sizeof(emp));
			break;
		}
	}
	file.close();
}

// Delete an existing employee.
void Database::deleteEmp() {
	fstream file;
	file.open(fileName, ios::in | ios::out);
	Employee emp;
	int id;
	cout << "Enter id to be deleted :\n";
	cin >> id;
	file.seekg(0);
	bool deleted = false;
	while(!file.eof()) {
		file.read((char*) &emp, sizeof(emp));
		if (emp.id == id) {
            emp.id = -1;
            file.seekp(file.tellg() - sizeof(emp), ios::beg);
            file.write((char*)&emp, sizeof(emp));
            deleted = true;
            cout << "Employee deleted\n\n";
            break;
		}
	}
	if (!deleted)
        cout << "No such id\n\n";
	file.close();
}

// Clear all File data.
void Database::clearData() {
    ofstream  file;
    file.open(fileName, ios::out | ios::trunc);
    file.close();

    cout << "Data deleted\n\n";
}
