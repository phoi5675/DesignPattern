#include <iostream>
#include <string>
#include <vector>
using namespace std;

class no_implementation {};
class Base
{
    string title;
    int depth;
public:
    Base(string title) : title(title) {}

    string getTitle() { return title; }

    virtual void setDepth(int depth) { this->depth = depth; }

    virtual int getDepth() { return depth; }
    virtual int getSize() = 0;
    virtual void print() = 0;

    virtual void add(Base* b) { throw no_implementation(); }

    virtual ~Base() {}
};

class Folder : public Base
{
    vector<Base*> v;
    int _depth = 0;
public:
    Folder(string title) : Base(title) {}

    int getSize() override
    {
        int totalSize = 0;
        for (Base* b : v)
        {
            totalSize += b->getSize();
        }
        return totalSize;
    }
    void print() override
    {
        cout << '[' + getTitle() + ']' << endl;

        for (Base* b : v)
        {
            cout << string(getDepth() + 1, '\t');
            b->print();
        }
    }
    void add(Base* b) override
    {
        b->setDepth((b->getDepth() + 1));
        v.push_back(b);
    }
    ~Folder()
    {
        cout << "deleted folder " << getTitle() << endl;
        for (Base* b : v)
        {
            delete b;
        }
    }
};

class File : public Base
{
private:
    int size;

public:
    File(string title, int size) : Base(title), size(size) {}

    int getSize() override
    {
        return size;
    }
    void print() override
    {
        cout << '(' + getTitle() + ',' + ' ' + to_string(getSize()) + ')' << endl;
    }

    ~File()
    {
        cout << "deleted file " << getTitle() << endl;
    }
};

int main()
{
    // 조건 1. Folder와 File의 객체를 생성할 수 있어야 합니다.
    Folder *rootFolder = new Folder("ROOT"); // 폴더는 이름만 있습니다.
    Folder *aaaaFolder = new Folder("AAAA");
    Folder *bbbbFolder = new Folder("BBBB");

    File *file1 = new File("a.txt", 10); // 파일은 이름과 크기가 있습니다.
    File *file2 = new File("b.txt", 20);
    File *file3 = new File("c.txt", 30);
    File *file4 = new File("d.txt", 40);

    // 조건 2. 폴더안에 파일 및 다른 폴더를 넣을 수 있어야 합니다.
    rootFolder->add(aaaaFolder);
    rootFolder->add(bbbbFolder);
    rootFolder->add(file1);

    aaaaFolder->add(file2);
    aaaaFolder->add(file3);

    bbbbFolder->add(file4);

    // 조건 3. 파일과 폴더 크기를 출력할 수 있어야 합니다.
    //        폴더는 자신만의 크기는 없지만 크기를 구할 수는 있습니다.
    cout << file1->getSize() << endl;
    cout << aaaaFolder->getSize() << endl;
    cout << rootFolder->getSize() << endl;

    // 조건 4. 화면 출력
    file1->print(); // 파일이므로 이름과 크기만 출력해 주세요.
                    // ex) (a.txt, 10)

    rootFolder->print(); // ROOT폴더 전체의 모양을 보기좋게 출력해 주세요
                         // [ROOT]
                         //      [AAAA]
                         //              (b.txt, 20)
                         //              (b.txt, 30)
                         //      [BBBB]
                         //              (d.txt, 40)
                         //       (a.txt, 10)

    // 조건 5. 폴더 제거시 폴더 안에 있는 모든 파일과 폴더가 제거 되게 해주세요
    delete rootFolder;

    return 0;
}