#include<iostream>
#include<vector>
using namespace std;

int main()
{
    long int d,m;
    cin>>d;
    cin>>m;
    int n;
    cin>>n;
    if((n==0)&&(d!=m))
    {
        cout<<"-1";
        return 0;
    }
    vector<long> stop(n);
    for(int i=0;i<n;++i)
    cin>>stop[i];
    stop.push_back(d);
    int mark=0, prev=0,count=0,index=-1;
    while(mark<=n)
    {
        if((stop[mark]-prev>m)&&(mark!=index+1))
        {
            count+=1;
            prev=stop[mark-1];
            index=mark-1;
            mark-=1;
        }
        else if((stop[mark]-prev>m)&&(mark==index+1))
        {
            cout<<"-1";
            return 0;
        }
        
        mark+=1;
    }
    cout<<count;
    return 0;
}