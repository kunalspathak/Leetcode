#include "stdafx.h"
#include <vector>
#include <unordered_map>
#include <string>
#include <iostream>
#include <assert.h>
using string = std::string;


// https://leetcode.com/problems/reverse-integer/
class Solution {

public:

  int reverse(int x)
  {
    int answer = 0;
    int i = 0;
    int num = abs(x);
    answer = num % 10;
    num /= 10;
    int oldAnswer = answer;
    const int MAX_DIV = INT32_MAX / 10;
    while (num != 0)
    {
      // division overflow?
      if (MAX_DIV < answer)
      {
        return 0;
      }
      answer = (answer * 10);

      // addition overflow?
      if (INT32_MAX - (num % 10) < answer)
      {
        return 0;
      }
      answer += (num % 10);
      if (answer < oldAnswer)
        return 0;
      num /= 10;
      oldAnswer = answer;
    }
    if (x < 0)
      answer *= -1;
    //printf("%d : %d\n", x, answer);
    return answer;
  }
};

int _7(int argc, _TCHAR* argv[])
{
  Solution s;

  s.reverse(100);
  s.reverse(1534236469);
  return 0;
}
