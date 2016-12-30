#include "stdafx.h"
#include <vector>
#include <unordered_map>
#include <string>
#include <iostream>
#include <assert.h>



struct ListNode {
  int val;
  ListNode *next;
};


class Utility {
public:
  void sort(std::vector<int>& input) {
    for (size_t i = 0; i < input.size(); i++) {
      size_t j = i;
      while (j > 0 && input[j - 1] > input[j]) {
        int temp = input[j];
        input[j] = input[j - 1];
        input[j - 1] = temp;
        j--;
      }
    }
  }

  // Appends a node to lastNode and returns appended node
  ListNode* CreateLinkedList(int inputArray[], int length) {
    if (length == 0)
      return nullptr;
    ListNode* headNode = (ListNode*)malloc(sizeof(ListNode));
    headNode->val = inputArray[0];
    headNode->next = nullptr;
    ListNode *tempNode = headNode;
    for (int i = 1; i < length; i++) {
      ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
      newNode->val = inputArray[i];
      newNode->next = nullptr;
      tempNode->next = newNode;
      tempNode = newNode;
    }
    return headNode;
  }

  ListNode* CreateLinkedList(ListNode *currNode, int number) {
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode->val = number;
    newNode->next = nullptr;
    if (currNode != nullptr) {
      currNode->next = newNode;
    }
    return newNode;
  }

  void PrintList(ListNode* headNode) {
    for (ListNode* currNode = headNode; currNode != nullptr; currNode = currNode->next) {
      printf("%d ", currNode->val);
    }
    printf("\n");
  }

};
