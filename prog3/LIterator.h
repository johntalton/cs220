#ifndef LITERATOR_H
#define LITERATOR_H
#include "list.h"
#include "longint.h"
template <class Type> 
class ListIterator 
{
	public:
		ListIterator(const List <Type>& l):list(l),current(l.first){ };
		Boolean NotNull();
		Boolean NextNotNull();
		Type *First();
		Type *Next();
	private:
		const List<Type>& list;
		ListNode <Type>* current;			
};
#endif