//p6 file
//sean wright
//This project is our first exposure to using stl operators 

#include <cstdlib>
#include <iostream>
#include <vector>
#include <math.h>
#include <random>


using namespace std;

//This function tests whether the input is a prime number or not
//Preconditions: Parameter being passed in is a number, must
//be above 0 to have an accurate output
//Postconditions: If number passed in and is above 0, then it'll return
//true if the number is prime or false if it's not
bool isPrime(int num);

//This is the display function to print the number vector
//Preconditions: A vector has been created and filled
//Postconditions: Will print out contents of the vector
void display(vector<int> v);

const int N = 1000;

int main(){
  //Generate random seed
  random_device rd;

  // Initialize Mersenne Twister pseudo-random number generator
  mt19937 gen(rd());
  
  //Generate pseudo-random numbers
  //uniformly distributed in range 1- 500
  uniform_int_distribution<> dis(1, 500);
  vector<int> v;
  v.reserve(N);
  vector<int>::iterator i;
  //Generates 1000 random numbers and stores in a vector  
  for(int j=0; j<N; ++j){
	int randomX = dis(gen);
	v.push_back(randomX);
  }
  cout<<"Hello! This program is my first exposure into using STL packages\n";
  cout<<"in C++. STL is a set of C++ template classes to provide pre-built\n";
  cout<<"functionality for common data structures. In this program I use a\n";
  cout<<"container, vector, to hold 1000 integers and cut off specific\n";
  cout<<"integers. I use vector iterator to peruse through the vector.\n";
  cout<<"\nAll "<<N<<" random numbers generated:"<<endl;
  display(v);
  //Removes all numbers divisible by 5
  for(i=v.begin(); i!=v.end(); ++i){
	if((*i) % 5 == 0){
	  v.erase(i);
	  i--;
	}
  }
  cout<<"Random numbers after removing multiples of 5:"<<endl;
  display(v);
  //Removes primes between numbers of different parity
  for(i=v.begin(); i<v.end()-2; ++i){
	int x = *i;
	int y = *(i+1);
	int z = *(i+2);
	if(x%2 != z%2){
	  if(isPrime(y))
	    v.erase(i+1);
	}
	else
		continue;
  }
  cout<<"Random numbers after removing primes between\n";
  cout<<"different parity numbers:"<<endl;
  display(v);
  //Repetedly removes primes between numbers of different parity
  int flag = 1;
  int count =1;
  while(flag == 1){
	count++;
	flag = 0;
	for(i=v.begin(); i<v.end()-2; ++i){
	  int x = *i;
	  int y = *(i+1);
	  int z = *(i+2);
      if(x%2 != z%2){
		if(isPrime(y)){
		  flag = 1;
		  v.erase(i+1);
		}
	  }
	}
	if(flag == 1){
	  cout<<"\nRandom numbers after removing primes between \ndifferent ";
	  if(count ==2)
		cout<<"parity numbers "<<count<<"nd iteration:"<<endl;
	  else if(count == 3)
		cout<<"parity numbers "<<count<<"rd iteration:"<<endl;
	  else
		cout<<"parity numbers "<<count<<"th iteration:"<<endl;
	  display(v);
	}
  }
  cout<<"\nFinal list of Random numbers after removing\n";
  cout<<"primes from different parity numbers:"<<endl;
  display(v);
  return 0;
}

//displays the numbers in the vector
void display(vector<int> v){
  int printCount = 0;
  vector<int>::iterator i;
  for(i=v.begin(); i!=v.end(); ++i){
	if(printCount %10 == 0)
	  cout<<endl;
    else
		cout<<"";
	cout<<(*i)<<" ";
	printCount++;
  }
  cout<<endl;
}

//checks if a number is prime
bool isPrime(int num){
  if(num%2 == 0 && num !=2)
	return false;
  else if(num <= 3)
	return true;
  else{
	for(int i=3; i<=(num/2)+1; i++){
	  if(num%i == 0)
		return false;
	  }
  }
  return true;
}