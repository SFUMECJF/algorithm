#include<iostream>
using namespace std;
//数据储存不一定是从0开始的。很大的数组，所以要传递数量low,high
int binary_search (long long *prefix_sum, int low, int high, long long value){
  while (low <= high){//注意要有等于，否则会漏掉正好在中间的值
    int mid = (low + high) / 2;
    if (prefix_sum[mid] > value)
      high = mid - 1;
    else if (prefix_sum[mid] < value)
      low = mid + 1;
    else
      return mid;

  }
  return high;//如果没找到，返回小的那个。不用判断为负的情况？最多为0，是不是？然后为0，相减说明i-j也是一个可行的区间。
}

//long long prefix_sum[500005];//从1开始，到n储存a[0]到a[n - 1]

int main(){

  int  s, n, a[500005];
  cin >> s >> n;
  int result = n + 1;//要最小结果，所以给大值
  long long prefix_sum[n + 1];//从1开始，到n储存a[0]到a[n - 1]
  //这里必须采用利用输入的n+1来定义long long的大小，一开始直接定义long long prefix_sum[500005]
  //或者采用将long long prefix_sum[500005]的定义 放到主函数外围，则不会炸内存
  prefix_sum[0] = 0;
  for(int i = 0; i < n; i++){
    cin >> a[i];
    prefix_sum[i + 1] = prefix_sum[i] + a[i];//
  }

  for(int i = 1; i <= n; i++){//i <= n 不是i < n
    if(prefix_sum[i] >= s){
      int j = binary_search(prefix_sum, 1, i, prefix_sum[i] - s);//返回坐标，坐标值应该是 <= prefix_sum[i] - s的，
                                               // 如此才满足prefix_sum[i] -prefix_sum[j] >= s
      result = min(result, i - j);
    }
  }
  if(result == n + 1)
    cout << 0;
  else
    cout << result;
  return 0;
}