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
private:
  int noOfUnsolvedCells = 0;
public:
#define Validate(ch, used) \
      if (ch != '.') { \
        val = ch - '0' - 1; \
        if (used[val]) { \
          return false; \
        } \
        used[val] = true; \
      } \

  void solveSudoku(vector<vector<char>>& board1) {

    vector<string> board = {"..9748...", "7........", ".2.1.9...", "..7...24.", ".64.1.59.", ".98...3..", "...8.3.2.", "........6", "...2759.."};

    vector<int> unsolvedCells(81 * 2);
    int unsolvedCount = 0;
    for (int i = 0; i < board.size(); i++) {
      for (int j = 0; j < board.size(); j++) {
        if (board[i][j] == '.') {
          unsolvedCells[unsolvedCount++] = i;
          unsolvedCells[unsolvedCount++] = j;
        }
      }
    }
    this->noOfUnsolvedCells = unsolvedCount;
    sudokuSolver(board, unsolvedCells, 0);
  }

private:
  bool isValid(vector<string>& board, int currRow, int currCol) {
    bool used1[9] = { false }, used2[9] = { false }, used3[9] = { false };
    int boxI = currRow - (currRow % 3);
    int boxJ = currCol - (currCol % 3);
    int val;
    for (int i = 0; i < 9; i++) {
      char rowChar = board[currRow][i];
      char colChar = board[i][currCol];
      char boxChar = board[boxI + (i / 3)][boxJ + (i % 3)];
      Validate(rowChar, used1)
      Validate(colChar, used2)
      Validate(boxChar, used3)
    }
    return true;
  }

  bool sudokuSolver(vector<string>&board, vector<int> unsolved, int unsolvedIndex) {
    if (unsolvedIndex == this->noOfUnsolvedCells) {
      return true;
    }
    int currRow = unsolved[unsolvedIndex];
    int currCol = unsolved[unsolvedIndex + 1];

    for (int i = 0; i < 9; i++) {
      assert(board[currRow][currCol] == '.');
      board[currRow][currCol] = '0' + i + 1;
      if(!isValid(board, currRow, currCol)) {
        board[currRow][currCol] = '.';
        continue;
      }
      if (sudokuSolver(board, unsolved, unsolvedIndex + 2)) {
        return true;
      }
      board[currRow][currCol] = '.';
    }
    return false;
  }

};

int _37(int argc, _TCHAR* argv[])
{
  Solution s;
  vector<vector<char>> i;
  s.solveSudoku(i);
  return 0;
}