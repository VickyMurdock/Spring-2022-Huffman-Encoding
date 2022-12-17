#include "huffmanNode.h"
#include <string>
using namespace std;

huffmanNode::huffmanNode(char gg, int freqq){
  
  g = gg;
  freq = freqq;
  leftChild = NULL;
  rightChild = NULL;

}

huffmanNode::~huffmanNode(){
}
