#include <iostream>
#include <string>
using namespace std;

class Document
{
protected:
    string name;

public:
    Document(const string &n = "") : name(n)
    {
        cout << "Document 构造函数调用，name = " << name << endl;
    }
    virtual ~Document()
    {
        cout << "Document 析构函数调用" << endl;
    }
    string getName() const { return name; }
};

class Book : public Document
{
private:
    int pageCount;

public:
    Book(const string &n = "", int pages = 0) : Document(n), pageCount(pages)
    {
        cout << "Book 构造函数调用，pageCount = " << pageCount << endl;
    }
    ~Book()
    {
        cout << "Book 析构函数调用" << endl;
    }
    int getPageCount() const { return pageCount; }
};

int main()
{
    Book b("C++ Primer", 500);
    cout << "书名: " << b.getName() << ", 页数: " << b.getPageCount() << endl;
    return 0;
}
