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
  int search(vector<int>& nums, int target) {
    int N = nums.size();
    int start = 0, end = N - 1, pivot = 0;
    bool found = false;
    while (end - start > 1) {
      pivot = (end + start) / 2;
      if (nums[pivot] > nums[pivot + 1]) {
        found = true;
        break;
      }
      if (nums[0] > nums[pivot]) {
        end = pivot;
      }
      else {
        start = pivot;
      }
    }

    if (!found) {
      pivot = nums[start] > nums[end] ? start : end;
    }

    if (nums[0] > target) {
      start = std::min(pivot + 1, N - 1);
      end = N - 1;
    }
    else {
      start = 0;
      end = pivot;
    }

    while (end - start > 1) {
      pivot = (end + start) / 2;
      if (nums[pivot] == target) { return pivot; }
      if (target > nums[pivot]) {
        start = pivot;
      }
      else {
        end = pivot;
      }
    }

    return nums[start] == target ? start : (nums[end] == target ? end : -1);
  }
};

int _33(int argc, _TCHAR* argv[])
{
  vector<int> nums = {1};
  Solution s;
  for (int i = 0; i < nums.size(); i++) {
    assert(i == s.search(nums, nums[i]));
    assert(-1 == s.search(nums, nums[i]  *2));
  }
  return 0;
}