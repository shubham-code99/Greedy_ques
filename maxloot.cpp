#include<iostream>
#include<vector>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    long W;
    cin>>n>>W;
    vector<long> v(n);
    vector<long> w(n);
    for(int i=0;i<n;++i)
    {
        cin>>v[i]>>w[i];
    }
    vector<double> per_unit(n);
    double f;
    for(int i=0;i<n;++i)
    {
        f=double(v[i])/w[i];
        per_unit.push_back(f);
    }
    sort(per_unit.begin(), per_unit.end(), greater<double>());
    for(int i=0;i<=per_unit.size()/2;++i)
    per_unit.pop_back();
    int i=0;
    double value=0.0,sum=0;
    for(int k=0;k<w.size();++k)
    sum+=w[k];
    if(sum<=W)
    {
        for(int k=0;k<v.size();++k)
        {
            value+=v[k];            
        }
        std::cout.precision(10);
        cout<<value;
        return 0;
    }
    while(W!=0)
    {
        for(int j=0;j<v.size();++j)
        {
            if(per_unit[i]==double(v[j])/w[j])
            {
                if(w[j]<=W)
                {
                    value+=v[j];
                    W-=w[j];
                    v.erase(v.begin()+j);
                    w.erase(w.begin()+j);
                }
                else
                {
                    double frac=double(w[j])/W;
                    value+=double(v[j])/frac;
                    std::cout.precision(10);
                    cout<<value;
                    return 0;
                }
            }
        }
        ++i;

    }
    std::cout.precision(10);
    cout<<value;
    return 0;
}