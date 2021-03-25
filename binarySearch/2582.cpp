////
//// Created by sf on 2021/3/25.
////
////#include <bits/stdc++.h>
//#include <iostream>
// using namespace std;
//这里的long long int *elements需要和调用时候的数组类型相同。
 int binary_search(long long int *elements, int key, int low = 0, int high = 0)
 //需要排序好的数组
{
  int mid; //数据储存不一定是从0开始的。很大的数组，所以要传递数量low,high

  while (low <= high) //注意要有等于，否则会漏掉正好在中间的值
  {
    mid = (low + high) / 2;
    if (elements[mid] < key)
      low = mid + 1;
    else if (elements[mid] > key)
      high = mid - 1;
    else
      return mid;
  }
  //从小到大递增的数组，找一个小于等于的前缀和，不能大于
  //此时low > high
  return high; //记住没找到返回什么
}
//
// int main() {
//  long long s;
//  int n;
//  cin >> s >> n;
//  int item[n], min_length = n + 1;
//  long long prefix_sum[n + 1];
//  prefix_sum[0] = 0;
//
//  for (int i = 0; i < n; i++) {
//    cin >> item[i];
//    prefix_sum[i + 1] = prefix_sum[i] + item[i];
//  }
//
//  for (int i = 1; i <= n; i++) {
//    if (prefix_sum[i] < s)
//      continue;
//    else {
//      // int j = upper_bound(prefix_sum, prefix_sum + i, prefix_sum[i] - s) -
//      prefix_sum;
//      int j = binarySearch(prefix_sum, prefix_sum[i] - s, 1, i);
//      min_length = min(min_length, i - j - 1);
//    }
//  }
//  if (min_length == n + 1)
//    cout << 0 << endl;
//  else
//    cout << min_length;
//
//  return 0;
//}
/*
 *
50 20
10 8 9 3 11 8 5 1 1 1 1 20 8 9 11 4 13 22 9 6

 output 4

 */
#include <bits/stdc++.h>
using namespace std;
#define MIN(a, b) a < b ? a : b
int main() {
  long long s;
  int n;
  cin >> s >> n;
  int a[n], res = n + 1;
  long long sum[n + 1];
  sum[0] = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum[i + 1] = sum[i] + a[i];
  }
  for (int i = 1; i <= n; i++) {
    if (sum[i] < s)
      continue;
    else {
      //int j = upper_bound(sum, sum + i, sum[i] - s) - sum;
      int j = binary_search(sum, sum[i] - s, 1, i);
      res = MIN(res, i - j);
    }
  }
  res = res == n + 1 ? 0 : res;
  cout << res << endl;
  return 0;
}
