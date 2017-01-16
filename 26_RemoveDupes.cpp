#include "stdafx.h"
#include <vector>
#include <unordered_map>
#include <string>
#include <iostream>
#include <assert.h>
using namespace std;

// https://leetcode.com/problems/two-sum/
class Solution {
public:
  int removeDuplicates(vector<int>& nums) {
    int curr = 0;
    int i = 0, N = nums.size();
    if (N == 0 || N == 1) {
      return N;
    }
    for (int i = 0; i < N; i++) {
      if (nums[curr] == nums[i])
        continue;
      nums[++curr] = nums[i];
    }
    return curr + 1;
  }
};

int _26(int argc, _TCHAR* argv[])
{
  Solution s;
  std::vector<int> input = {};
  int size =  s.removeDuplicates(input);
  for (int i = 0; i < size; i++) {
    printf("%d, ", input[i]);
  }
  return 0;
}