#include "stdafx.h"
#include <vector>
#include <unordered_map>
#include <string>
#include <iostream>
#include <assert.h>
#include <algorithm>
using namespace std;

// https://leetcode.com/problems/4sum/
class Solution {
public:
  vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> result;
    int sum = -1;
    int minSum = -1, maxSum = -1;
    int n = (int)nums.size();
    if (n < 4) {
      return result;
    }
    else if (n == 4) {
      sum = nums[0] + nums[1] + nums[2] + nums[3];
      if (sum == target) {
        result.push_back(nums);
        return result;
      }
    }
    std::sort(nums.begin(), nums.end());
    for (int i = 0; i < n - 3; i++) {
      int first = nums[i];
      // check if target is within start and end range of first
      minSum = first + nums[i + 1] + nums[i + 2] + nums[i + 3];
      maxSum = first + nums[n - 3] + nums[n - 2] + nums[n - 1];
      // no point in checking further first
      if (target < minSum) break;
      // target is greater, so worth checking with higher values of first
      if (target > maxSum) continue;

      for (int j = i + 1; j < n - 2; j++) {
        int second = nums[j];
        minSum = first + second + nums[j + 1] + nums[j + 2];
        maxSum = first + second + nums[n - 2] + nums[n - 1];
        // no point in checking further second
        if (target < minSum) break;
        // target is greater, so worth checking with higher values of second
        if (target > maxSum) continue;

        int start = j + 1;
        int end = n - 1;
        while (start < end) {
          int third = nums[start];
          int fourth = nums[end];

          sum = first + second + third + fourth;
          if (sum == target) {
            result.push_back({ first, second, third, fourth });
            while (start < end && nums[start] == third) {
              start++;
            }
            while (start < end && nums[end] == fourth) {
              end--;
            }
          }
          else if(sum < target) {
            while (start < end && nums[start] == third) {
              start++;
            }
          }
          else {
            while (start < end && nums[end] == fourth) {
              end--;
            }
          }
        }

        while (j + 1 < n - 2 && nums[j + 1] == second) {
          j++;
        }
      }

      while (i + 1 < n - 3 && nums[i + 1] == first) {
        i++;
      }
    }
    return result;
  }
};

int _tmain(int argc, _TCHAR* argv[])
{
  Solution s;
  vector<int> input = {-1, 0,0,0,0,1};

  vector<int> quad;
  vector<vector<int>> result = s.fourSum(input,0);
  for (vector<vector<int>>::iterator it = result.begin(); it != result.end(); ++it) {
    quad = (*it);
    printf("[%d, %d, %d, %d]\n", quad[0], quad[1], quad[2], quad[3]);
  }
  return 0;
}