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
  int removeElement(vector<int>& nums, int val) {
    int N = nums.size();
    int curr = 0;

    for (int i = 0; i < N; i++) {
      if (val != nums[i]) nums[curr++] = nums[i];
    }
    return curr;
  }
};

int _27(int argc, _TCHAR* argv[])
{
  Solution s;
  std::vector<int> input = {1};
  int size =  s.removeElement(input, 1);
  for (int i = 0; i < size; i++) {
    printf("%d, ", input[i]);
  }
  return 0;
}