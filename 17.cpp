#include "stdafx.h"
#include <vector>
#include <unordered_map>
#include <string>
#include <iostream>
#include <assert.h>
#include <map>
using namespace std;


// https://leetcode.com/problems/letter-combinations-of-a-phone-number/
class Solution {
public:
  vector<string>  letterCombinations(string digits) {
    vector<string> resultVector;
    if (digits.length() == 0) {
      return resultVector;
    }
    char * result = (char *)malloc(digits.size() + 1);
    combinationUtil(digits, result, 0, 0, resultVector);
    return resultVector;
  }

  string getStringForDigit(char c) {
    switch (c) {
    case '2':
      return "abc";
    case '3':
      return "def";
    case '4':
      return "ghi";
    case '5':
      return "jkl";
    case '6':
      return "mno";
    case '7':
      return "pqrs";
    case '8':
      return "tuv";
    case '9':
      return "wxyz";
    default:
      assert(false);
      return nullptr;
    }
  }

 void combinationUtil(string digits, char * result, int index, int resultIndex, vector<string> &resultVector) {
    string choices = getStringForDigit(digits[index]);
    for (int charForDigit = 0; charForDigit < choices.size(); charForDigit++) {
      result[resultIndex++] = choices[charForDigit];
      if (index == digits.length() - 1) {
        // last one, print it
        result[resultIndex] = '\0';
        //printf("%s, ", result);
        string answer(result);

        resultVector.push_back(answer);
      }
      else {
        combinationUtil(digits, result, index + 1, resultIndex, resultVector);
      }
      resultIndex--;
    }
  }
};

int _17(int argc, _TCHAR* argv[])
{
  Solution s;
  vector<string> answer = s.letterCombinations("2345");
  for (auto it = answer.begin(); it != answer.end(); it++)
  {
    printf("%s, ", (*it).c_str());
  }
  return 0;
}