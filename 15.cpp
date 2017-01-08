#include "stdafx.h"
#include <vector>
#include <map>
#include <unordered_set>
#include <string>
#include <iostream>
#include <assert.h>
#include <algorithm>
using namespace std;


// https://leetcode.com/problems/3sum/
class Solution {
public:

  vector<vector<int>> threeSum(vector<int>& nums) {
    unordered_set<string> indices;
    vector<int> triplet;
    vector<vector<int>> result;

    if (nums.size() < 3) {
      return result;
    }
    else if (nums.size() == 3) {
      if (nums[0] + nums[1] + nums[2] == 0) {
        triplet = { nums[0],nums[1],nums[2] };
        result.push_back(triplet);
        return result;
      }
    }

    std::sort(nums.begin(), nums.end());

    int n = nums.size();
    for (int i = 0; i < n - 3; i++) {
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
        if (sum == 0) {
          triplet = { a,b,c };
          end--;

          string s1, s2, s3;
          if (a < 0) {
            s1 = "-";
          }
          s1 += ('0' + abs(a));
          if (b < 0) {
            s2 = '-';
          }
          s2 += ('0' + abs(b));

          if (c < 0) {
            s3 = '-';
          }
          s3 += ('0' + abs(c));
          string s = s1 + s2 + s3;
          if (indices.find(s) == indices.end()) {
            indices.insert(s);
            result.push_back(triplet);
          }
        }
        else if (sum > 0) {
          end--;
        }
        else {
          start++;
        }
      }
    }
    return result;
  }
};

int _tmain(int argc, _TCHAR* argv[])
{
  Solution s;
  vector<int> input = { 0,0,0};

  vector<int> triplet;
  vector<vector<int>> result = s.threeSum(input);
  for (vector<vector<int>>::iterator it = result.begin(); it != result.end(); ++it) {
    triplet = (*it);
    printf("[%d, %d, %d]\n", triplet[0], triplet[1], triplet[2]);
  }
}