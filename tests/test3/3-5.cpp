#include <iostream>
using namespace std;

class Student
{
private:
    int stid;
    static int numOfStudents;

public:
    void printAddr()
    {
        cout << &stid << " " << &numOfStudents << endl;
    }
    Student(int id) : stid(id)
    {
        numOfStudents++;
    }

    ~Student()
    {
        numOfStudents--;
    }

    void print()
    {
        cout << "学号: " << stid
             << "，当前学生总数: " << numOfStudents << endl;
    }

    static int printNumOfStudents()
    {
        cout << "当前学生总数: " << numOfStudents << endl;
        return numOfStudents;
    }
};

int Student::numOfStudents = 0;

int main()
{
    Student::printNumOfStudents();
    Student s1(0);
    Student s2(1);
    {
        Student s3(2);
        Student::printNumOfStudents();
    }
    Student::printNumOfStudents();
    s1.printNumOfStudents();
    s1.printAddr();
    s2.printAddr();
    return 0;
}
