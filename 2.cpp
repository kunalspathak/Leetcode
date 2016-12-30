#include "stdafx.h"
#include <vector>
#include <unordered_map>
#include <string>
#include <iostream>
#include <assert.h>
#include "Utility.h"
// https://leetcode.com/problems/add-two-numbers/
class Solution {

public:
  // (2 -> 4 -> 3) + (5 -> 6 -> 4)
  // result = 7 -> 0 -> 8
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    Utility u;
    ListNode* headNode = nullptr;
    ListNode* result = nullptr, *left = l1, *right = l2;
    int sum, lsb, carry = 0;
    for (; left != nullptr && right != nullptr; left = left->next, right = right->next)
    {
      sum = left->val + right->val + carry;
      lsb = sum % 10;
      carry = sum / 10;

      result = u.CreateLinkedList(result, lsb);
      if (headNode == nullptr) {
        headNode = result;
      }

    }

    // Process remaining left list
    while (left != nullptr) {
      sum = left->val + carry;
      lsb = sum % 10;
      carry = sum / 10;

      result = u.CreateLinkedList(result, lsb);
      if (headNode == nullptr) {
        headNode = result;
      }
      left = left->next;
    }

    // Process remaining right list
    while (right != nullptr) {
      sum = right->val + carry;
      lsb = sum % 10;
      carry = sum / 10;

      result = u.CreateLinkedList(result, lsb);
      if (headNode == nullptr) {
        headNode = result;
      }
      right = right->next;
    }

    // Process remaining carry bit
    while (carry != 0) {
      lsb = carry % 10;
      carry = carry / 10;
      result = u.CreateLinkedList(result, lsb);
    }

    return headNode;
  }

};


int _2(int argc, _TCHAR* argv[])
{
  Utility u;
  Solution s;

  int input1[] = { 9, 2, 9 };
  ListNode *l1 = u.CreateLinkedList(input1, (int)(sizeof(input1) / sizeof(input1[0])));
  int input2[] = { 9, 3, 1, 2, 7, 5 };
  ListNode *l2 = u.CreateLinkedList(input2, (int)(sizeof(input2) / sizeof(input2[0])));
  printf("List 1 :");
  u.PrintList(l1);

  printf("List 2 :");
  u.PrintList(l2);

  ListNode* l3 = s.addTwoNumbers(l1, l2);
  printf("Answer :");
  u.PrintList(l3);
  return 0;
}