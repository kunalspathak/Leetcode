#include "stdafx.h"
#include <vector>
#include <unordered_map>
#include <string>
#include <iostream>
#include <assert.h>


// https://leetcode.com/problems/palindrome-number/
class Solution {
public:

  bool isPalindrome(int x) {
    if (x < 0) {
      return false;
    }
    int y = x;
    int noofDigits = 1;
    while ((y /= 10) != 0) noofDigits++;
    y = x;
    int d = noofDigits;
    for (int i = 0; i < noofDigits / 2, d > 1; i++) {
      int _left10 = pow(10, (d - 1));
      int left = x / _left10;
      int right = x % 10;
      if (left != right) {
        return false;
      }
      x -= (left * _left10);
      x /= 10;
      d -= 2;
    }

    return true;
  }

};


int _9(int argc, _TCHAR* argv[])
{
  Solution s;
  printf("Actual : %d\n", s.isPalindrome(-2147447412));
  return 0;
}