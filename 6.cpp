#include "stdafx.h"
#include <vector>
#include <unordered_map>
#include <string>
#include <iostream>
#include <assert.h>
using string = std::string;


// https://leetcode.com/problems/zigzag-conversion/
class Solution {
public:

  // https://leetcode.com/problems/zigzag-conversion/
  string convert(string s, int numRows)
  {
    if (numRows == 1)
    {
      return s;
    }
    int length = s.length();
    bool flipFlop = true;
    auto fn = [&](int currentLine)
    {
      int nextIndex = -1;
      if (currentLine == 0 || currentLine == (numRows - 1))
      {
        nextIndex = 2 * (numRows - 1);
      }
      else
      {
        nextIndex = flipFlop ? 2 * (numRows - (currentLine + 1)) : (2 * currentLine);
        flipFlop = !flipFlop;
      }
      return nextIndex;
    };
    string answer(length, '_');
    int answerIndex = 0;
    for (int currentRow = 0; currentRow < numRows; currentRow++)
    {
      flipFlop = true;
      int currentIndex = currentRow;
      while (currentIndex < length)
      {
        answer[answerIndex++] = s[currentIndex];
        currentIndex += fn(currentRow);
      }
    }
    return answer;
  }

};

int _6(int argc, _TCHAR* argv[])
{
  Solution s;

  std::cout << s.convert("THE", 3) << "\n";

  return 0;
}