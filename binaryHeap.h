#ifndef BINARYHEAP_H
#define BINARYHEAP_H
#include <string>
#include "huffmanNode.h"
#include <vector>
using namespace std;

class binaryHeap{
 public:
  binaryHeap();
  ~binaryHeap();
  binaryHeap(vector<huffmanNode*> forest);


  void insert(huffmanNode* h);
  huffmanNode* findMin();
  huffmanNode* deleteMin();
  int size();
  void makeEmpty();
  bool isEmpty();
  void print();
  void buildTree();


 private:

  vector<huffmanNode*> heap;
  unsigned int heap_size;
  void percolateUp(int hole);
  void percolateDown(int hole);
};

#endif
  
  
