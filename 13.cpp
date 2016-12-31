#include "stdafx.h"
#include <vector>
#include <unordered_map>
#include <string>
#include <iostream>
#include <assert.h>
using string = std::string;

// https://leetcode.com/problems/roman-to-integer/
class Solution {

private:

  void getValue(char ch, int * pos, int * val) {
    switch (ch) {
    case 'I':
      *pos = 0;
      *val = 1;
      break;
    case 'V':
      *pos = 1;
      *val = 5;
      break;
    case 'X':
      *pos = 2;
      *val = 10;
      break;
    case 'L':
      *pos = 3;
      *val = 50;
      break;
    case 'C':
      *pos = 4;
      *val = 100;
      break;
    case 'D':
      *pos = 5;
      *val = 500;
      break;
    case 'M':
      *pos = 6;
      *val = 1000;
      break;
    }
  }

public:
  int romanToInt(string s) {
    int prev = -1;
    int answer = 0;
    int pos = -1, value = -1;
    char ch;
    for (int i = s.length() - 1; i >= 0; i--) {
      ch = s[i];
      getValue(ch, &pos, &value);
      if (prev > pos) {
        prev = -1;
        answer -= value;
      }
      else {
        prev = pos;
        answer += value;
      }
    }
    return answer;
  }
};

int _13(int argc, _TCHAR* argv[])
{
  Solution s;
  string num("MMM");
  printf("%s : %d.\n", num.c_str(), s.romanToInt(num));
}