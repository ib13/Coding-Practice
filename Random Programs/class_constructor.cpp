#include<iostream>
using namespace std;

class student{
private:
    string name;
    int age;
    int standard;
public:
    student()
    {
        this->name="NULL";
        this->age=0;
        this->standard=1;
    }
    student(string name,int age,int standard)
    {
        this->name=name;
        this->age=age;
        this->standard=standard;
    }
    student(student &s)
    {
        this->name=s.name;
        this->age=s.age;
        this->standard=s.standard;
    }
    void printstudent()
    {
        cout<<name<<" "<<age<<" "<<standard;
    }
    void setage(int age)
    {
        this->age=age;
    }
};

int main()
{
    student student1;
    student1.printstudent();
    cout<<"\n";
    student student2("Ishan",20,15);
    student2.printstudent();
    cout<<"\n";
    student student3(student2);
    student3.printstudent();
    cout<<"\n";
    student3.setage(21);
    student3.printstudent();
    cout<<"\n";
    student2.printstudent();
}