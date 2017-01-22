#include "stdafx.h"
#include <vector>
#include <unordered_map>
#include <string>
#include <iostream>
#include <assert.h>
#include <stack>
#include <algorithm>
using namespace std;

// https://leetcode.com/problems/two-sum/
class Solution {
public:

  int longestValidParentheses(string s) {
    stack<int> st;
    vector<pair<int, int>> intermediate;
    for (int i = 0; i < s.length(); i++) {
      char ch = s[i];
      if (ch == '(') { st.push(i); continue; }
      if (!st.empty()) {
        intermediate.push_back(std::make_pair(st.top(), i));
        st.pop();
      }
    }
    if (intermediate.size() == 0) {
      return 0;
    }
    std::sort(intermediate.begin(), intermediate.end(), [](pair<int,int> &left, pair<int, int> &right) {
      return left.first < right.first;
    });
    pair<int, int> curr;
    int first = intermediate[0].first, second = intermediate[0].second;
    int maxLength = (second - first) + 1;
    int startOfLongest = first;

    for (int i = 1; i < intermediate.size(); i++) {
      curr = intermediate[i];
      if (second + 1 == curr.first) {
        second = curr.second;
      }
      else if (second < curr.first) {
        first = curr.first;
        second = curr.second;
      }
      int diff = (second - first) + 1;
      if (maxLength < diff) {
        maxLength = diff;
        startOfLongest = first;
      }
    }
    printf("Input: %s\n", s.c_str());
    printf("Output: %d, %s\n", maxLength, s.substr(startOfLongest, maxLength).c_str());
    return maxLength;
  }
};

int _32(int argc, _TCHAR* argv[])
{
  Solution s;
  int len = s.longestValidParentheses("))()");
  return 0;
}