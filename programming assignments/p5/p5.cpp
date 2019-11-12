//p5.cpp
//sean wright
//program 5 main file
//Used base idea of hash function from class
//Original creator: Susan Reeder
//11/28/2018

#include<iostream>
#include<sstream>
#include<ctype.h>
#include<fstream>
#include<stdio.h>
using namespace std;

const int min_length = 4;
const int maxValue = 2423;

struct HNode{
	string word;
	int count;
	HNode* next;
};

//Used to filter out words that don't have at least 5 characters
//along with cutting off punctuation
//Preconditions: Passing in a string as parameter
//Postconditions: Will return the string without extrenuous punctuation
string preProcess(string word);

//I decided to have the store function do the heavy lifting 
//It keeps track of collisions for a new node as well as
//adding a new node if need be, and incrementing the count of words
//Preconditions: The node pointer array has been created with a max size
//Postconditions: Will either add a new node and return collisions,
//or it will increment the count of the word being passed in
int store(int key,  HNode* hTable[],  string real_word);

//Used to check how many times a word has appeared in the txt file
//Preconditions: You can enter any string you want, but it'll prompt you
//to re-enter if the word you enter is less than 5 characters
//The node array must've been initiallized
//Postconditions: Will return either the number of times the word
//has appeared or it'll output a message saying it's not in the document
int checkCount(string word, HNode* linkedList);

//Used to hash the strings, which means go from a word to a single number
//Preconditions: The size of the map has been initiallized, passing in a word
//Postconditions: Will return a key to where the string will be stored on map
int hashFunction(string real_word, int tableSize);

//Used to delete list nodes
//Preconditions: The array of node pointers has been created
//Postconditions: The array and it's linked lists will be deleted
bool deleteList(HNode* hTable[]);

int main(){
	HNode *list[maxValue];
	ifstream inFile;
	string inWord, resultWord, searchWord;
	//Initallize list to nullptr 
	for(int i = 0; i <maxValue; i++)
		list[i] = nullptr;
	//I added the txt file to my directory
	inFile.open("41.txt"); 
	int key =0,totalCollisions =0, wordCount =0, newWords =0, totalWords = 0;
	char go;
	bool keepSearching = true;
	float loadFactor =0;
	HNode* tmp;
	HNode* listNode;
	cout<<"This is programming assignment 5, about hash tables. This \n";
	cout<<"program reads in the book, The Legend of Sleepy Hollow and "<<endl;
	cout<<"hashes all the words that have more than 4 characters. For \n";
	cout<<"collision resolution I'm using linked lists. All the stored \n";
	cout<<"words are stripped of unneccesary punctuation and are lowercase.\n";
	while(inFile>>inWord){
		totalWords++;
		resultWord = preProcess(inWord);
		if(resultWord.length() >min_length){
			key = hashFunction(resultWord, maxValue);
			totalCollisions += store(key,list,resultWord);
		}	
		else
			continue;
	}
	
	
	//Traverse the array, then down each array index
	//Find unqiue words by counting total nodes
	for(int i = 0; i <maxValue; i++){
		tmp = list[i];
		if(tmp != nullptr)
			newWords++;
		else 
			continue;
		listNode = tmp->next;
		if(listNode == nullptr)
			continue;
		else{
			while(listNode != nullptr){
				newWords++;
				listNode = listNode->next;			
			}
		}
	}
	loadFactor = (maxValue *1.0) / (newWords*1.0);
	cout<<"\nLoad factor: "<<loadFactor<<"\n";
	cout<<"Total collisions: "<<totalCollisions<<"\n";
	cout<<"Total unique words: "<<newWords<<"\n";
	cout<<"Total words: "<<totalWords<<"\n";
	cout<<"Table size: "<<maxValue<<"\n";
	while(keepSearching){
		cout<<"Enter a word to see how many times it's in the file:"<<endl;
		cin>>searchWord;
		if(searchWord.length() <= min_length){
			while(searchWord.length() <= min_length){
				cout<<"The length must be above 4 characters. Enter again:\n";
				cin>>searchWord;
			}
		}
		for(unsigned int i = 0; i<searchWord.length(); i++){
			searchWord.at(i) = tolower(searchWord.at(i));
		}
		key = hashFunction(searchWord, maxValue);
		wordCount = checkCount(searchWord, list[key]);
		cout<<"The number of times "<<searchWord<<" was found is "<<wordCount;
		cout<<".\nPress y to continue searching with another word."<<endl;
		cin>>go;
		if(go == 'y')
			keepSearching = true;
		else
			keepSearching = false;
	}
	keepSearching = deleteList(list);
	if(keepSearching)
		cout<<"All nodes have been deleted. Thank you.\n";
	else
		cout<<"Couldn't succesfully delete the list.\n";
	return 0;
}


int store(int key,  HNode* hTable[],  string real_word){

	HNode* tmp = hTable[key];
	int tmpCollisions = 0;
	//List is empty at key location
	if(tmp == nullptr){
		HNode* newNode = new HNode;
		newNode->word = real_word;
		newNode->count = 1; 
		newNode->next = nullptr;
		hTable[key] = newNode;
		return 0;
	}
	else{
		//Word is the head of the linked list
		if(tmp->word ==real_word){
			tmp->count++;
			return 0;
		}
		//Word isn't the head of the linked list
		else{
			tmpCollisions = 1;
			HNode* nextTmp = tmp->next;
			//Word is the second node on the linked list
			if(nextTmp == nullptr){
				//Add new node 
				HNode* newNode = new HNode;
				newNode->word = real_word;
				newNode->count = 1;
				newNode->next = nullptr;
				tmp->next = newNode;
				return 1;
			}
			else{
				//Look at next node's next, so that way you know if it's
				//at the bottom of the linked list
				while(nextTmp->next != nullptr){
					//Real word is found in the linked list
					if(nextTmp->word == real_word){
						nextTmp->count++;
						return 0;
						 
					}
					//Continue traversing linked list
					else{
						nextTmp = nextTmp->next;
						tmpCollisions++;
					}
				}
				//Reached bottom node, word wasn't found so add a new node
				HNode* newNode = new HNode;
				newNode->word = real_word;
				newNode->count = 1;
				newNode->next = nullptr;
				nextTmp->next = newNode;
				return 1;
			}
		}
	}
}

int  checkCount(string real_word, HNode* linkedList){
	
	HNode* tmp = linkedList;
	HNode* nextNode = tmp->next; 
	//Checks head of linked list, returns if it's empty
	if(tmp == nullptr){
		cout<<"This word isn't in the document."<<endl;
		return 0;
	}
	else if(tmp->word == real_word)
		return tmp->count;
	else{
		if(nextNode == nullptr){
			cout<<"This word isn't in the document."<<endl;
			return 0;
		}
			while(nextNode != nullptr){
				if(nextNode->word == real_word)
					return nextNode->count;
				else
					nextNode = nextNode->next;
				//Move down list until found 
			}
		cout<<"Word not in document.\n";
		return 0;	
	}
	return 0;
}
//Based on hashing function provided in class with major tweaks
int hashFunction(string word, int tableSize){
	int index = 5381;//1327;
	//Loop parses word into characters, then multiplies by a set prime number
	for(unsigned int i = 0;  i<word.length(); i++)
		index +=word[i]+31;
	index +=word[2]*23;
	//I added some extra if statements to reduce total collisions
	if(word.length() > 5)
		index +=word[5];
	if(word.length() == 5)
		index +=word[3]*13;
	if(word[2] > 13)
		index= index - 137;
	else
		index += 57;
	//In case index is a negative number, I add tableSize to make it positive
	int value = index % tableSize;
	if (value < 0)
		value = value + tableSize;
	return value;
}

string preProcess(string word){
	string temp;
	unsigned pos = 0;
	bool num = false;
	if(word.length() < min_length)
		return temp;
	while(word.length() > min_length && ispunct(word.at(pos))){
		word.erase(pos,1);
	}
	if(word.length() > min_length){
		pos = word.length() - 1;
		while(pos >=0 && ispunct(word.at(pos))){
			word.erase(pos,1);
			pos--;
		}
	}
	if(word.length()>min_length){
		for(unsigned i =0; i <word.length(); i++){
			if(isdigit(word.at(i)))
				num = true;
		}
		if(num)
			return temp;
	}
	if(word.length() > min_length){
		for(unsigned i = 0; i<word.length(); i++){
			word.at(i) = tolower(word.at(i));
		}
		return word;	
	}
	else
		return temp;
}
bool deleteList(HNode* hTable[]){
	HNode* tmp;
	HNode* deletePtr;
	//check head of linked list, if it's nullptr then no delete necessary
	for(int i = 0; i <maxValue; i++){
		tmp = hTable[i];
		if(tmp == nullptr)
			continue;
		else{
			while(tmp != nullptr){
				deletePtr = tmp;
				tmp = tmp->next;
				delete deletePtr;  
			}
		}
	}
	return true;
}
