#include <bits/stdc++.h>
using namespace std;

int binarySearch(int elements[], int key,int length)//需要排序好的数组
{
    int low = 0,high = length -1, mid = (low + high)/2;//数据储存是从0开始的。很大的数组，所以要传递数量length

    while(low <= high)//注意要有等于，否则会漏掉正好在中间的值
    {
        mid = (low + high)/2;
        if(elements[mid] < key)
            low = mid +1;
        else if(elements[mid] > key)
            high = mid -1;
        else
            return mid;

    }
    return -1;//记住没找到返回什么

}

int main()
{ 
  int n; 
  int a[100001]; 
  cin >> n; 
  for (int i = 0; i < n; ++i)
    cin >> a[i]; 
  int q, m; 
  cin >> q; 
  for (int i = 1; i <= q; ++i) 
 { 
    cin >> m; 
    //if (*lower_bound(a + 1, a + 1 + n, m) == m)
     if (binarySearch(a, m, n) != -1)
      cout << "Yes" << endl;
    else 
      cout << "No" << endl;
 } 
  return 0; 
}