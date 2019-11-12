//lab 5 cpp file
//sean wright
//


#include <iostream>
#include <random>
#include <fstream>
#include<sstream>
#include<ctype.h>
#include<stdio.h>
 
using namespace std;
const int maxValue = 3142;

struct Node{
  string place;
  int censusCount;
};
 
//Merges the broken up arrays togethor
void Merge(Node *a, int low, int high, int mid); 
// Splits into tiny pieces
void MergeSort(Node *a, int low, int high);
 
int main()
{
	
  ifstream inFile;
  inFile.open("countyPop.dat");
  Node list[maxValue];
  int count = 0;
  while (inFile >> list[count].censusCount){
	getline(inFile, list[count].place);
	count++;
  }
  cout<<"First 10 entries: \n";
  for(int i  = 0 ; i <10; i++){
	cout<<"Population: "<<list[i].censusCount<<" Location: "<<list[i].place<<endl;
  }
  cout<<"Last 10 entries: \n";
  for(int j = maxValue-1; j >maxValue-11;j--)
	cout<<"Population: "<<list[j].censusCount<<" Location: "<<list[j].place<<endl;
  MergeSort(list, 0, maxValue-1);
  cout<<"After sorting.\n";
  cout<<"First 10 entries: \n";
  for(int i  = 0 ; i <10; i++)
	cout<<"Population: "<<list[i].censusCount<<" Location: "<<list[i].place<<endl;
  cout<<"Last 10 entries, starting from largest to smallest: \n";
  for(int j = maxValue-1; j >maxValue-11;j--)
	cout<<"Population: "<<list[j].censusCount<<" Location: "<<list[j].place<<endl;
  
  return 0;
}


void Merge(Node *a, int low, int high, int mid)
{
  int i, j, k;
  Node* temp = new Node[high-low+1];
  i = low;
  k = 0;
  j = mid + 1;

  while (i <= mid && j <= high){
	if (a[i].censusCount < a[j].censusCount){
	  temp[k].censusCount = a[i].censusCount;
	  temp[k].place = a[i].place;
	  k++;
	  i++;
	}
	else{
	  temp[k].censusCount = a[j].censusCount;
	  temp[k].place = a[j].place;
	  k++;
	  j++;
	}
  }

  while (i <= mid){
	temp[k].censusCount = a[i].censusCount;
	temp[k].place = a[i].place;
	k++;
	i++;
  }

  while (j <= high){
	temp[k].censusCount = a[j].censusCount;
	temp[k].place = a[j].place;
	k++;
	j++;
  }


  for (i = low; i <= high; i++){
	a[i].censusCount = temp[i-low].censusCount;
	a[i].place = temp[i-low].place;
	
  }
}

void MergeSort(Node *a, int low, int high)
{
  int mid;
  if (low < high){
	mid=(low+high)/2;
	MergeSort(a, low, mid);
	MergeSort(a, mid+1, high);
	Merge(a, low, high, mid);
  }
}
