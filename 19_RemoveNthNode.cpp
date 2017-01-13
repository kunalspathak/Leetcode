#include "stdafx.h"
#include <vector>
#include <unordered_map>
#include <string>
#include <iostream>
#include <assert.h>
#include <algorithm>
#include <stack>
using namespace std;

// https://leetcode.com/problems/remove-nth-node-from-end-of-list/

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode* removeNthFromEnd1(ListNode* head, int n) {
    if (head == nullptr) {
      return nullptr;
    }

    stack<ListNode*> s;
    ListNode * node = head;
    int count = 0;
    ListNode* result;
    while (node != nullptr) {
      count++;
      s.push(node);
      node = node->next;
    }

    if (n == count) {
      result = head;
    }
    else {

      int curr = 1;
      ListNode* prevNode = nullptr;

      while ((node = s.top()) != nullptr) {
        if (curr == n + 1) {
          prevNode = node;
          break;
        }
        curr++;
        s.pop();
      }

      result = prevNode->next;
      prevNode->next = result->next;
    }
    //printf("%d\n", result->val);
    return result;
  }
};

int _19(int argc, _TCHAR* argv[])
{
  int arr[] = { 1};
  ListNode *head = new ListNode(arr[0]);
  ListNode *temp = head;
  for (int i = 1; i < sizeof(arr) / sizeof(int); i++) {
    temp->next = new ListNode(arr[i]);
    temp = temp->next;
  }
  Solution s;
  s.removeNthFromEnd1(head, 1);
  return 0;
}