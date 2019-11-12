// Sean Wright
// lab2.cpp

#include <iostream>
#include <fstream>

using namespace std;

struct Node
{
  int data;
  Node* next;
};

const string FILENAME = "/home/fac/sreeder/class/cs2430/lab2.dat";

bool insertInOrder(Node*& h, int d);
// inserts d into h in numerical order
// returns false if no memory available
// post: h may be changed

void printList(Node* h);
// prints all data on h to the screen in a column

void delList(Node*& h);
// post: each node of h deleted

int main()
{
  Node* head = nullptr;
  ifstream inFile;
  int num;
	cout<<"before file."<<endl;
  inFile.open(FILENAME);
  if (inFile.fail()){
	cout << "file problem...exiting program...press enter...";
	cin.get();
  }
	cout<<"before while main";
  while (inFile >> num && insertInOrder(head, num));
	
  cout << endl;
  printList(head);

  cout << endl << endl;
  
  delList(head);
	
  return 0;
}


bool insertInOrder(Node*& h, int d)
{
  Node* tmp = new Node;
  tmp->data = d;
  Node* ptr;
  if(h == nullptr || (h->data > tmp->data)){
	  tmp->next = h;
	  h = tmp;
	  cout<<"after if";
  }
  else
  {
	  ptr = h;
	  while(ptr->next != nullptr && (ptr->next->data < tmp->data))
		  ptr = ptr->next;
	  tmp->next = ptr->next;
	  ptr->next = tmp;
	  
  }
  return true; 
}

void printList(Node* h)
{
	Node* tmp = new Node;
	tmp = h;
	while(tmp != nullptr)
	{
		cout<<tmp->data<<endl;
		tmp = tmp->next;
	}
}

void delList(Node*& h)
{
	Node* deletePtr = new Node;
	while(h !=nullptr)
	{
		deletePtr = h;
		h = h->next;
		delete deletePtr;
	}
}
