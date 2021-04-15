

##  模板与解释
```c++
int binary_search (long long *prefix_sum, int low, int high, long long value){
  while (low <= high){//注意要有等于，否则会漏掉正好在中间的值
    int mid = (low + high) >> 1;
    //加快速度，不使用/,使用>>
    if (prefix_sum[mid] > value)
      high = mid - 1;
    else if (prefix_sum[mid] < value)
      low = mid + 1;
    else
      return mid;

  }
  //return -1  视情况return
  return high;//如果没找到，返回小的那个。不用判断为负的情况？最多为0，是不是？然后为0，相减说明i-j也是一个可行的区间。
}
```
