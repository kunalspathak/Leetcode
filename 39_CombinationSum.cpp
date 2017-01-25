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
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    std::sort(candidates.begin(), candidates.end());
    vector<vector<int>> accum;
    vector<int> result;
    combinationUtil(candidates, target, result, accum, 0);
    return accum;
  }

  void combinationUtil(vector<int> &input, int target, vector<int> &result, vector<vector<int>> &accum, int startI) {
    for (int i = startI; i < input.size() && input[i] <= target; i++) {
      int curr = input[i];
      if (curr == target) {
        result.push_back(curr);
        accum.push_back(result);
        result.pop_back();
        return;
      }

      result.push_back(curr);
      combinationUtil(input, target - curr, result, accum, i);
      result.pop_back();
    }
  }
};

int _39(int argc, _TCHAR* argv[])
{
  vector<int> input = {2};
  int target = 2;
  Solution s;
  vector<vector<int>> answer = s.combinationSum(input, target);
  for (int i = 0; i < answer.size(); i++) {
    vector<int> comb = answer[i];
    for (int j = 0; j < comb.size(); j++) {
      printf("%d, ", comb[j]);
    }
    printf("\n");
  }
  return 0;
}