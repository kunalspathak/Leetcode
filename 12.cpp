#include "stdafx.h"
#include <vector>
#include <unordered_map>
#include <string>
#include <iostream>
#include <assert.h>
#include <stack>
using std::vector;

using string = std::string;

// https://leetcode.com/problems/integer-to-roman/
class Solution {

public:

#define PROCESS(A) currDigit[currDCount++] = getChar((A))

  string intToRoman(int num) {
    int D = num % 10, F = 1, N = num, temp = -1, currDCount = -1;
    vector<char> output;
    char currDigit[5];
    string sAccum;
    std::stack<string> answer;

    while (N != 0) {
      currDCount = 0;
      switch (D) {
      case 4:
      case 9:
        PROCESS(F);
        PROCESS((D + 1) * F);
        break;
      case 5:
        PROCESS(D * F);
        break;
      case 6:
      case 7:
      case 8:
        D = D - 5;
        PROCESS(5 * F);
      case 1:
      case 2:
      case 3:
        temp = D;
        while (temp != 0) {
          PROCESS(F);
          temp--;
        }
        break;
      }
      // push currDigit's roman equivalent
      currDigit[currDCount] = '\0';

      sAccum = currDigit;
      answer.push(sAccum);

      N = N / 10;
      F *= 10;
      D = N % 10;
    }

    sAccum.clear();
    while (!answer.empty()) {
      sAccum.append(answer.top());
      answer.pop();
    }
    return sAccum;
  }

private:
  char getChar(int num) {
    switch (num) {
    case 0:
      return '-';
    case 1:
      return 'I';
    case 5:
      return 'V';
    case 10:
      return 'X';
    case 50:
      return 'L';
    case 100:
      return 'C';
    case 500:
      return 'D';
    case 1000:
      return 'M';
    default:
      assert("Bug found!");
      return 'O';
    }
  }
};

int _tmain(int argc, _TCHAR* argv[])
{
  Solution s;
  int num = 70;
  
  printf("%d = %s\n",num, s.intToRoman(num).c_str());

  return 0;
}