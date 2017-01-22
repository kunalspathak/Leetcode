#include "stdafx.h"
#include <vector>
#include <unordered_map>
#include <string>
#include <iostream>
#include <assert.h>
#include <algorithm>
using namespace std;

// https://leetcode.com/problems/two-sum/
class Solution {
public:
#define VALIDATE(i, j) \
  if (board[i][j] == '.') continue; \
  int val = board[i][j] - '0'; \
  if (flags[val]) { \
    return false; \
  } \
  flags[val] = true; \

  bool isValidSudoku(vector<vector<char>>& board1) {
    vector<string> board = { "......5..",".........",".........","93..2.4..","..7...3..",".........","...34....",".....3...",".....52.."
  };

    int i, j;

    for (i = 0; i < 9; i++) {
      for (j = 0; j < 9; j++) {
        printf("%c ", board[i][j]);
      }
      printf("\n");
    }

    const int FLAGSIZE = 10;
    bool flags[FLAGSIZE];
    memset(&flags, false, FLAGSIZE);
    // check rows
    for (i = 0; i < 9; i++) {
      for (j = 0; j < 9; j++) {
        VALIDATE(i,j)
      }
      memset(&flags, false, FLAGSIZE);
    }
    // check columns
    for (i = 0; i < 9; i++) {
      for (j = 0; j < 9; j++) {
        VALIDATE(j, i)
      }
      memset(&flags, false, FLAGSIZE);
    }

    int startI = 0, startJ = 0;
    while (startI < 9) {
      while (startJ < 9) {
        for (i = startI; i < (startI + 3); i++) {
          for (j = startJ; j < (startJ + 3); j++) {
            VALIDATE(i, j)
          }
        }
        memset(&flags, false, FLAGSIZE);
        startJ += 3;
      }
      startJ = 0;
      startI += 3;
    }
    
    return true;
  }
};

int _36(int argc, _TCHAR* argv[])
{
  vector<string> board = { "..5.....6", "....14...", ".........", ".....92..", "5....2...", ".......3.", "...54....", "3.....42.", "...27.6.." };

  Solution s;
  vector<vector<char>> a;
  printf("%d\n", s.isValidSudoku(a));
  return 0;
}