#include "tree.cpp"
#include <iostream.h>




void main()
{
   char a1[8] = "BLKURTZ";
   char a2[8] = "LKBRUTZ";
   Tree thetree;
   thetree.buildTree(a1,a2);
   thetree.print_tree();

}


