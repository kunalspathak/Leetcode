#include "stdafx.h"
#include <vector>
#include <unordered_map>
#include <string>
#include <iostream>
#include <assert.h>
using string = std::string;

// https://leetcode.com/problems/longest-palindromic-substring/
class Solution {

public:
  string longestPalindrome(string s)
  {
    if (s.length() == 0 || s.length() == 1)
      return s;

    int tempStartPos = 0;
    int startPos = 0;
    unsigned longestLength = 0;
    unsigned int strLength = s.length();
    for (unsigned int i = 0; i < strLength; i++)
    {
      unsigned int currLength = getLengthOfPalindromeAt(s, i, tempStartPos);
      if (longestLength < currLength)
      {
        longestLength = currLength;
        startPos = tempStartPos;
      }
    }
    return s.substr(startPos, longestLength);
  }

private:
  // In string 'str', checks if there exist a sub-string which is an even 
  // palindrome (at 'i') or a odd palindrome (at 'i-1' / 'i+1'). If so, return
  // the length of longest palindrome, else returns zero.
  unsigned int getLengthOfPalindromeAt(string str, unsigned int i, int &startPos)
  {
    unsigned int evenLenth = 0;
    unsigned int oddLength = 0;
    int strLength = str.length();
    int left = i - 1;
    int evenRight = i; // marker to track even palindrome
    int oddRight = i + 1; // marker to track odd palindrome
    bool isEvenPalin = true, isOddPalin = true;
    while (left >= 0)
    {
      // if even's marker within limits
      if (evenRight < strLength)
      {
        if (isEvenPalin)
        {
          if (str[left] == str[evenRight])
          {
            evenLenth += 2;
            evenRight++;
            startPos = left;
          }
          else
          {
            isEvenPalin = false;
          }
        }

      }
      // if odd's marker within limits
      if (oddRight < strLength)
      {
        if (isOddPalin)
        {
          if (str[left] == str[oddRight])
          {
            oddLength += 2;
            oddRight++;
            startPos = left;
          }
          else
          {
            isOddPalin = false;
          }
        }
      }
      // If neither even nor odd, then break the loop
      if (!isEvenPalin && !isOddPalin)
        break;

      // update the markers
      left--;
    }
    // If we found odd palindrome, then its actual length is length+1 (considering the center character)
    if (oddLength > 0) oddLength++;
    return evenLenth > oddLength ? evenLenth : oddLength;
  }

};

int _5(int argc, _TCHAR* argv[])
{
  Solution s;
  std::cout << s.longestPalindrome(nullptr) << "\n";
  return 0;
}