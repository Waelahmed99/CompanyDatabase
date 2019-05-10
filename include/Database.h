#ifndef DATABASE_H
#define DATABASE_H
#include <iostream>

class Database
{
    public:
        Database();
        std::string fileName;
        void addEmp();
        void showAll();
        void showEmp(int);
        void searchEmp();
        void updateEmp();
        void deleteEmp();
        void clearData();
        bool isIdExists(int id);

    private:
};

#endif // DATABASE_H
