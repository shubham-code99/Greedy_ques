#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    long int n;
    cin>>n;
    if(n==0)
    {
        cout<<"0";
        return 0;
    }
    vector<long long int> a(n);
    vector<long int> b(n);
    for(int i=0;i<n;++i)
    cin>>a[i];
    for(int i=0;i<n;++i)
    cin>>b[i];
    sort(a.begin(),a.end(),greater<long int>());
    sort(b.begin(),b.end(),greater<long int>());
    long long int sum=0;
    for(int i=0;i<n;++i)
    {
        sum+=a[i]*b[i];
    }
    cout<<sum;
    return 0;
}