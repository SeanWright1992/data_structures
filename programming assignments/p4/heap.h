//heap.h
//sean wright
//header file for heap class

#ifndef HEAP_H
#define HEAP_H	
using namespace std;
class heap
{
	private:
		struct Node
		{
			int priority;
			int old_priority;
		};
		int currentSize;
		int maxSize;
		int*HeapArr;
		void percolateUp(int hole);
		void percolateDown(int hole);
		void resizeArr();
		bool isEmpty();
		
	public: 
		void insert(int a);
		void changePriority(int &oldPriority, int &newPriority);
		void deleteMin(int b);
		heap();
		~tree();
		heap(const heap &aheap);
		heap& operator=(const heap& rhs);	
};
#endif