//heap.cpp
//sean wright
//implementation file for heap class

#include "heap.h"
#include <iostream>


using namespace std;

heap::heap(){
	currentSize = 0;
	maxSize = 20;
	HeapArr = new int[maxSize]; 
	
}
heap::~heap(){
	
	delete[] HeapArr;
	
}
heap::heap(const heap &aheap){
	//copy constructor
	//if(!aheap.HeapArr[1]) 
		int i = 0;
		
}
heap& heap::operator=(const heap &rhs){
	//if(this != rhs){
		//delete
		//copy
		//heap
	//	return *this;
	//}
	int i = 0;
}

void heap::percolateUp(int hole){
	Node temp = new Node;
	temp.priority = HeapArr[hole];
	int temp_value = temp.priority;
	while(hole > 1 && temp_value< HeapArr[hole/2])
	{
		HeapArr[hole] = HeapArr[hole/2];
		hole = hole /2;
	}
	HeapArr[hole] = temp_value;
}

void heap::percolateDown(int hole){
  Node temp = new Node;
  temp.priority = HeapArr[hole];
  int temp_value = temp.priority;
  while ((hole*2 <= currentSize && temp_value >HeapArr[hole*2]) || (hole*2+1 <= currentSize && temp_value > HeapArr[hole*2+1])){
    if (hole*2+1 <= currentSize && HeapArr[hole*2+1] < HeapArr[hole*2]){
      HeapArr[hole] = HeapArr[hole*2+1];
      hole = hole*2+1;
    }else{
      HeapArr[hole] = HeapArr[hole*2];
      hole = hole*2;
    }
  }
  HeapArr[hole] = temp_value; 
}
void heap::resizeArr(){
	int newSize = 1.5 * maxSize;
	int newArr = new int[newSize];
	for(int i = 0; i <maxSize + 1; i++){
		newArr[i] = HeapArr[i];
	}
	HeapArr = newArr;
	maxSize = newSize;
}
void heap::insert(int a){
	Node newNode = new Node;
	newNode.priority = a;
	newNode.old_priority = a;
	if(currentSize + 1 <= maxSize)
			resizeArr(); 
	else{
		int hole = ++currentSize;
		while(hole > 1 && a < HeapArr[hole/2]){
			HeapArr[hole] = HeapArr[hole/2];
			hole = hole/2;
		}
		HeapArr[hole] = newNode.priority;
		percolateUp(newNode.priority);   
	}
}
void changePriority(int &oldPriority, int *newPriority){
	
	int place;
	for(int i = 0; i < maxSize; i++)
		if(HeapArr[i] = oldPriority)
			place = i;
		
}
void heap::deleteMin(int b){
	Node a = new Node;
	a.priority = HeapArr[b];
	a.old_priority = HeapArr[1];
	
	return x;
}
bool heap::isEmpty(){
	if(HeapArr[1])
		return true;
	else
		return false;
}

