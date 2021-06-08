#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int n,count=0;
    cin>>n;
    vector<vector<long long int>> ab;
    for(int i=0;i<n;++i )
    {
        vector<long long int> v(2);
        for(int j=0;j<2;++j)
        {
            cin>>v[j];            
        }
        ab.push_back(v);
    }
    vector<long long int> a(2);
    a.push_back(2);
    a.push_back(2);
    ab.push_back(a);
    vector<long long int> y;   
    vector<long long int> x;    
    vector<int> index;
    index.push_back(0);
    while(ab.size()>1)
    {
        long long int temp2=ab[0][1];
        long long int temp1=ab[0][0];
        for(int j=1;j<ab.size()-1;++j)
        {
            if(((ab[j][0]<=temp2)&&(ab[j][1]>=temp2))||((ab[j][0]<=temp1)&&(ab[j][1]>=temp1))||((temp1<ab[j][0])&&(temp2>ab[j][1])))
            {
                index.push_back(j);
            }
        }
        if(index.size()==1)
        {
            x.push_back(temp2);
            count+=1;
            ab.erase(ab.begin());
            break;
        }
        int times=index.size()-1;
        while(times>0)
        {
            bool flag=false;
            while(temp2>=temp1)
            {
                int in=1,count2=0;
                for(int k=index[in];in<index.size();++in)
                {
                    if((temp2>=ab[k][0])&&(temp2<=ab[k][1]))
                    {
                        count2+=1;
                        if(count2==index.size()-1)
                        {
                            x.push_back(temp2);
                            count+=1;
                            flag=true;
                            break;
                        }
                    }   
                    else
                        count2-=1; 

                }
                if(flag==true)
                    break;
                temp2-=1;
            }
            int time=index.size()-1;
            while(time>=0)
            {
                ab.erase(ab.begin()+index[time]);
                time-=1;
            }
            index.erase(index.begin()+1,index.end());
            break;
        }

        
    }   
    cout<<count<<endl;
    //cout<<ab.size();
    for(int i=0;i<x.size();++i)
    cout<<x[i]<<" "; 
    return 0;
}