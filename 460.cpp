#include "stdafx.h"
#include <vector>
#include <unordered_map>
#include <string>
#include <iostream>
#include <assert.h>


// https://leetcode.com/problems/lfu-cache/
class LFUCache {
public:
  LFUCache(int capacity) {
    this->capacity = capacity;
    this->headFNode = nullptr;
    this->size = 0;
  }

  int get(int key) {
    auto hashValue = hashMap.find(key);
    if (hashValue == hashMap.end()) {
      printf("Not found\n");
      return -1;
    }
    else {
      CNode* cNode = (*hashValue).second;
      wrapper(cNode);
      int d = cNode->value;
      printf("Found %d\n", d);
      return d;
    }
  }

  void set(int key, int value) {
    auto hashValue = hashMap.find(key);
    if (hashValue == hashMap.end()) {
      // Doesn't exist, create new
      if (this->capacity == this->size) {
        // Delete entry of evicted node from hashMap
        CNode* evicted = evict();
        printf("Evicted %d\n", evicted->key);
        hashMap.erase(evicted->key);
        free(evicted);
      }
      else {
        this->size++;
      }
      CNode* newNode = createCNode(key, value);
      wrapper(newNode);
      hashMap[key] = newNode;
    }
    else {
      CNode* existingNode = (*hashValue).second;
      assert(existingNode->key == key);
      existingNode->value = value;
      wrapper(existingNode);
    }
  }

private:

  int capacity;
  int size;

  struct FNode;
  struct CNode {
    int key;
    int value;
    CNode *prev, *next;
    FNode* parent;
  };

  struct FNode {
    int freq;
    FNode *prev, *next;
    CNode *first, *last;
  };

  FNode ** headFNode;
  std::unordered_map<int, CNode*> hashMap;

  CNode * createCNode(int _key, int _value) {
    CNode * node = (CNode *)malloc(sizeof(CNode));
    node->key = _key;
    node->value = _value;
    node->next = nullptr;
    node->prev = nullptr;
    node->parent = nullptr;
    return node;
  }

  FNode * createFNode(int _freq) {
    FNode * node = (FNode *)malloc(sizeof(FNode));
    node->freq= _freq;
    node->next = nullptr;
    node->prev = nullptr;
    node->first = nullptr;
    node->last = nullptr;
    return node;
  }

  // Gets or create FNode with 1-freq. This is usually 1st node in the FList
  FNode * getOrCreateFreqOneNode() {
    if (headFNode == nullptr) {
      headFNode = (FNode **)malloc(sizeof(FNode*));
      *headFNode = nullptr;
    }
    FNode * firstFNode = *headFNode;
    if (firstFNode == nullptr) {
      firstFNode = createFNode(1);
      *headFNode = firstFNode;
    }
    else if (firstFNode->freq != 1) {
      FNode * oneFreqNode = createFNode(1);
      oneFreqNode->next = firstFNode;
      firstFNode->prev = oneFreqNode;
      *headFNode = oneFreqNode;

      firstFNode = oneFreqNode;
    }
    return firstFNode;
  }

  void wrapper(CNode* curr) {
    FNode* currFreqNode = curr->parent;

    // If this is new node, insert in 1-freq list
    if (currFreqNode == nullptr) {
      currFreqNode = getOrCreateFreqOneNode();
      insertInFList(currFreqNode, curr);
      return;
    }

    int currFreq = currFreqNode->freq;
    FNode* nextFreqNode = currFreqNode->next;
    if (nextFreqNode == nullptr) {
      nextFreqNode = createFNode(currFreq + 1);
      currFreqNode->next = nextFreqNode;
      nextFreqNode->prev = currFreqNode;
    }
    else if (nextFreqNode->freq != currFreq + 1) {
      FNode *newFreqNode = createFNode(currFreq + 1);
      nextFreqNode->prev->next = newFreqNode;
      newFreqNode->prev = nextFreqNode->prev;
      newFreqNode->next = nextFreqNode;
      nextFreqNode->prev = newFreqNode;
      nextFreqNode = newFreqNode;
    }

    removeFromFList(currFreqNode, curr);
    insertInFList(nextFreqNode, curr);
  }

  CNode* evict() {
    assert(headFNode && *headFNode);
    FNode* fNode = *headFNode;
    CNode* cNodeToEvict = fNode->last;
    removeFromFList(fNode, cNodeToEvict);
    return cNodeToEvict;
  }

  void removeFromFList(FNode* currFreqNode, CNode *curr) {
    assert(curr->parent == currFreqNode);
    assert(currFreqNode->first);
    assert(currFreqNode->last);
    if (currFreqNode->first == curr && currFreqNode->last == curr) {
      // If curr is the only node in currFreqNode
      currFreqNode->first = nullptr;
      currFreqNode->last = nullptr;
      
      if (currFreqNode->prev) {
        currFreqNode->prev->next = currFreqNode->next;
      }
      if (currFreqNode->next) {
        currFreqNode->next->prev = currFreqNode->prev;
      }

      // If this was 1st freq node, replace head with its next
      if (*headFNode == currFreqNode) {
        *headFNode = currFreqNode->next;
      }
      free(currFreqNode);
    }
    else if (currFreqNode->first == curr) {
      // If curr is the first node
      assert(curr->prev == nullptr);
      currFreqNode->first = curr->next;
      curr->next = nullptr;
    }
    else if (currFreqNode->last == curr) {
      // If curr is the last node
      assert(curr->next == nullptr);
      currFreqNode->last = curr->prev;
      curr->prev = nullptr;
    }
    else {
      // If curr is the intermediate node
      assert(curr->prev);
      assert(curr->next);
      curr->prev->next = curr->next;
      curr->next->prev = curr->prev;
      curr->prev = nullptr;
      curr->next = nullptr;
    }
    curr->parent = nullptr;
  }

  void insertInFList(FNode* newFreqNode, CNode *curr) {
    if (newFreqNode->first == nullptr && newFreqNode->last == nullptr) {
      // This is the new frequency node created
      newFreqNode->first = curr;
      newFreqNode->last = curr;
      curr->prev = nullptr;
      curr->next = nullptr;
    }
    else {
      CNode* currFNode = newFreqNode->first;
      newFreqNode->first = curr;
      curr->prev = nullptr;
      curr->next = currFNode;
      currFNode->prev = curr;
    }
    curr->parent = newFreqNode;
  }
};

int _tmain(int argc, _TCHAR* argv[])
{
  LFUCache cache(2);

  cache.set(1, 1);
  cache.set(2, 2);
  cache.set(2, 10);
  cache.set(2, 20);
  cache.set(3, 5);
  cache.get(2);
  cache.set(4, 5);
  cache.get(3);
  

  return 0;
}