#include <stdlib.h>
#include <iostream.h>
#include <string.h>


#include "list.cpp"
#include "LIterator.cpp"
#include "longint.cpp"

///////////////////////////////
// John Talton               //
// cs220 and all             //
// date - well a little late //
// aahhhaahhhh aahhhhhh      //
///////////////////////////////

void main(int argc, char *argv[ ], char *envp[ ]) 
{
	char c=0;
	do{
		longint A,B,C,D;
		cout<<"input long int A:\n";
		cin>>A;
  cout<<"input long int B:\n";
		cin>>B;
		C = A+B;
		cout<<"A+B= "<<C<<"\n";
  D = A*B;
  
		cout<<"A*B= "<<D<<"\n";
  
  cout<<"Do you want to try again? Enter 'y' to continue, other character to quit\n";
		cin>>c;
	}while(c=='y' || c=='Y');
}

