#ifndef _Gen_Stack_
#define _Gen_Stack_
#include <exception>
#include <cstdlib>
#include <stdexcept>

template <class T> class GenStack
{
	public:
		GenStack();
		GenStack(int maxSize);
		~GenStack();
		void Push(T data);
		T Pop();
		T Peek(); 
		int IsFull();
		int IsEmpty();
		int GetMax();

	private:
		int top;
		int max;
		T *stackArray;

};

#include "GenStack.hxx"

#endif 