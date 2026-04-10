#include <iostream>
#include <string>
using namespace std;

class Date
{
private:
    int year, month, day;

public:
    Date(int y = 2000, int m = 1, int d = 1) : year(y), month(m), day(d) {}
    int getYear() const { return year; }
    int getMonth() const { return month; }
    int getDay() const { return day; }
    void show() const { cout << year << "-" << month << "-" << day; }
};

class People
{
private:
    int id;
    string name;
    char gender;
    Date birthday;
    string dept;
    string pos;
    double salary;

public:
    People(int pid = 0, string pname = "无名", char pgender = 'M',
           Date b = Date(2000, 1, 1), string d = "未分配",
           string p = "员工", double s = 5000.0)
        : id(pid), name(pname), gender(pgender), birthday(b),
          dept(d), pos(p), salary(s)
    {
        cout << "构造 " << name << endl;
    }

    People(const People &p)
        : id(p.id + 10000), name("副本_" + p.name), gender(p.gender),
          birthday(p.birthday), dept(p.dept), pos("助理_" + p.pos),
          salary(p.salary * 0.8)
    {
        cout << "拷贝 " << name << endl;
    }

    ~People()
    {
        cout << "析构 " << name << endl;
    }

    inline void show() const
    {
        cout << "工号:" << id << " 姓名:" << name
             << " 性别:" << (gender == 'M' ? "男" : "女") << endl;
        cout << "生日:";
        birthday.show();
        cout << " 部门:" << dept << " 职位:" << pos
             << " 工资:" << salary << endl;
    }

    int getAge(int curYear = 2026) const
    {
        return curYear - birthday.getYear();
    }

    void up(string newPos = "高级员工", double add = 1000)
    {
        pos = newPos;
        salary += add;
        cout << name << " 升为 " << newPos << " 加薪" << add << endl;
    }

    void setId(int i) { id = i; }
    void setName(string n) { name = n; }
    int getId() const { return id; }
    string getName() const { return name; }
    double getSalary() const { return salary; }
};

int main()
{
    People p1;
    p1.show();

    Date bd(1995, 5, 15);
    People p2(1001, "张三", 'M', bd, "技术部", "工程师", 8000);
    p2.show();

    People p3 = p2;
    p3.show();

    cout << "张三年龄:" << p2.getAge() << endl;

    p2.up();
    p2.up("经理", 3000);
    p2.show();

    {
        People p4(1002, "李四", 'F', Date(1998, 8, 20), "财务部");
        p4.show();
    }

    return 0;
}
