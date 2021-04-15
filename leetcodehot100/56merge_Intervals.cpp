//
// Created by YMXD on 2021/4/15.
//
class Solution {
 public:
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<vector<int>> result;
    // if(intervals.empty()) return result;//leetcode的惯例，会出现空输入。则空输出。

    sort(intervals.begin(),intervals.end());//对于二元的vector，按照左端点作为键排序
    int left = intervals[0][0], right = intervals[0][1];//每次可能的端点做一个维护
    for (int i = 0; i < intervals.size(); i++) {//intervals.size()用来求长度，不是.length
      if (intervals[i][0] <= right) right = max(intervals[i][1], right);//not right = intervals[i][1];
      else {
        result.push_back({left, right});//{}里放两个元素表示什么类型？是list类型。
        left = intervals[i][0],right = intervals[i][1];//这种放一行的写法，简单。
      }
    }
    result.push_back({left, right});//
    return result;
  }
};