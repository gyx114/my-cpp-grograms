#include <stdio.h>

struct Student
{                     // 学生信息结构体
    int num;          // 学号
    const char *name; // 姓名，字符串对象，将在第6章详细介绍
    char sex;         // 性别
    int age;          // 年龄

    private : int hello;
};

int main()
{
    Student stu = {97001, "Lin Lin", 'F', 19};
    printf("Num:  %d\n", stu.num);
    printf("Num:  %s\n", stu.name);
    printf("Num:  %c\n", stu.sex);
    printf("Num:  %d\n", stu.age);
    return 0;
}
