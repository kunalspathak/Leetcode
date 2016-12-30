#include "stdafx.h"
#include <vector>
#include <unordered_map>
#include <string>
#include <iostream>
#include <assert.h>
using string = std::string;

// https://leetcode.com/problems/longest-substring-without-repeating-characters/
class Solution {

public:
  int lengthOfLongestSubstring(string s)
  {
    int currLength = 0;
    int maxLength = 0;
    //int substrStartingPoint = 0;
    unsigned int currStartingPoint = 0;
    std::unordered_map<char, unsigned int> lookup;
    size_t strLength = s.length();
    for (unsigned int i = 0; i < strLength; i++)
    {
      char ch = s[i];
      auto lookupResult = lookup.find(ch);

      // If 'ch' doesn't exist
      if (lookupResult == lookup.end())
      {
        lookup[ch] = i;
        currLength++;
      }
      // If 'ch' already exist
      else
      {
        // update the maxLength, if applicable
        if (maxLength < currLength)
        {
          maxLength = currLength;
        }
        // 'ch' is before startingPoint
        if (lookupResult->second < currStartingPoint)
        {
          currLength++;
        }
        else
        {
          currStartingPoint = lookupResult->second + 1;
          currLength = i - lookupResult->second;
        }
        lookupResult->second = i;
      }
    }
    /* printf("%d :", substrStartingPoint);
    for (unsigned int i = substrStartingPoint; i < (substrStartingPoint + maxLength);i++)
    {
    printf("%c", s[i]);
    }
    printf("\n");*/
    return maxLength < currLength ? currLength : maxLength;
  }
};


int _3(int argc, _TCHAR* argv[])
{
  Solution s;
  printf("length = %d\n", s.lengthOfLongestSubstring("ffgaihhhfgaihjaalkjlakshldhljhasdklhalksdhlkahsldjahuoiujkkjmasl"));
  return 0;
}