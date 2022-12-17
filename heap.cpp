#include "heap.h"
#include "huffmanNode.h"
#include <iostream>
using namespace std;

heap::heap() : heap_size(0){
  Heap.push_back(NULL);

}



heap::heap(vector<huffmanNode*> forest) : heap_size(forest.size()){
  Heap = forest;
  Heap.push_back(Heap[0]);
  Heap[0] = NULL;

  for (int i = heap_size/2; i > 0; i--){
    percolateDown(i);
  }
}



heap::~heap(){
  destruct(findMin());


}

void heap::destruct(huffmanNode* cur){

    if (cur->rightChild != NULL){
      destruct(cur->rightChild);
    }
    if (cur->leftChild != NULL){
      destruct(cur->leftChild);
    }
    delete cur;
  
}
  


void heap::insert(huffmanNode* h){

  Heap.push_back(h);

  percolateUp(++heap_size);


}


huffmanNode* heap::findMin(){
  if (heap_size == 0){
    throw "findMin() called on empty heap";
  }
  return Heap[1];
}

huffmanNode* heap::deleteMin(){
  if (heap_size == 0){
    throw "deleteMin() called on empty heap";
  }

  huffmanNode* ret = Heap[1];
  Heap[1] = Heap[heap_size--];
  Heap.pop_back();

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
  Heap.resize(1);
  
  

  
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
    cout << "( " << Heap[i]->g << ", " << Heap[i]->freq << ") " << endl;
    bool isPow2 = (((i+1)& ~(i))==(i+1))? i+1 : 0;
    if (isPow2){
      cout << endl << "\t";
    }
  }
  cout << endl;

  
  /// figure out how to print later
}


  

void heap::percolateUp(int hole){
  huffmanNode* x = Heap[hole];

  for ( ; (hole > 1) && (x->freq < Heap[hole/2]->freq); hole /= 2){
    Heap[hole] = Heap[hole/2];
  }

  Heap[hole] = x;
  
}




void heap::percolateDown(int hole){


  huffmanNode* x = Heap[hole];

  while (hole*2 <= heap_size){
    int child = hole*2;

    if ((child+1 <= heap_size) && (Heap[child+1]->freq < Heap[child]->freq)) {
      child++;
    }

    if (x->freq > Heap[child]->freq){
      Heap[hole] = Heap[child];
      hole = child;
    }
    else{
      break;
    }
  }

  Heap[hole] = x;


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
					      
  

