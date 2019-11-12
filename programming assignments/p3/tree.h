//sean wright
//tree.h
//implementation file for tree class

#ifndef TREE_H
#define TREE_H	
using namespace std;
class tree
{
  private:
    struct treeNode
	{
	  int value;
	  treeNode *left; 
	  treeNode *right;
	};
	treeNode *root; 
	
	//Private member functions:
	
	//preconditions:insert function called it with an already
	//established tree object and a new value(node) to add.
	
	//postconditions: This will add the new node to it's proper place
	//in the BST(lower value = left, higher value = right).
    void insert(treeNode *&nodePtr, treeNode *&newNode);
	
	//Destroys entire BST.
	
	//preconditions: Tree object has been initalized.
	
	//postconditions: Destroys entire BST, cleaning up memory.
    void destroyAll(treeNode *&nodePtr);
	
	//Selects a specific node, calls itself recursively.
	
	//preconditions:Tree object created.
	//(not necessarilly a number in the BST).
	
	//postconditions: Calls makeDeletion to delete a specific node in the BST. 
    void deleteNode(int num, treeNode *&nodePtr);
	
	//Deletes a specific node in the BST.
	
	//preconditions: tree object initalized.
	
	//postconditions: Deletes a specific node in the BST and depending on the 
	//number of children will reorganize the placements of other nodes.
    void makeDeletion(treeNode *&nodePtr);
	
	//Displays the BST in root left right fashion
	
	//preconditions: Tree object made.
	
	//postconditions: Recursively prints out the value of the node its on. 
    void displayPreOrder(treeNode *nodePtr) const;
	
	//Function to make deep copies opf tree objects
	
	//preconditions: Tree object created when called

	//postconditions: Will create a deep copy of the original BST into the new
	//tree object. 
	treeNode* makeCopy(treeNode* r);
	
	
  public:
  
	//constructor
	
	//preconditions: none
	
	//postconditions: Initialize a tree class object
    tree();
	
	//destructor
	
	//preconditions: There's been a tree class object created
	
	//postconditions: The object(s) will be deleted
	~tree();
	
	//copy constructor
	
	//preconditions: The parameter being passed in exists
	//ie; already have some tree object initalized before using 
	//the copy constructor
	
	//postconditions: Creates a tree class object that is a 
	//deep copy of the tree object passed in
	tree(const tree &atree);
	
	//overload assignment operator
	
	//preconditions: The tree class object needs to have been
	//declared, and the tree object passed in also must've been
	//declared before using the overload assignment operator
	
	//postconditions: It overloads the entirety of the original
	//object with the object being passed in(in a way).So it destroys the
	//first object completely then fills it with the passed in object.
	tree& operator=(const tree& rhs);
	
	//Insert a node to the tree.
	
	//preconditions: There needs to have been a tree object initalized
	//to use this funtion.
	
	//postconditions: This will add a new node to the tree object.
	void insertNode(int num);
	
	//Removes a node from the tree.
	
	//preconditions: There needs to have been a tree object created.
	
	//postconditions: Removes the node thats value matches num.
	//if it's part of the BST.
	void remove(int num);
	
	//Returns height of longest point in tree.
	
	//preconditions: As with all the member functions, we need a tree object.
	
	//postconditions: It'll return an int with the height (up to down)
	//of the tallest chain in th BST. If it's empty it'll return 0. 
	int height();
	
	//Returns min value in tree.
	
	//preconditions: Tree object initalized.
	
	//postconditions: Return the smallest numbered node in the BST, so
	//if it doesn't have any values in it. 
	int minNode();
	
	//Returns max value in tree
	
	//preconditions: The tree object needs to have been created.
	
	//postconditions: Returns the largest value found in the BST.
	int maxNode();
	
	//Searches the BST for a specific value
	
	//preconditions: The tree object has been created.
	
	//postconditions: This function will return true if it's found the 
	//node with the passed in value, false otherwise. 
	bool searchNode(int num);
	
	//Displays tree in order
	//preconditions: Tree object has been created.
	
	//postconditions: Will create a stack that's used to load up the trees
	//values and print them to the screen in ascending fashion.
    void nonRecurInOrder();
	
	//displays tree in preorder
	
	//preconditions: The tree object has been initalized.
	
	//postconditions: Calls the recursive displayPreOrder function to
	//print out the BST in root|left|right fashion. 
    void displayPreOrder() const;
};
#endif