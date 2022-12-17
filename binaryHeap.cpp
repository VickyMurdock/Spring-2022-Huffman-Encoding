#include "heap.h"
#include "huffmanNode.h"
#include <iostream>
using namespace std;

heap::heap() : heap_size(0){
  heap.push_back(NULL);

}



heap::heap(vector<huffmanNode*> forest) : heap_size(forest.size()){
  heap = forest;
  heap.push_back(heap[0]);
  heap[0] = NULL;

  for (int i = heap_size/2; i > 0; i--){
    percolateDown(i);
  }
}



heap::~heap(){
  // go back and fix this


 
}
/*
void binaryHeap::destruct(huffmanNode* cur){
  if ((cur->rightChild == NULL) && (cur->leftChild == NULL)){
    delete cur;
  }
  else{
    if (cur->rightChild
  

*/
void heap::insert(huffmanNode* h){

  heap.push_back(h);

  percolateUp(++heap_size);


}


huffmanNode* heap::findMin(){
  if (heap_size == 0){
    throw "findMin() called on empty heap";
  }
  return heap[1];
}

huffmanNode* heap::deleteMin(){
  if (heap_size == 0){
    throw "deleteMin() called on empty heap";
  }

  huffmanNode* ret = heap[1];
  heap[1] = heap[heap_size--];
  heap.pop_back();

  if (!isEmpty()){
    percolateDown(1); 
  }

 
  return ret;
}

int heap::size(){
  return heap_size;
}




void heap::makeEmpty(){
  
  heap_size = 0;
  heap.resize(1);
  
  

  
}

bool heap::isEmpty(){
  return heap_size == 0;
}

void heap::print(){
  /*
  if (heap_size > 0){
    

  for (int i = 1; i <= heap_size; i++){
    cout <<"( "<< heap[i]->g << ", " << heap[i]->freq << ") " << endl;
  }
  }
  */


  // cout << "(heap[0])" << endl;
  for (int i = 1; i <= heap_size; i++){
    cout << "( " << heap[i]->g << ", " << heap[i]->freq << ") " << endl;
    bool isPow2 = (((i+1)& ~(i))==(i+1))? i+1 : 0;
    if (isPow2){
      cout << endl << "\t";
    }
  }
  cout << endl;

  
  /// figure out how to print later
}


  

void heap::percolateUp(int hole){
  huffmanNode* x = heap[hole];

  for ( ; (hole > 1) && (x->freq < heap[hole/2]->freq); hole /= 2){
    heap[hole] = heap[hole/2];
  }

  heap[hole] = x;
  
}




void heap::percolateDown(int hole){


  huffmanNode* x = heap[hole];

  while (hole*2 <= heap_size){
    int child = hole*2;

    if ((child+1 <= heap_size) && (heap[child+1]->freq < heap[child]->freq)) {
      child++;
    }

    if (x->freq > heap[child]->freq){
      heap[hole] = heap[child];
      hole = child;
    }
    else{
      break;
    }
  }

  heap[hole] = x;


}



void heap::buildTree(){
  /*
 
  while (heap_size != 0){
    huffmanNode* temp1 = deleteMin();
    huffmanNode* temp2 = deleteMin();
  
    huffmanNode* temp = new huffmanNode('T', temp1->freq + temp2->freq);
    temp->leftChild = temp1;
    temp->rightChild = temp2;
    insert(temp);
  
  }


  */
}
					      
  

