#include "stdafx.h"
#include <vector>
#include <unordered_map>
#include <string>
#include <iostream>
#include <assert.h>

// https://leetcode.com/problems/two-sum/
class Solution {

public:
  std::vector<int> twoSum(std::vector<int>& nums, int target) {
    std::unordered_map<int, int> hashmap;
    std::vector<int> result;
    size_t length = nums.size();
    for (size_t i = 0; i < length; i++) {
      hashmap[nums[i]] = i;
    }

    for (size_t i = 0; i < length; i++) {
      auto r = hashmap.find(target - nums[i]);
      if (r != hashmap.end()) {
        if (i == r->second) continue;
        result.push_back(i + 1);
        result.push_back(r->second + 1);
        return result;
      }
    }
    result.push_back(0);
    result.push_back(0);
    return result;
  }
};

int _1(int argc, _TCHAR* argv[])
{
  Solution s;

  std::vector<int> _input1 = { 3,2,4 };
  std::vector<int> _output1 = s.twoSum(_input1, 6);
  printf("%d %d\n", _output1.at(0), _output1.at(1));
  return 0;
};