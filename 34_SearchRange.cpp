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
  vector<int> searchRange(vector<int>& nums, int target) {
    int N = nums.size();
    int start = 0, end = N - 1, mid = 0;
    int ansStart = -1, ansEnd = -1;
    vector<int> result({-1,-1});
    if (N == 0) {
      return result;
    }
    while (start <= end) {
      mid = (start + end) / 2;
      if ((mid == 0 ||  nums[mid - 1] != target) && nums[mid] == target) {
        break;
      }
      if (nums[mid] >= target) end = mid - 1;
      else start = mid + 1;
    }

    if (nums[mid] != target) {
      return result;
    }

    ansStart = mid;
    start = mid, end = N - 1;
    while (start <= end) {
      mid = (start + end) / 2;
      if ((mid == N - 1 || nums[mid + 1] != target) && nums[mid] == target) {
        break;
      }
      if (nums[mid] <= target) start = mid + 1;
      else end = mid - 1;
    }

    ansEnd = mid;
    assert(nums[mid] == target);
    result[0] = ansStart;
    result[1] = ansEnd;
    return result;
  }
};

int _34(int argc, _TCHAR* argv[])
{
  vector<int> nums = {};
  int target = 5;
  Solution s;
  int expectedStart = -1, expectedEnd = -1;
  for (int i = 0; i < nums.size(); i++) {
    if (nums[i] == target) {
      expectedStart = i;
      break;
    }
  }
  for (int i = nums.size() - 1; i >=0 ; i--) {
    if (nums[i] == target) {
      expectedEnd = i;
      break;
    }
  }
  vector<int> r = s.searchRange(nums, target);
  assert(r[0] == expectedStart && r[1] == expectedEnd);
  return 0;
}