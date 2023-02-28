#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int i;
    vector <int> a {1,3,4};
    auto it =a.begin()+1;
    cout<<"Before : ";
    for ( i = 0; i < a.size(); i++)
    {
        cout<<a[i]<<" ";
    }
    auto itr=a.insert(it,2);
    cout<<"\nAfter : ";
    for ( i = 0; i < a.size(); i++)
    {
        cout<<a[i]<<" ";
    }
    // cout<<a.size();
    cin>>i;
}