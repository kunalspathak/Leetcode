#include "stdafx.h"
#include <vector>
#include <unordered_map>
#include <string>
#include <iostream>
#include <assert.h>
using std::vector;
using string = std::string;

// https://leetcode.com/problems/two-sum/
class Solution {
public:
  int maxArea(vector<int>& height) {
    int maxArea = 0;
    int length = height.size();
   /* int line1 = -1;
    int line2 = -1;*/
    for (int i = 0; i < length; i++) {
      int maxMinElem = -1;
      int leftMost = height[i];
      if (leftMost == 0)
        continue;
      for (int j = length - 1; j >= (i + 1); j--) {
        int rightMost = height[j];
        if (rightMost == 0)
          continue;
        int currArea = leftMost * (j - i);
        if (currArea < maxArea) {
          break;
        }
        // If found a greater element than leftMost, use it
        if (leftMost <= rightMost) {
          if (maxArea < currArea) {
            // line1 = i;
            //line2 = j;
            maxArea = currArea;
          }
          break;
        }
        // else if found smaller element, check if it max of smaller elements
        else {
          if (maxMinElem < rightMost) {
            maxMinElem = rightMost;
            int currArea = rightMost * (j - i);
            if (maxArea < currArea) {
              // line1 = i;
              //line2 = j;
              maxArea = currArea;
            }
          }
        }
      }
    }
    //printf("line1 : %d, line2 = %d, maxArea = %d\n", line1, line2, maxArea);
    return maxArea;
  }
};

int _tmain(int argc, _TCHAR* argv[])
{
  Solution s;
  /* 11 */
  //int arr[7] = { 2, 3, 4, 5, 18, 17, 6 };
  // Expected output : 17, actual : 16
  int arr[15001];
  for (int i = 0;i <= 15000;i++) {
  arr[i] = 15000 - i;
  }
  vector<int> vec(arr, arr + sizeof(arr) / sizeof(arr[0]));
  s.maxArea(vec);
  return 0;
}