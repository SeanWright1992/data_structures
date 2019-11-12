//sean wright
//tree.cpp
//tree class file
#include <iostream>
#include "tree.h"
#include<queue>
#include<stack>
using namespace std;

//constructor
tree::tree()
{
	root = nullptr;
}

//destructor 
tree::~tree()
{
	destroyAll(root);
}

// copy constructor
tree::tree(const tree& atree)
{
  if (atree.root == nullptr)
    root = nullptr;
  else
    root = makeCopy(atree.root); 
}

//overload assignment operator
tree& tree::operator=(const tree& rhs)
{
  if (this != &rhs){
    destroyAll(root);
    root = makeCopy(rhs.root);
  }
  return *this;
}

// copy function for copy & overload operators
tree::treeNode* tree::makeCopy(treeNode* r)
{

  if (r == nullptr)
    return nullptr;
  else{
    treeNode* temp = new treeNode;
    temp->value = r->value;
    temp->left = makeCopy(r->left);
    temp->right = makeCopy(r->right);
    return temp;
  } 
}

void tree::insertNode(int num)
{
	treeNode *newNode = nullptr;	// Pointer to a new node.
   // Create a new node and store num in it.
   newNode = new treeNode;
   newNode->value = num;
   newNode->left = nullptr;
   newNode->right = nullptr;
   // Insert the node.
   insert(root, newNode);
}

void tree::insert(treeNode *&nodePtr, treeNode *&newNode)
{
   if (nodePtr == nullptr)
      nodePtr = newNode;                  // Insert the node.
   else if (newNode->value == nodePtr->value)
	   return;
   else if (newNode->value < nodePtr->value)
      insert(nodePtr->left, newNode);     // Search the left branch
   else 
      insert(nodePtr->right, newNode);    // Search the right branch
}

void tree::destroyAll(treeNode *&nodePtr)
{
   if (nodePtr){
      if (nodePtr->left)
         destroyAll(nodePtr->left);
      if (nodePtr->right)
         destroyAll(nodePtr->right);
      delete nodePtr;
	  nodePtr = nullptr;
   }
}

bool tree::searchNode(int num)
{
   treeNode *nodePtr = root;
   while (nodePtr){
      if (nodePtr->value == num)
         return true;
      else if (num < nodePtr->value)
         nodePtr = nodePtr->left;
      else
         nodePtr = nodePtr->right;
   }
   return false;
}

void tree::remove(int num)
{
   deleteNode(num, root);
}

void tree::deleteNode(int num, treeNode *&nodePtr)
{
   if (num < nodePtr->value)
      deleteNode(num, nodePtr->left);
   else if (num > nodePtr->value)
      deleteNode(num, nodePtr->right);
   else{
	    if(num == nodePtr->value)
		 makeDeletion(nodePtr);
	    else 
		  return;
	}
}

void tree::makeDeletion(treeNode *&nodePtr)
{
   // Define a temporary pointer to use in reattaching
   // the left subtree.
   treeNode *tempNodePtr = nullptr;
   // treeNode *dtlPtr = nullptr;
   if (nodePtr == nullptr)
      cout << "Cannot delete, empty node.\n";
   else if (nodePtr->right == nullptr){
      tempNodePtr = nodePtr;
      nodePtr = nodePtr->left;   // Reattach the left child
      delete tempNodePtr;
   }
   else if (nodePtr->left == nullptr){
      tempNodePtr = nodePtr;
      nodePtr = nodePtr->right;  // Reattach the right child
      delete tempNodePtr;
	 // if()cout<<""<<endl;
   }
   // If the node has two children.
   else{
      // Move one node the right.
      tempNodePtr = nodePtr->right;
      // Go to the end left node.
      while (tempNodePtr->left)
         tempNodePtr = tempNodePtr->left;
      // Reattach the left subtree.
      tempNodePtr->left = nodePtr->left;
      tempNodePtr = nodePtr;
      // Reattach the right subtree.
      nodePtr = nodePtr->right;
      delete tempNodePtr;
   }
}


void tree::nonRecurInOrder(){  
	stack<treeNode*> stack;  
	treeNode* current = root; 
	while (current != nullptr || !stack.empty()){
		if (current){
			stack.push(current);
			current = current->left;
		}
		else{     
		current = stack.top();
		stack.pop();
		cout << current->value<<" ";
		current = current->right;
		}
	}
	return;
}


void tree::displayPreOrder(treeNode *nodePtr) const
{
   if (nodePtr)
   {
      cout << nodePtr->value << " ";
      displayPreOrder(nodePtr->left);     
      displayPreOrder(nodePtr->right);
   }
}

void tree::displayPreOrder() const
{
	displayPreOrder(root);
}

int tree::height(){
  queue<treeNode*> q;
  treeNode* current = root;
  int left =0, right = 0;
  if (current){
	left = 1,right = 1;
	q.push(current); 
    while (!q.empty()){
	  current = q.front();
	  q.pop();
	  q.pop();
      if (current->left){
		q.push(current->left);  
	    left++;
      }
      if (current->right){
	  q.push(current->right);
      right++;
	  }
    }
  }
  else
	  return 0;
  if (left > right)
	  return left;
  else
	  return right;
} 

int tree::minNode()
{
	treeNode* nodePtr = root;
	if(nodePtr){
		while(nodePtr->left)
			nodePtr = nodePtr->left;
		return nodePtr->value;
	}
	else
		return 0;
}

int tree::maxNode()
{
	treeNode* nodePtr = root;
	if(nodePtr){
		while(nodePtr->right)
			nodePtr= nodePtr->right;
		return nodePtr->value;
	}
	else
		return 0;
}