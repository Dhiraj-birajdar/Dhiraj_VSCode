#include<iostream>
using namespace std;
float add(float a,float b)
{
    return a+b;
}
float sub(float a,float b)
{
    return a-b;
}
float mul(float a,float b)
{
    return a*b;
}
float div(float a,float b)
{
    return a/b;
}
int main()
{
    int choice;
    float a,b;
    float (*fp[4])(float,float)={add,sub,mul,div};
    cout<<"Enter Two No"<<endl;
    cin>>a>>b;
    cout<<"Enter Choice\n 0.Add\n1.sub\n2.sub\n3.mul\n4.div"<<endl;
    cin>>choice;
    cout<<"The Result Is "<<fp[choice](a,b)<<endl;
    return 0;

}