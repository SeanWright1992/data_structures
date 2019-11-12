//Sean Wright
//p2.cpp
//This program tests our understanding of linked lists
//how to traverse them and making output files etc.
#include <iostream>
#include <fstream>
#include <random>

using namespace std;

struct Node{
  int data;
  Node* next;
};

void insertInOrder(Node*& h, int d);
// inserts d into h in numerical order

void updateList(Node* h, bool first);
// Outputs all data on stack to the correct output file

void delList(Node*& h);
// post: each node of h deleted

bool delNode(Node*& h, bool smallest, bool largest, bool middle);
//Deletes a specific node from stack

int main(){
  Node* head = nullptr;
  int randomValue =0;
  //Since I call the update list function twice, I use a bool start to 
  //differentiate if it should write outputs to file A or B
  bool start = true;
  //Placeholders used to make sure that all three nodes are deleted
  bool placeHolder1 = true, placeHolder2 = true, placeHolder3 = true;

  //Generate random seed
  random_device rd;

  // Initialize Mersenne Twister pseudo-random number generator
  mt19937 gen(rd());

  //Generate pseudo-random numbers
  //uniformly distributed in range 1- 100
  uniform_int_distribution<> dis(1, 100);
 
  for(int i = 0; i < 50; i++){
	randomValue = dis(gen);
	insertInOrder(head, randomValue);  
  }
  updateList(head, start);
  start = false;
  cout<<"The output file A has been created and filled."<<endl;
  cout<<"  Now deleting three nodes,"<<endl;
  cout<<"one with the smallest and largest value, and one inbetween."<<endl;
  //Order of booleans to be deleted is smallest, largest, middle
  placeHolder1 = delNode(head, true, false, false);
  placeHolder2 = delNode(head, false, true, false);
  placeHolder3 = delNode(head, false, false, true);

  if(placeHolder1 && placeHolder2 && placeHolder3)
	cout<<"Successfully deleted middle, smallest and largest nodes."<<endl;
  else
	cout<<"Didn't successfully delete the three nodes."<<endl;
  updateList(head, start);
  delList(head);
  return 0;
}

//inserts nodes in linked list in an ascending fashion
void insertInOrder(Node*& h, int d){
  Node* tmp = new Node;
  Node* ptr;
  tmp->data = d;
  if(h == nullptr || (h->data > tmp->data)){
    tmp->next = h;
    h = tmp;
  }
  else{
    ptr = h;
    while(ptr->next != nullptr && (ptr->next->data < tmp->data))
	  ptr = ptr->next;
    tmp->next = ptr->next;
    ptr->next = tmp;
  
  }
}

//Function to output the linked lists to 2 different output text files
void updateList(Node* h, bool first){	
  Node* tmp = new Node;
  tmp = h;
  if(first){
	ofstream myfileA;
	myfileA.open("P2OutputA.txt");
	while(tmp != nullptr){
		myfileA << tmp->data<<endl;
		tmp = tmp->next;
	}
  }
  else{
	ofstream myfileB;
	myfileB.open("p2OutputB.txt");
	while(tmp != nullptr){
		myfileB << tmp->data<<endl;
		tmp = tmp->next;	
	}
  }
}

//deletes entire linked list
void delList(Node*& h){
  Node* deletePtr = new Node;
  while(h !=nullptr){
	deletePtr = h;
	h = h->next;
	delete deletePtr;
  }
}

//deletes a node in a linked list; middle and both ends
bool delNode(Node*& h, bool smallest, bool largest, bool middle){
  Node* deletePtr = h;
  Node* dlt = new Node;
  if(h->next == nullptr || h->next->next == nullptr){
	cout<<"Too few nodes, need at least three."<<endl;
	return false;
  }
  else if(smallest && !largest && !middle){
	dlt = deletePtr;
	h = h->next;
	cout<<"Deleting "<<dlt->data<<"."<<endl;
	delete dlt;
	return true;
  }
  else if(!smallest && largest && !middle){
	while(deletePtr->next->next !=nullptr)
		deletePtr = deletePtr->next;
	dlt = deletePtr->next;
	deletePtr->next = nullptr;
	cout<<"Deleting "<<dlt->data<<"."<<endl;
	delete dlt;
	return true;
  }
  else if(!smallest && !largest && middle){
	dlt = deletePtr->next;
	deletePtr->next = dlt->next;
	cout<<"Deleting "<<dlt->data<<"."<<endl;
	delete dlt;
	return true;
  }
  else{
	cout<<"Didn't want to delete any node."<<endl;
	return false;
  }
}
