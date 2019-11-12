//sean wright
//lab 3.cpp
//binary search tree file

#include <iostream>
#include <fstream>

using namespace std;

struct Node
{
  int key; 
  Node* left;
  Node* right;
};

void inOrder(Node* root);
void preOrder(Node* root);
void postOrder(Node* root);
bool insert(Node*& root, int k);
void deleteAll(Node*& root);
int main()
{
	Node* root = nullptr;
	int test [10] = {2,6,3,9,6,6,7,10,12,1};
	for(int i = 0; i <10; i++)
		insert(root, test[i]);
	cout<<"In-order: ";
	inOrder(root);
	cout<<endl<<"Pre-order: ";
	preOrder(root);
	cout<<endl<<"Post-order: ";
	postOrder(root);
	cout<<endl<<endl;
	deleteAll(root);
	if(root != nullptr)
		cout<<"Root isn't nullptr.";
	else
		cout<<"Root is nullptr.";
	return 0;
}


bool insert(Node*& root, int k)
{
	if (root ==nullptr){
		root = new Node;
		root->key = k;
		root->left = nullptr;
		root->right = nullptr;
		return true;
	}
	else if(root->key ==k)
		return false;
	else if(root->key >k)
		return insert(root->left,k);
	else 
		return insert(root->right,k);
}

void inOrder(Node* root)
{
	if(root != nullptr){
		inOrder(root->left);
		cout<<root->key<<" ";
		inOrder(root->right);
	}
	
}

void preOrder(Node* root)
{
	if(root != nullptr){
		cout<<root->key<<" ";
		preOrder(root->left);
		preOrder(root->right);
	}
}

void postOrder(Node* root)
{
	if(root != nullptr){
		postOrder(root->left);
		postOrder(root->right);
		cout<<root->key<<" ";
	}
}

void deleteAll(Node*& root)
{
	if(root != nullptr){
		deleteAll(root->left);
		deleteAll(root->right);
		delete root;
		root = nullptr;
	}
}
