#include "stdafx.h"
#include <vector>
#include <unordered_map>
#include <string>
#include <iostream>
#include <assert.h>
#include<algorithm>
using namespace std;

// https://leetcode.com/problems/two-sum/
class Solution {
public:
  void nextPermutation(vector<int>& nums) {
    if (nums.size() < 2) {
      return;
    }
    // check where desc ends
    int i;
    int N = nums.size();
    int maxNumIndex;
    int minNumIndex;
    int minSoFar = INT32_MAX;
    i = N - 2;
    for (i = N - 2; i >= 0; i--) { // find index where it is non-descending
      if (nums[i] < nums[i + 1]) break;
    }

    if(i == -1) {
      minNumIndex = N - 1;
      maxNumIndex = 0;
    }
    else {
      maxNumIndex = i; // find smallest number greater than nums[maxNumIndex]
      for(i = N - 1;i >= maxNumIndex;i--)
        if (nums[i] > nums[maxNumIndex]) {
          if (minSoFar > nums[i]) {
            minNumIndex = i;
            minSoFar = nums[i];
          }
        }
    }

    swap(nums[minNumIndex], nums[maxNumIndex]);
    sort(nums.begin() + maxNumIndex + 1, nums.end());
  }
};

int _31(int argc, _TCHAR* argv[])
{
  Solution s;
  vector<int> in = {1,2,0,0,1};
  for (int i = 0; i < 25; i++) {
    s.nextPermutation(in);
    printf("%d. ", i);
    for (int n : in) {
      printf("%d", n);
    }
    printf("\n");
  }
  return 0;
}