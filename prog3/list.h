#ifndef LIST_H
#define LIST_H
#include <stdlib.h>
#include <iostream.h>
#include <string.h>

enum Boolean {FALSE, TRUE};

template <class Type> class List;
template <class Type> class ListIterator;

template <class Type> class ListNode 
{
	friend class List <Type>; friend class ListIterator <Type>;
	public:
		ListNode(Type val){
			data = val;
			link = 0;
		}
	private:
		Type data;
		ListNode *link;
};

template <class Type> class List 
{
	friend class ListIterator <Type>;
	friend class longint;
 public:
		List() {first = 0;};
		void Attach(Type item);
  void Clear();
	private:
		ListNode <Type> *first;
};
#endif