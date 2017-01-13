#include "stdafx.h"
#include <vector>
#include <string>
#include <iostream>
#include <assert.h>
#include <unordered_set>
#include <algorithm>
#include <iterator>
using namespace std;

// https://leetcode.com/problems/two-sum/
class Solution {
private:

public:
  vector<string> generateParenthesis(int n) {

    unordered_set<string> result;
    if (n == 0) {
      vector<string> answer;
      return answer;
    }
    result.insert("()");
    unordered_set<string> accum;

    for (int i = 1; i < n; i++) {
      accum.clear();
      for (auto it = result.begin(); it != result.end();it++) {
        string temp = *it;
        int index = 0;

        while (1) {
          index = temp.find('(', index);
          if (index == -1) {
            break;
          }

          if (index == 0) {
            accum.insert("()" + temp.substr(0));
            accum.insert("(()" + temp.substr(1));
          }
          else if (index == 1) {
            accum.insert("(()" + temp.substr(1));
            accum.insert(temp.substr(0, 2) + "()" + temp.substr(2));
          }
          else {
            accum.insert(temp.substr(0, index) + "()" + temp.substr(index));
            accum.insert(temp.substr(0, index + 1) + "()" + temp.substr(index + 1));
          }

          index++;
        }
      }
      result = accum;
    }
    vector<string> answer(result.begin(), result.end());
    return answer;
  }
};

int _tmain(int argc, _TCHAR* argv[])
{
  Solution s;
  vector<string> result = s.generateParenthesis(3);
  for (auto r = result.begin(); r != result.end(); r++) {
    printf("%s.\n", (*r).c_str());
  }
  return 0;
}

/*

()

()()
(())

()()()
(())()
()(())
(()())
((()))


*/