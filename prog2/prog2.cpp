#include <iostream.h>                                             
#include "Stack.h"
#include <string.h>

int error = 0;

template <class KeyType>                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     
Stack<KeyType>::Stack(int MaxStackSize):MaxSize(MaxStackSize)
{
   stack = new KeyType[MaxSize];
   top = -1;
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     

template <class KeyType>
void Stack<KeyType>::push(const KeyType& item)
{
   if(isfull()) error(1);
   else stack[++top] = item;
}


template <class KeyType>
KeyType* Stack<KeyType>::pop(KeyType &x)
{
   if(isempty()) { error(2); return 0; }
   x = stack[top--];
   return &x;
}

template <class KeyType>
inline int Stack<KeyType>::isfull()
{
   if(top==MaxSize-1) return 1;
   else return 0;
}

template <class KeyType>
inline int Stack<KeyType>::isempty()
{
   if(top==-1) return 1;
   else return 0;
}


template <class KeyType>
void Stack<KeyType>::error(int flag)
{
   switch(flag)
   {
      case 1:cerr << "The Stack is Really full man, sorry bout that.\n"; break;
      case 2:cerr << "Uhh, Something is wrong here, oh I see - there is nothing in the stack.\n"; break;
   }   
}





void Getinfix(char eg[])
{
  cout << "Enter the cool little infix equation so I \ncan destroy it, I mean put it in postfix.\n(Enter # it end input line)(Press Enter to end prgram)\n\n:";
  //cin.ignore(80,'\n');
  cin.getline (eg, 20, '\n');
}

int isoperand(char i)
{
   if((i >= '0') && (i <= '9'))
      return 1;
   else
      return 0;
}

int isp(char hi_mom)
{
   switch(hi_mom)
   {
      case '(':return 0;
      case '*':
      case '/':
      case '%':return 2;
      case '+': 
      case '-':return 1;
   }
   return -37;
}


int icp(char hi_son)
{
    switch(hi_son)
   {
      case '(':return 3;
      case '*':
      case '/':
      case '%':return 2;
      case '+': 
      case '-':return 1;
   }
   return -37;
}

void ConvertToPost(char i[],char poster[])
{
   Stack<char> mystack(10);
   char tempchar,tempchar2,trash;
   int x = 0;
   int a = 0;

   if (i[strlen(i)-1] == '#')
   {
      while(i[x] != '#')
      {
         if (isoperand(i[x]))
         {
            poster[a++] = i[x];
         } 
         else if(i[x] == ')')
         {
            //unstack until '(' 
            do
            {                
               mystack.pop(tempchar);
               mystack.push(tempchar);
               if(tempchar != '(') 
               {     
                  if (isoperand(poster[a - 1]))
                     poster[a++] = ' ';
                  mystack.pop(poster[a++]);
                  
               }
               else mystack.pop(trash);
            } while(tempchar != '(');
         }
         else 
         {
           
            if ((i[x] != '(') && (poster[a-1] != ' ') && (isoperand(poster[a-1]))) poster[a++] = ' ';   
            if(!mystack.isempty())
            {
               mystack.pop(tempchar);
               mystack.push(tempchar);
            }
            else tempchar = ' ';
            while((icp(i[x]) < isp(tempchar)) && (!mystack.isempty()))
            {
               mystack.pop(tempchar2); 
               poster[a++] = tempchar2;                   
               if(!mystack.isempty())
               {
                  mystack.pop(tempchar);
                  mystack.push(tempchar);
               }
               else tempchar = ' ';
            }
            mystack.push(i[x]);   
            
         }
         x++;
      }
      while(!mystack.isempty())
      {
         if (isoperand(poster[a - 1]))
            poster[a++] = ' ';
         mystack.pop(poster[a++]);      
      }
   }
   else 
   {
       cerr << "\nYou forgot you # sign stupid\n\n";
       error = 1;
   }
   poster[a++] = '#';
   if (isoperand (poster[a-2]))
   {
      poster [a - 1] = ' ';
      poster [a++] = '#';
   }   
   poster[a++] = '\0';
   cout << "\nThe postfix eq is:   ";
   cout << poster;
   cout << '\n';

}

void Evalposteq(char eq[])
{
   Stack<int> operands(10);
   int x = 0;
   int trash,num1,num2,temp;

   cout << "\nUsing the powers of modern technology and some nifty\npostfix equation, the answer is. . .\n\n--- ";
              
   while(eq[x] != '#')
   {
      if(isoperand(eq[x]))
      {
         operands.push(eq[x++] - '0');
         while(eq[x] != ' ')
         {
            operands.pop(trash);
            operands.push(trash * 10 + eq[x++] - '0');
         }
         x++;
      }
      else
      {
         operands.pop(num2);
         operands.pop(num1);
         switch (eq[x])
         {
            case '+':operands.push(num1 + num2);break;
            case '-':operands.push(num1 - num2);break;
            case '*':operands.push(num1 * num2);break;
            case '/':operands.push(num1 / num2);break;
            case '%':operands.push(num1 % num2);break;          
         }
         x++;
      }
   }

 operands.pop(temp);
 cout << temp << "\n" <<endl;
}

void main()
{
   Stack<char> Snum[10];
   char infixeq[20];
   char postfixeq[20];
   int error = 0;

   do
   {
      error = 0;
      Getinfix(infixeq);
      if(!error)
      {
         ConvertToPost(infixeq,postfixeq);
         Evalposteq(postfixeq);
      }      
   } while (infixeq[0] != '\0');

 
}