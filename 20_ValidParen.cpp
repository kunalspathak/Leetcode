#include "stdafx.h"
#include <vector>
#include <unordered_map>
#include <string>
#include <iostream>
#include <assert.h>
#include <stack>
using namespace std;

// https://leetcode.com/problems/two-sum/
class Solution {
public:
  bool isValid(string s) {
    stack<char> st;
    char cOnStack;
    for (int i = 0; i < s.length(); i++) {
      char c = s[i];
      switch (c) {
      case '(':
      case '{':
      case '[': st.push(c); break;
      case ']': if (st.empty() || st.top() != '[') { return false; } else { st.pop(); } break;
      case '}': if (st.empty() || st.top() != '{') { return false; } else { st.pop(); } break;
      case ')': if (st.empty() || st.top() != '(') { return false; } else { st.pop(); } break;
      }
    }
    return st.empty();
  }
};

int _20(int argc, _TCHAR* argv[])
{
  Solution s;
  printf("%d,\n", s.isValid("()[]{}"));
  return 0;
}