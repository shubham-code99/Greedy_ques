#include<iostream>
#include<vector>
using namespace std;

int main()
{
    long long int n,i=1,sum=0;
    cin>>n;
    vector<long long int> prize;
    bool flag=false;
    //long long int sum=0;
    if((n==1)||(n==2))
    {
        cout<<"1"<<endl<<n;
        return 0;
    }
    while(flag==false)
    {
        prize.push_back(i);
        sum+=i;
        if((n-sum)<=prize[prize.size()-1])
        {
            prize.pop_back();
            prize.push_back(n-(sum-i));
            flag=true;
        }
        i+=1;

    }
    cout<<prize.size()<<endl;
    for(long long int j=0;j<prize.size();++j)
    cout<<prize[j]<<" ";
    return 0;
}