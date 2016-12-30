#include "stdafx.h"
#include <vector>
#include <unordered_map>
#include <string>
#include <iostream>
#include <assert.h>
using string = std::string;

// https://leetcode.com/problems/string-to-integer-atoi/
class Solution {
public:

  int myAtoi(string str) {
    /*printf("Input : %s\n", str.c_str());
    printf("Expected : %d\n", atoi(str.c_str()));*/
    int result = 0;
    size_t startIndex = 0;
    char ch;
    int sign = 1;
    int factor = 1;
    bool isOverflow = false;
    while ((ch = str[startIndex]) == ' ') startIndex++;
    ch = str[startIndex];
    if (ch == '-') {
      sign = -1;
      startIndex++;
    }
    else if (ch == '+') {
      sign = 1;
      startIndex++;
    }
    else if (ch < '0' || ch > '9') {
      return 0; // invalid input after optional sign
    }
    for (; startIndex < str.length(); startIndex++) {
      ch = str[startIndex];
      if (ch < '0' || ch > '9') break;

      if (INT32_MAX / 10 < result) {
        result = INT32_MAX;
        isOverflow = true;
        break;
      }
      result = (result * 10);

      int adder = (ch - '0');
      if (INT32_MAX - adder < result) {
        result = INT32_MAX;
        isOverflow = true;
        break;
      }
      result += adder;
    }

    if (sign == -1) {
      // check if this is overflow
      if (isOverflow) {
        result = INT32_MIN;
      }
      else {
        result = sign * result;
      }
    }
    return result;
  }
};

int _8(int argc, _TCHAR* argv[])
{
  Solution s;

  printf("Actual : %d\n", s.myAtoi("2147483650"));
  return 0;
}
