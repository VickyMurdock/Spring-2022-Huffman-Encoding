#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <unordered_set>
#include <vector>
#include <map>
#include "heap.h"
#include "huffmanNode.h"

using namespace std;
void findCode(huffmanNode* cur, string code, map <char, string> &codekey );


 
	  



int main(int argc, char** argv){

  unordered_set<char> character;



  vector<char> first;


  if (argc != 2){
    cout << "Must supply the input file name as the one and only parameter" << endl;
    exit(1);
  }




  ifstream file(argv[1]);
  ifstream mine(argv[1]);
 

         // read in characters one by one, until reading fails (we hit the end of the file)
    char g;
    char h;
    map <char,int> freq;
    int cnt=0;  



    while (file.get(g)){
      if ((g >= 0x20) && (g<= 0x7e)){
	// cout << g << endl;
      while (mine.get(h)){
	if ( h == g){
	  cnt++;
	}
      }
      mine.clear();
      mine.seekg(0);
      freq.insert(pair<char, int>(g, cnt));
      cnt = 0;
      }
    }


    // now, I should have a map with the characters and frequency


    map<char, int>::iterator itr;
    heap bHeap;
    vector<huffmanNode*> forest;
    
    for (itr = freq.begin(); itr != freq.end(); ++ itr){
  
     
      

       huffmanNode* newnode = new huffmanNode(itr->first, itr->second);
       bHeap.insert(newnode);
    
    }



    while (bHeap.size() > 1){
    
    huffmanNode* temp1 = bHeap.deleteMin();
    
    huffmanNode* temp2 = bHeap.deleteMin();
  
    huffmanNode* temp = new huffmanNode('T', temp1->freq + temp2->freq);

    temp->leftChild = temp1;
  
    temp->rightChild = temp2;

    bHeap.insert(temp);


    
    }

   
 
    map <char, string> codekey;


    findCode(bHeap.findMin(), "", codekey);

    map<char, string>::iterator bitr;


     for (bitr = codekey.begin(); bitr != codekey.end(); ++bitr){
      
        cout <<" " << bitr->first << " "<< bitr->second<< endl;
  
    }

    
     

    

    


    

    
    // a nice pretty separator
    cout << "----------------------------------------" << endl;




    


 
    


    file.clear();
    file.seekg(0);
    string years ="";

        // Read the file again, and print to the screen
    float counter = 0;
    while (file.get(g)) {
         if ((g >= 0x20) && (g<= 0x7e)){
	   bitr = codekey.find(g);
	   if (bitr != codekey.end()){
	     cout << bitr->second << " ";
	     years = years+ bitr->second;

	   }
	   
      counter++;
	 }
    }
    
    cout << endl;
    cout << "----------------------------------------" << endl;

    // close the file
    file.close();
    float compression = (8*counter)/years.length();
    float cost = 0;
    for (itr = freq.begin(); itr != freq.end(); ++itr){
      bitr = codekey.find(itr->first);
      cost = (float)cost + (float)(itr->second*(bitr->second).length());
      cout<<cost<<endl;
    }

    cost = cost/(float)(counter);
    cost = (float)cost;




    cout << "There are a total of " << counter << " symbols that are encoded." << endl;
    cout << "There are "<< freq.size() << " distinc symbols used." << endl;
    cout << "There were " << 8*counter<< " bits in the original file." << endl;
    cout << "There were " <<years.length() << " bits in the compressed file." << endl;
    cout << "This gives a compression ratio of " << compression << "." << endl;
    cout << "The cost of the Huffman tree is " << cost << " bits per character." << endl;

    return 0;




}


void findCode(huffmanNode* cur, string code,  map <char, string> &codekey ){
  // cout << code << endl;
  if ((cur->leftChild == NULL) && (cur->rightChild == NULL)){
    codekey.insert(pair<char,string>(cur->g, code));
    //  cout << "(" << cur->g << "," << code << ")" << endl;
   
  }
  else{
    if (cur->rightChild != NULL){
      findCode(cur->rightChild, code + "1", codekey);
    }
    if (cur->leftChild != NULL){
      findCode(cur->leftChild, code + "0", codekey);
    }
  }
}
   
