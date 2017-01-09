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
    int diff = -1;
    int sum = 0;

    if (nums.size() < 3) {
      return result;
    }
    else if (nums.size() == 3) {
      return (nums[0] + nums[1] + nums[2]);
    }

    std::sort(nums.begin(), nums.end());

    int n = nums.size();
    for (int i = 0; i < (n - 2); i++) {
      for (int j = (i + 1); j <= (n - 1); j++) {
        for (int k = (j + 1); k < n; k++) {
          sum = nums[i] + nums[j] + nums[k];
          int diff = sum - target;
          if (diff == 0) {
            return target;
          }
          if (minDiffSoFar > abs(diff)) {
            minDiffSoFar = abs(diff);
            result = sum;
          }
        }
      }
    }
    return result;
  }
};

int _tmain(int argc, _TCHAR* argv[])
{
  Solution s;
  vector<int> input = { 1,1,1,0 };

  printf("%d\n", s.threeSumClosest(input, 100));
}