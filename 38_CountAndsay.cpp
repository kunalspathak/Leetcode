#include "stdafx.h"
#include <vector>
#include <unordered_map>
#include <string>
#include <iostream>
#include <assert.h>
#include <algorithm>
using namespace std;

// https://leetcode.com/problems/count-and-say/
class Solution {
public:
  string countAndSay(int n) {
    if (n == 0) {
      return "";
    }
    string result = "1", temp = "1";

    if (n == 0) {
      return result;
    }

    //printf("1. 1\n");
    for (int seq = 2; seq <= n; seq++) {
      result.clear();
      int N = temp.length();
      for (int i = 0; i < N; i++) {
        int j = i + 1, count = 0;
        char ch = temp[i];
        while (j < N && temp[j] == ch) {
          count++; j++;
        }
        result.push_back((count + 1) + '0');
        result.push_back(ch);
        i += count;
      }
      //printf("%d. %s \n", seq, result.c_str());
      temp = result;
    }
    return result;
  }
};

int _38(int argc, _TCHAR* argv[])
{
  Solution s;
  s.countAndSay(15);
  return 0;
}