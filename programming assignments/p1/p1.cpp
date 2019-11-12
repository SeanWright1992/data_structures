//Sean Wright
//p1.cpp
//This is the main file to run the stack h and c++ files.

#include <iostream>  
#include <random>
#include "stack.h"
using namespace std;
int main()
{
	//Generate random seed
	random_device rd;
	
	// Initialize Mersenne Twister pseudo-random number generator
	mt19937 gen(rd());
	
	//Generate pseudo-random numbers
	//uniformly distributed in range 1- 100
	 uniform_int_distribution<> dis(1, 100);

	cout<<"This is the driver program for the stack class. The stack class \nis a dynamically allocated stack that only adds prime integers to the stack."<<endl;
	cout<<"The tested functions are push, pop, empty, resize, copy \nconstructor and overload assignment operator."<<endl;
	cout<<"Press enter to begin the program."<<endl;
	string go;
	go = cin.get();
	//Tests basic constructor, builds stack basic
	Stack basic;
	//outputs used to print out what's being popped
	int output1, output2, count = 0;
	
	//Testing loading random numbers to the stack
	//I made it odd so that way there's a higher chance of getting a prime number
	for(int i = 0; i <10; i++)
	{
		int randomX = dis(gen);
		if(randomX % 2 ==0)
			randomX++;
		cout<<"Pushing "<<randomX<<" to the stack."<<endl;
		basic.push(randomX);
	}
	
	//pops numbers from basic until it becomes empty
	while(!basic.isEmpty())
	{
		output1 = basic.pop();
		cout<<"Popped: "<<output1<<endl;
	}
	
	//Now I must test resize function, so we'll set the range of random numbers from 1-10 odd only to increase
	//chances of getting a prime number as the input
	uniform_int_distribution<> odd(1, 10);
	for(int i = 0; i <300; i ++)
	{
		int randomX = odd(gen);
		if(randomX % 2 ==0 && randomX !=2)
			randomX++;
		basic.push(randomX);
	}
	while(!basic.isEmpty())
	{
		basic.pop();
		count ++;
	}
	if(count < 50)
		cout<<"Stack didn't resize for more than 50 ints."<<endl;
	else
		cout<<"Stack popped "<<count<<" prime integers, when it originally had a size of 50."<<endl;
	
	
	//We need to reinitiallize the stack with values, so we'll do the same method as above
	for(int i = 0; i <30; i ++)
	{
		int randomX = odd(gen);
		if(randomX % 2 ==0 && randomX !=2)
			randomX++;
		basic.push(randomX);
	}
	
	//Creating a copy of the basic stack
	cout<<"Testing the copy constructor."<<endl;
	Stack copy_basic(basic);
	
	//This while loop will print out if the values being popped are different, which would mean
	//that the copy constructor didn't work correctly.
	bool copyCat = true;
	while(!copy_basic.isEmpty())
	{
		output1 = basic.pop();
		output2 = copy_basic.pop();
		cout<<output1<<"	"<<output2<<endl;
		if(output1 != output2)
		{
			cout<<"The values didn't all copy over."<<endl;
			copyCat = false;
		}
		else
			continue;
	}
	if(copyCat)
		cout<<"Succesfully copied the original stack."<<endl;
	else
		cout<<"Unsuccesfully copied the original stack."<<endl;
	
	
	cout<<endl<<"Testing the overload constructor."<<endl<<endl;
	
	for(int i = 0; i < 6; i++)
	{
		int randomX = odd(gen);
		if(randomX % 2 ==0 && randomX != 2)
			randomX++;
		basic.push(randomX);
		cout<<"Pushing "<<randomX<<" to the stack."<<endl;
	}
	
	//Finally testing the overload assignment operator
	int size = 10;
	bool over_Load = true;
	Stack overload_basic(size);
	
	for(int i = 0; i < 10; i++)
	{
		int randomX = odd(gen);
		if(randomX % 2 ==0 && randomX != 2)
			randomX++;
		overload_basic.push(randomX);
		cout<<"Pushing "<<randomX<<" to overload stack."<<endl;
	}
	cout<<"Comparing contents of overload stack to original stack after using the overload assignment function."<<endl;
	basic = overload_basic;
	while(!overload_basic.isEmpty())
	{
		
		output1 = basic.pop();
		output2 = overload_basic.pop();
		cout<<output1<<"	"<<output2<<endl;
		if(output1 != output2)
		{
			cout<<"The values didn't all copy over."<<endl;
			over_Load = false;
		}
		else
			continue;
	}
	if(over_Load)
		cout<<"Sucessfully overloaded the first stack."<<endl;
	else
		cout<<"Couldn't overload the first stack."<<endl;
	//test to make sure emptystack exception is thrown
	cout<<"Testing that the empty exception is thrown when an empty stack is popped."<<endl;
	basic.pop();
	return 0;
}