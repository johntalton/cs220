#include "LIterator.h"

template <class Type> 
Boolean ListIterator<Type>::NotNull() 
{
	if (current) return TRUE;
	else return FALSE;
}

template <class Type> 
Boolean ListIterator<Type>::NextNotNull() 
{
	if (current && current->link) return TRUE;
	else return FALSE;
}

template <class Type> 
Type* ListIterator<Type>::First() 
{
	current = list.first;
 if (list.first) return &list.first->data;
	else return 0;
} 


template <class Type> 
Type* ListIterator<Type>::Next() 
{
	if (current) 
	{
		current = current->link;
		return &current->data;
	}
	else return 0;
}


