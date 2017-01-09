#include "stdafx.h"
#include <vector>
#include <map>
#include <unordered_set>
#include <string>
#include <iostream>
#include <assert.h>
#include <algorithm>
using namespace std;


// https://leetcode.com/problems/3sum-closest/
class Solution {
public:

  int threeSumClosest(vector<int>& nums, int target) {
    int result = -1;
    int minDiffSoFar = INT32_MAX;

    if (nums.size() < 3) {
      return result;
    }
    else if (nums.size() == 3) {
      return (nums[0] + nums[1] + nums[2]);
    }

    std::sort(nums.begin(), nums.end());

    int n = nums.size();
    for (int i = 0; i < n - 2; i++) {
      int a = nums[i];
      int start = i + 1;
      int end = n - 1;
      while (start < end) {
        assert(i != start);
        assert(i != end);
        assert(start != end);
        int b = nums[start];
        int c = nums[end];
        int sum = a + b + c;
        int diff = sum - target;
        int absDiff = abs(diff);
        if (absDiff < minDiffSoFar) {
          minDiffSoFar = absDiff;
          result = sum;
        }

        if (diff > 0) {
          end--;
        }
        else if(diff < 0) {
          start++;
        }

        if (diff == 0) {
          return target;
        }
      }
    }
    return result;
  }
};

int _16(int argc, _TCHAR* argv[])
{
  Solution s;
  vector<int> input = { 1,1,1,1 };

  printf("%d\n", s.threeSumClosest(input, 0));
  return 0;
}