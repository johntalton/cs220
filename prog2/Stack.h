#ifndef _Stack_H
#define _Stack_H

template <class KeyType>
class Stack
{
   public:
      Stack(int MaxStacksize = 100);
      void push(const KeyType& item);
      int isfull();
      
      KeyType* pop(KeyType &x);
       int isempty();

   private:
      void error(int flag); 
    
      int top;
      KeyType* stack;
      int MaxSize;      
      
};

#endif

