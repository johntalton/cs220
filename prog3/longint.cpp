#include "longint.h"

void printLongInt(ListIterator<longintnode> &Aiter)
{
   
   longintnode *val = Aiter.Next();

   if (Aiter.NotNull() && Aiter.NextNotNull())
   {      
         printLongInt(Aiter);
   }
   
   if(Aiter.NotNull())
   {   
      int num = val->value;      
      char ch1[5]; // holds the integer value in string form
      int y=1000;
   
      for(int dummy = 0; dummy < 4; dummy++)
      {
         ch1[dummy]=char(((num / y) % 10)+'0');
         y =y / 10;
      }
      ch1[4] = '\0'; 
      cout << ch1;
   }
   //return;


}

istream& operator >>(istream& is, longint &l){
	char *tmp = new char[MAXLEN], slice[5];
	int i,j,val;
	longintnode nd;              

	is>>tmp;
	i = strlen(tmp)-1;
	slice[4] = 0;
	while(i>3){
		for(j=3; j>=0; j--) // get a slice of data
			slice[j] = tmp[i--];
		val = atoi(slice); // convert string to int
		nd.Init(val); l.lngint.Attach(nd); // attach to the list
	}
	// get the last slice of data
	slice[i+1] = 0;
	for(j=i; j>=0; j--){ // get a slice of data
		slice[j] = tmp[i--];
	}
	val = atoi(slice); // convert string to int
	nd.Init(val); l.lngint.Attach(nd); // attach to the list
	return is;
}

ostream& operator <<(ostream& os, const longint &l)
{
   ListIterator<longintnode> Lit(l.lngint);
   

   printLongInt(Lit);
    
   longintnode *val = Lit.First();
   int num = val->value;      
   char ch1[5]; // holds the integer value in string form
   int y=1000;
   
   for(int dummy = 0; dummy < 4; dummy++)
   {
      ch1[dummy]=char(((num / y) % 10)+'0');
      y =y / 10;
   }
   ch1[4] = '\0'; 
   cout << ch1;

   //return;
     
   
   
   return os;


}

longint operator*(const longint& A, const longint& B)
{
   ListIterator <longintnode>Aiter(A.lngint);
   ListIterator <longintnode>Biter(B.lngint);

   longint Result_one;
   longint Result_two;

   int offset = 0;

   longintnode *pA = Aiter.First();
   longintnode *pB = Biter.First();
   longintnode temp;
   int carry = 0;
   int tempint;

   temp.Init(0000);
   Result_one.lngint.Attach(temp);         
   
   while(Biter.NotNull())
   {
      for(int mom = 0; mom < offset; mom++)
      {
         temp.Init(0000);
         Result_two.lngint.Attach(temp);         
      }
      while(Aiter.NotNull())
      {
         tempint = ((pA->value * pB->value) + carry);
         carry = tempint / 10000;
         temp.Init(tempint % 10000);
         Result_two.lngint.Attach(temp);
         pA = Aiter.Next();
      }
      temp.Init(carry);
      Result_two.lngint.Attach(temp);
      Result_one = Result_one + Result_two;
      
      Result_two.lngint.Clear();
      
      pA = Aiter.First();
      offset++;
      pB = Biter.Next();
   }
   return Result_one;
}




longint operator+(const longint& A, const longint& B) 
{
	int carry = 0, partial_sum;
	longintnode *a_ptr, *b_ptr, temp;
	ListIterator<longintnode>Aiter(A.lngint);
	ListIterator<longintnode>Biter(B.lngint);
	longint result;


	a_ptr=Aiter.First(); b_ptr=Biter.First();
	
	while(Aiter.NotNull() && Biter.NotNull()) { // both integers have more terms
		partial_sum = a_ptr->value + b_ptr->value + carry;
		if(partial_sum > maxslice) 
		{
			carry = 1;
			partial_sum -= maxslice; 
		}
		else carry = 0;
		temp.Init(partial_sum); result.lngint.Attach(temp);
		a_ptr = Aiter.Next();
		b_ptr = Biter.Next();
	} // both not null
 	
	while(Aiter.NotNull()){
 		temp.Init(a_ptr->value+carry); result.lngint.Attach(temp);
		a_ptr = Aiter.Next();
		carry = 0;
 	} // copy from A
	while(Biter.NotNull()){
 		temp.Init(b_ptr->value+carry); result.lngint.Attach(temp);
		b_ptr = Biter.Next();
		carry = 0;
 	}	// copy from B
	if(carry){
		temp.Init(1); result.lngint.Attach(temp);
	}
 	return result;
} // overloaded + operator
   

