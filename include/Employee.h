#ifndef EMPLOYEE_H
#define EMPLOYEE_H


class Employee
{
    public:
        Employee();
        int id;
        char name[20];
        char department[20];
        void print();
        void getInput();
};

#endif // EMPLOYEE_H
