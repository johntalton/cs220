#include "list.h"
template <class Type>
void List<Type>::Attach(Type item) 
{
	ListNode<Type> *newnode = new ListNode<Type>(item), *last;
	if (first==0) first = newnode;
	else 
	{ 
		last = first;
		while(last->link) last=last->link;
		last->link = newnode;
	}                                                                                                                            }

template <class Type>                                           

void List<Type>::Clear()
{
   first = 0;

}