#include "stdafx.h"
#include <vector>
#include <unordered_map>
#include <string>
#include <iostream>
#include <assert.h>
using namespace std;

// https://leetcode.com/problems/swap-nodes-in-pairs/
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
  ListNode* swapPairs(ListNode* head) {
    if (head == nullptr) {
      return nullptr;
    }
    ListNode* headNext = head->next;

    if (headNext == nullptr) {
      return head;
    }

    ListNode* headNextNext = headNext->next;
    ListNode* swapped = swapPairs(headNextNext);
    head->next = swapped;
    headNext->next = head;
    return headNext;
  }
};

int _24(int argc, _TCHAR* argv[])
{
  int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
  ListNode *head = new ListNode(arr[0]);
  ListNode *temp = head;
  for (int i = 1; i < sizeof(arr) / sizeof(int); i++) {
    temp->next = new ListNode(arr[i]);
    temp = temp->next;
  }
  Solution s;
  ListNode* swapped = s.swapPairs(head);
  temp = swapped;
  while (temp != nullptr) {
    printf("%d->", temp->val);
    temp = temp->next;
  }
  printf("\n");
  return 0;
}