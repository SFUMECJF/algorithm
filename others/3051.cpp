//
// Created by YMXD on 2021/3/26.
//
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int p10[] = {1, 10, 100, 1000, 10000, 100000, 1000000,10000000,
             100000000,1000000000};
int get(int n)
{
  for(int i =0; i < 10; i++)//i + 1代表是k位数
  {
    //9LL表示把9扩展到longlong的类型
    long long len = 9 *(i + 1) * p10[i];//第k位的长度9*k*10(k-1)，此处k为i+1
    if(n <= len)
    {
      int num = (n -1) / (i+1) + p10[i];//第k位数上  为什么是n-1
      int s = (n-1) %(i +1);//从左数，k位数的第几位    为什么是n-1
      return (num / p10[i - s]) % 10;
    }
    n -= len;
  }

}
int main()
{
  int t, v;
  cin >> t;
  for(int i =0; i<t;i++)//i=1;i <=t
  {
    cin >> v;
    cout << get(v)<<endl;
  }
  return 0;

}