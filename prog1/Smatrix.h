#ifndef _SMATRIX_H
#define _SMATRIX_H

const int Imax = 100;

class Smatrix_item
   {
      friend class Smatrix;
      public:
	     int row,col,value;
   };

class Smatrix
{  
   public:
      Smatrix();
	  Smatrix add(Smatrix num);
      friend ostream& operator<<(ostream& out,Smatrix& M);
      friend istream& operator>>(istream& in,Smatrix& M);
   
   private:   
	  int Icol,Irow,Iterms;
      Smatrix_item Athearray[Imax];
};

#endif