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

private:
  ListNode** headRef;
  bool startReversing;

public:
  Solution::Solution() : startReversing(false) {
    headRef = (ListNode**)malloc(sizeof(ListNode*));
    *headRef = nullptr;
  }


  ListNode* reverseKGroup(ListNode* head, int k) {
    if (k == 0 || k == 1) {
      return head;
    }
    swapPairs(head, k, 1);
    return *headRef != nullptr ? *headRef : head;
  }

  ListNode* swapPairs(ListNode* head, int k, int index) {
    if (head == nullptr || head->next == nullptr) {
      if (index == 0) {
        this->startReversing = true;
        *headRef = head;
      }
      return head;
    }

    ListNode* rest = swapPairs(head->next, k, (index + 1) % k);

    if (index == 0) {
      head->next = this->startReversing ? *headRef : rest;
      *headRef = head;
      this->startReversing = true;
    }
    else if (this->startReversing) {
      ListNode* t = rest->next;
      rest->next = head;
      head->next = t;
    }

    return head;
  }
};

int _25(int argc, _TCHAR* argv[])
{
  int arr[] = {1 ,2,3,4,5,6};
  ListNode *head = new ListNode(arr[0]);
  ListNode *temp = head;
  for (int i = 1; i < sizeof(arr) / sizeof(int); i++) {
    temp->next = new ListNode(arr[i]);
    temp = temp->next;
  }
  Solution s;
  ListNode* swapped = s.reverseKGroup(head, 1);
  while (swapped != nullptr) {
    printf("%d->", swapped->val);
    swapped = swapped->next;
  }
  printf("\n");
  return 0;
}