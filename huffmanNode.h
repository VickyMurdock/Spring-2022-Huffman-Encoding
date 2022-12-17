#ifndef HUFFMANNODE_H
#define HUFFMANNODE_H
#include <string>

using namespace std;

class huffmanNode{
public:
  huffmanNode(char gg, int freqq);
  ~huffmanNode();

  char g;
  int freq;
  huffmanNode* leftChild;
  huffmanNode* rightChild;


  friend class Heap;
};

#endif

  
