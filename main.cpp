#include <iostream>
#include "Employee.h"
#include "Database.h"

using namespace std;

// Screen prototypes.
void welcomeScreen();
void choiceScreen();
void queryScreen();
void modifyScreen();

// Choices prototypes.
void mainChoice();
void queryChoice();
void modifyChoice();

/* Main code goes here -> */
int main() {
	mainChoice();
	return 0;
}

void mainChoice() {
welcomeScreen();
	int ch;
	Database db;
	while(true) {
		choiceScreen();
		cin >> ch;
		switch (ch) {
            // Add employee.
			case 1:
				system("clear");
				db.addEmp();
				break;
            // Queries.
			case 2:
				system("clear");
				queryChoice();
				break;
            // Modifiy data.
			case 3:
				system("clear");
			    modifyChoice();
				break;
            //End program.
			case 4:
				system("clear");
				cout << "Thank you! :)";
				exit(0);
				break;
			dafault:
				cout << "please Enter a valid number\n\n";
		}
	}
}

void queryChoice() {
	int ch;
	Database db;
	while(true) {
		queryScreen();
		cin >> ch;
		switch (ch) {
            // Show data.
			case 1:
				system("clear");
				db.showAll();
				break;
            // Show specific (ID).
			case 2:
				system("clear");
				db.showEmp(1);
				break;
            // Show specific (name).
			case 3:
				system("clear");
				db.showEmp(2);
				break;
            // Show specific (Department).
			case 4:
				system("clear");
				db.showEmp(3);
				break;
            case 5:
                system("clear");
                mainChoice();
                return;
			dafault:
				cout << "please Enter a valid number\n\n";
		}
	}
}

void modifyChoice() {
    int ch;
	Database db;
	while(true) {
		modifyScreen();
		cin >> ch;
		switch (ch) {
            // Modify data.
			case 1:
				system("clear");
				db.updateEmp();
				break;
            // Delete an employee.
			case 2:
				system("clear");
				db.deleteEmp();
				break;
            // Clear data.
			case 3:
				system("clear");
				db.clearData();
				break;
            case 4:
                system("clear");
                mainChoice();
                return;
			dafault:
                system("clear");
				cout << "please Enter a valid number\n\n";
		}
	}
}

// Just a greeting..
void welcomeScreen() {
	cout << "Welcome to our Company management system project! :)\n";
}

// User available choices.
void choiceScreen() {
	cout << "Please select an operation\n";
	cout << "1.Add employee\n";
	cout << "2.Query\n";
	cout << "3.Modify data\n";
	cout << "4.End program\n";
}

// Queries.
void queryScreen() {
	cout << "Please select query operation\n";
	cout << "1.Show all data\n";
	cout << "2.using id\n";
	cout << "3.using name\n";
	cout << "4.using department\n";
	cout << "5.Go back\n";
}

// Modify data - delete data.
void modifyScreen() {
    cout << "Please select modify operation\n";
    cout << "1.Modify an employee\n";
    cout << "2.Delete an employee\n";
    cout << "3.Delete all data\n";
    cout << "4.Go back\n";
}
