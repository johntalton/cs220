#include <iostream.h>
#include "Smatrix.h"
 
Smatrix::Smatrix() { Iterms = 0; }

Smatrix Smatrix::add(Smatrix M)
{
   Smatrix Sresult;
   int Ipointone = 0;
   int Ipointtwo = 0;
   if ((Icol == M.Icol) && (Irow == M.Irow))
   {
      Sresult.Icol = Icol;
      Sresult.Irow = Irow;
      while ((Ipointone != Iterms) || (Ipointtwo != M.Iterms))
      {
         if (Athearray[Ipointone].row == M.Athearray[Ipointtwo].row)
         {
            if (Athearray[Ipointone].col == M.Athearray[Ipointtwo].col)
            {
               if ((Athearray[Ipointone].value + M.Athearray[Ipointtwo].value) != 0)
               {
                  Sresult.Athearray[Sresult.Iterms].row = Athearray[Ipointone].row; 
                  Sresult.Athearray[Sresult.Iterms].col = Athearray[Ipointone].col; 
                  Sresult.Athearray[Sresult.Iterms].value = Athearray[Ipointone].value + M.Athearray[Ipointtwo].value; 
                  Sresult.Iterms++;	
               }
               Ipointone++;
               Ipointtwo++;
            }
            else
            {
               if (Athearray[Ipointone].col > M.Athearray[Ipointtwo].col)
               {
                  Sresult.Athearray[Sresult.Iterms].row = M.Athearray[Ipointtwo].row; 
                  Sresult.Athearray[Sresult.Iterms].col = M.Athearray[Ipointtwo].col; 
                  Sresult.Athearray[Sresult.Iterms].value = M.Athearray[Ipointtwo].value;
                  Sresult.Iterms++;
                  Ipointtwo++;
               }
               else
               {
                  Sresult.Athearray[Sresult.Iterms].row = Athearray[Ipointone].row; 
                  Sresult.Athearray[Sresult.Iterms].col = Athearray[Ipointone].col; 
                  Sresult.Athearray[Sresult.Iterms].value = Athearray[Ipointone].value;
                  Sresult.Iterms++;
                  Ipointone++;
               }
            }
         }
         else
         {
            if (Athearray[Ipointone].row > M.Athearray[Ipointtwo].row)
            {
               Sresult.Athearray[Sresult.Iterms].row = M.Athearray[Ipointtwo].row; 
               Sresult.Athearray[Sresult.Iterms].col = M.Athearray[Ipointtwo].col; 
               Sresult.Athearray[Sresult.Iterms].value = M.Athearray[Ipointtwo].value;
               Sresult.Iterms++;
               Ipointtwo++;
            }
            else
            {
               Sresult.Athearray[Sresult.Iterms].row = Athearray[Ipointone].row; 
               Sresult.Athearray[Sresult.Iterms].col = Athearray[Ipointone].col; 
               Sresult.Athearray[Sresult.Iterms].value = Athearray[Ipointone].value;
               Sresult.Iterms++;
               Ipointone++;
            }
         }
      }
      for(;Ipointone <= Iterms;Ipointone++)
      {
         Sresult.Athearray[Sresult.Iterms].row = Athearray[Ipointone].row; 
         Sresult.Athearray[Sresult.Iterms].col = Athearray[Ipointone].col; 
         Sresult.Athearray[Sresult.Iterms].value = Athearray[Ipointone].value;
         Sresult.Iterms++;
      }
      for(;Ipointtwo <= M.Iterms;Ipointtwo++)
      {
         Sresult.Athearray[Sresult.Iterms].row = M.Athearray[Ipointtwo].row; 
         Sresult.Athearray[Sresult.Iterms].col = M.Athearray[Ipointtwo].col; 
         Sresult.Athearray[Sresult.Iterms].value = M.Athearray[Ipointtwo].value;
         Sresult.Iterms++;
      }
   }									 
   else
   {
      cerr << "Ahhhhh. . The two Matrices are not the same size.\n" << endl;
      return Sresult;
   }
   return Sresult;
}

ostream& operator<<(ostream& out,Smatrix& M)
{
   if((M.Irow <= 20) && (M.Icol <= 10))
   {
      int Icounter = 0;

      for(int r = 0;r < M.Irow; r++)
      {
         for(int c = 0; c < M.Icol; c++)
         {
            if((M.Athearray[Icounter].row == r) && (M.Athearray[Icounter].col == c))
            {
               out << M.Athearray[Icounter].value << ' ';
               Icounter++;
            }
            else 
            {
               out << 0 << ' ';
            }
         }
         out << '\n';
      }
      out << '\n';
   }
   else
   {
      for(int x=0;x < M.Iterms; x++)
      {
         out << M.Athearray[x].row << ' ';
         out << M.Athearray[x].col << ' ';
         out << M.Athearray[x].value << '\n';
      }
   }
   return out;
}

istream& operator>>(istream& in,Smatrix& M)
{
   int Iitem = 1;
   int Inumber_of_terms = 0;
   
   in >> M.Irow;
   in >> M.Icol;

   while (Iitem >= 0)
   {
      in >> M.Athearray[Inumber_of_terms].row;	
      if (M.Athearray[Inumber_of_terms].row < 0) {M.Iterms = Inumber_of_terms;return in;}
      in >> M.Athearray[Inumber_of_terms].col;
      if (M.Athearray[Inumber_of_terms].col < 0) {M.Iterms = Inumber_of_terms;return in;}	       
      in >> M.Athearray[Inumber_of_terms].value;
      Inumber_of_terms++;
   }
   M.Iterms = Inumber_of_terms;
   return in;	
}

void pause()
{    
   char ch[2]; //dummy variable

   cout << "Press enter to go on. . ." << flush;
   cin.ignore (10000, '\n');       
   cin.getline (ch, 2, '\n');  // and wait for the user to press enter  
} 

void main()
{
   int choice = -1;
   Smatrix Mone;
   Smatrix Mtwo;
   Smatrix temp;

   cout << "" << endl;
   while (choice != 4)
   {
      cout << "1.......Enter Matrix A\n" 
           << "2.......Enter Matrix B\n" 
           << "3..........Print A + B\n" 
           << "4.................Exit\n\n"
           << "Choice:  " << flush;
      cin >> choice;
      switch (choice)
      {
         case 1:
            cout << "Enter the size of the Matrix, Barry. ex: 3 3 is an 3x3 matrix\n\n"
                 << "Then enter the matrix - row number then col\n"
                 << "number then the value then a -1 to end.\n"
                 << "ex: 3 7 4 -1 (3,7 is the position and 4\n"
                 << "is the value.\n\n>";
            cin >> Mone;
            break;
         case 2:
            cout << "Enter the size of the Matrix, Barry. ex: 3 3 is an 3x3 matrix\n\n"
                 << "Then enter the matrix - row number then col\n"
                 << "number then the value then a -1 to end.\n"
                 << "ex: 3 7 4 -1 (3,7 is the position and 4\n"
                 << "is the value.\n\n>";   
            cin >> Mtwo;
            break;
         case 3:
            cout << Mone.add(Mtwo);
            pause();
            break;
         case 4:
            cout << "The end." << endl;
            break;
         default:
            cout << "\nOps, *this was not a valid choice or the code is wrong some place\n" 
                 << "And seeing that *this is by YNOP the chances are the code is wrong." << endl;
            break;
      } // switch
   } // while 
} // main

