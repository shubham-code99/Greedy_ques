#include<iostream>
#include<vector>
using namespace std;

int change(int a, vector<int> &b)
{
    int mul;
    mul=a/10;
    a=a-(10*mul);
    for(int i=1;i<=mul;++i)
    b.push_back(10);
    mul=a/5;
    a=a-(5*mul);
    for(int i=1;i<=mul;++i)
    b.push_back(5);
    for(int i=1;i<=a;++i)
    b.push_back(1);
    return 0;
}

int main()
{
    int a;
    vector<int>b;
    cin>>a;
    change(a,b);
    cout<<b.size();
    return 0;
}