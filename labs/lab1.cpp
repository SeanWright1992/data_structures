//Sean Wright
//Lab1.cpp
//This lab is a way to warmup to using putty, c++ and good test of skills
//Input: Asks user for input integers that are odd, once it collects 13 then it'll reprint the values in 
//order, 
//Output: max value in array, contents of array with indexes
//Sample: enter odd numbers between 10 and 100 13 times: 3 3 3 3 3 3 3 3 3 3 3 3 5
//1.3	2.3	3.3	4.3	...11.3	12.3	13.5
//max value entered: 5

#include <iostream>

using namespace std;
     
	 

int Getmax(int [], int);
int buildArray(int [], int);
	 
int main()
{
	int sizeArray =13, maxvalue;
	int Array[13];
	cout<<"This is lab 1, an exercise to practice basic c++ coding \nbasics. Please enter odd numbers between 10 and 100 13 times,\n at which point the program will end and it'll perform some \nfunctions. Please press enter after each number."<<endl;
	buildArray(Array, sizeArray);
	maxvalue = Getmax(Array, sizeArray);
	cout<<"The maximum value entered was "<<maxvalue<<".";
	cout<<endl<<"This is the end of lab1 program. Goodbye"<<endl;
	return 0;
}

int buildArray(int arr[], int sizeArray)
{
	int count = 0, x;
	while (count < sizeArray)
	{
		cin>>x;
		while(( x % 2 == 0) || (x < 10) || (x > 100))
		{
			cout<<"Please follow instructions. Enter an odd number between 10 and 100"<<endl;
			cin>>x;
		}
		arr[count] = x;
		count++;
	}
	cout<<"You've entered: "<<endl;
	for(int i = 0; i <sizeArray; i++)
		cout<<i + 1<<": "<<arr[i]<<endl;
	return 0;
}

int Getmax(int ar[], int size)
{
	int maxvalue = ar[0];
	for(int i = 0; i < size; i++)
	{
		if(ar[i] > maxvalue)
			maxvalue = ar[i];
	}
	return maxvalue; 
}