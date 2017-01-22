#include "stdafx.h"
#include <vector>
#include <unordered_map>
#include <string>
#include <iostream>
#include <assert.h>
#include <algorithm>
using namespace std;

// https://leetcode.com/problems/two-sum/
class Solution {
public:
  int searchInsert(vector<int>& nums, int target) {
    int N = nums.size();
    int start = 0, end = N - 1, mid = 0;
    if (N == 0 || target < nums[0]) {
      return 0;
    }
    if (nums[end] < target) return N;

    while (start < end) {
      mid = (start + end) / 2;
      if (nums[mid] == target) {
        return mid;
      }
      if (target < nums[mid]) end = mid - 1;
      else start = mid + 1;
    }

    return nums[end] < target ? end + 1 : end;
  }
};

int _35(int argc, _TCHAR* argv[])
{
  vector<int> nums = {1,3,5, 5,6};
  int target = 4;
  Solution s;
  int found = -1;
  for (int i = 0; i < nums.size(); i++) {
    if(nums[i] >= target) {
      found = i;
      break;
    }
  }
  assert((found == -1 ? nums.size() : found) == s.searchInsert(nums,target));
  return 0;
}