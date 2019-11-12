//sean wright
//p3.cpp
//driver file for binary search treemain class

#include <iostream>
#include "tree.h"

using namespace std;
 
int main(){
	tree treemain, treeoverload;
	
	int arr[20] = {10,5,2,8,4,4,14,3,9,12,7,6,0,13,18,16,19,20,11,1};
	int size = 0,max = 0, min =0, size1 = 0;
	bool tru;
	for(int i =0; i <20; i++)
		treemain.insertNode(arr[i]);
	
	cout<<"Display preorder: "<<endl;
	treemain.displayPreOrder();
	cout<<endl<<"Display in order: "<<endl;
	treemain.nonRecurInOrder();
	max = treemain.maxNode();  
	min = treemain.minNode();
	size = treemain.height();
	tru = treemain.searchNode(14);
	if(tru)
		cout<<endl<<"Searched for and found 14"<<endl;
	else
		cout<<endl<<"Searched for and didn't find 14."<<endl;
	cout<<"size: "<<size<<"\nmax: "<<max<<"\nmin: "<<min<<endl;
	treemain.remove(14);
	cout<<"Removing 14."<<endl;
	tru = treemain.searchNode(14);
	if(tru)
		cout<<"Searched for and found 14."<<endl;
	else
		cout<<"Searched for and didn't find 14."<<endl;
	cout<<"Display preorder:"<<endl;
	treemain.displayPreOrder();
	cout<<endl<<"Display in order: "<<endl;
	treemain.nonRecurInOrder();
	max = treemain.maxNode();
	min = treemain.minNode();
	size1 = treemain.height();
	cout<<"\nsize: "<<size1<<"\nmax: "<<max<<"\nmin: "<<min<<endl;
	cout<<"Now testing overload assignment operator: "<<endl;
	
	
	treeoverload = treemain;
	cout<<"Display preorder:\n";
	treeoverload.displayPreOrder();
	cout<<endl<<"Display in order:\n";
	treeoverload.nonRecurInOrder();
	max = treeoverload.maxNode();
	min = treeoverload.minNode();
	size1 = treeoverload.height();
	cout<<"\nsize: "<<size1<<"\nmax: "<<max<<"\nmin: "<<min<<endl;
	cout<<"Inserting 14 back into the main BST.\n";
	cout<<"In order traversal(main BST):"<<endl;
	treemain.insertNode(14);
	treemain.nonRecurInOrder();
	cout<<"\n\nNow testing overload BST, in order traversal:"<<endl;
	treeoverload.nonRecurInOrder();
	cout<<endl<<"\n\nNow copying overload BST to copy BST."<<endl;
	cout<<"Copy BST in order traversal:"<<endl;
	
	
	tree treecopy(treeoverload);
	treecopy.nonRecurInOrder();
	cout<<endl<<"Removing 0 - 5 on overload BST."<<endl;
	for(int i = 0; i <6; i++)
		treeoverload.remove(i);
	cout<<"In order traversal of overload BST:"<<endl;
	treeoverload.nonRecurInOrder();
	max = treeoverload.maxNode();
	min = treeoverload.minNode();
	size1 = treeoverload.height();
	cout<<"Overload BST data:"<<endl;
	cout<<"\nsize: "<<size1<<"\nmax: "<<max<<"\nmin: "<<min<<endl;
	tru = treeoverload.searchNode(1);
	if(tru)
		cout<<"Searched for and found 1 in overload BST.\n";
	else
		cout<<"Searched for and didn't find 1 in overload BST.\n";
	cout<<"In order traversal of copy BST(to make sure it's a deep copy).";
	cout<<endl;
	treecopy.nonRecurInOrder();
	cout<<"\nCopy BST data:"<<endl;
	max = treecopy.maxNode();
	min = treecopy.minNode();
	size1 = treecopy.height();
	cout<<"\nOverload BST data:";
	cout<<"\nsize: "<<size1<<"\nmax: "<<max<<"\nmin: "<<min<<endl;
	
	return 0;
} 
