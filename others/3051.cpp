#include<bits/stdc++.h>
using namespace std;
int p10[]={1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
int get(int n)
{
    for(int i=0;i<10;i++)
    {
        long long len=9LL*(i+1)*p10[i];
        if(n<=len)
        {
            int num=(n-1)/(i+1)+p10[i];
            int s=(n-1)%(i+1);
              return (num/p10[i-s])%10;
        }
        n-=len;
    }
}
int main(){
    int t,v;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cin>>v;
        cout<<get(v)<<endl;
    }
    return 0;
}