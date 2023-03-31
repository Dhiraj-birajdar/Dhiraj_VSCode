#include<iostream>
#include<string>

using namespace std;


class Student{
    public:
        string name;
        int rno;
        float percentage;

        void change_name(string n){
            name = n;
        }

        Student(string nm, int r, float p){
            name = nm;
            rno = r;
            percentage = p;
        }

        void show(){
            cout<<"\nName: "<<name;
            cout<<"\nRoll no: "<<rno;
            cout<<"\nPercentage: "<<percentage;
        }
};

int main()
{
    Student s1("sam hose", 102, 88.40);
    // s1.name = "Dhiraj Birajdar";
    s1.show();
    // char str[30];
    // string s;
    // cout<<"enter name : ";
    // cin.getline(str, 30);
    // cin.ignore();
    // cout<<str;
    // getline(cin, s);
    // cout<<s;
}