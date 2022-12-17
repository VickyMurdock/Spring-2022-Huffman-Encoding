#ifndef BINARYHEAP_H
#define BINARYHEAP_H
#include <string>
#include "huffmanNode.h"
#include <vector>
using namespace std;

class heap{
 public:
  heap();
  ~heap();
  void destruct(huffmanNode* cur);
  heap(vector<huffmanNode*> forest);


  void insert(huffmanNode* h);
  huffmanNode* findMin();
  huffmanNode* deleteMin();
  int size();
  void makeEmpty();
  bool isEmpty();
  void print();
  void buildTree();


 private:

  vector<huffmanNode*> Heap;
  unsigned int heap_size;
  void percolateUp(int hole);
  void percolateDown(int hole);
};

#endif
  
  
