#include "tree.h"
#include <iostream.h>

void Tree::inorder()
{
     inorder(root);
}

void Tree::inorder(TreeNode *CurrentNode)
{
     if (CurrentNode)
     {
          inorder(CurrentNode->LeftChild);
          cout << CurrentNode->data;
          inorder(CurrentNode->RightChild);
     }
}

void Tree::preorder()
{
     preorder(root);
}

void Tree::preorder(TreeNode *CurrentNode)
{
     if (CurrentNode)
     {
          cout << CurrentNode->data;
          preorder(CurrentNode->LeftChild);
          preorder(CurrentNode->RightChild);
     }
}

void Tree::postorder()
{
     postorder(root);
}

void Tree::postorder(TreeNode *CurrentNode)
{
     if (CurrentNode)
     {
          postorder(CurrentNode->LeftChild);
          postorder(CurrentNode->RightChild);
          cout << CurrentNode->data;
     }

}

void Tree::print_tree()
{
     print_tree(root, 1);
}

void Tree::print_tree(TreeNode *CurrentNode, int level)
{
     if (CurrentNode)
     {
          print_tree(CurrentNode->RightChild, level + 1);
          for (int x = 1; x < level; x++)
          {
               cout << "   ";
          } // for
          cout << CurrentNode->data << endl;
          print_tree (CurrentNode->LeftChild, level + 1);
     } // if

} // print_tree


void Tree::AddNode(TreeNode *where,char data,char dir)
{
   Num_of_Nodes++;
   if (dir == 'L') { where->LeftChild->data = data; } // left node
   else if (dir == 'R') { where->RightChild->data = data; } //right node
   else if (dir == 'X') { where->data = data; } //root
}

void Tree::buildTree(char s1[], char s2[])
{
   maketree(root,s1,s2,'X');
}

void substring(char Thestring[],int which,char dir,char subS[])
{
   if(dir == 'L')
   {
      for(int i = 0; i < which;i++)
      {
         subS[i] = Thestring[i];
      }
   }
   else if(dir == 'R')
   {
      for(int i = which; i < 8;i++)
      {
         subS[i] = Thestring[i];
      }
   }
}

void Tree::maketree(TreeNode *thenode, char s1[], char s2[],char dir)
{
   // go over to first char (number of node already in tree
   char left[10];
   char right[10];

   if(Num_of_Nodes != 6)
   {
      substring(s1,Num_of_Nodes,'L',left);
      substring(s1,Num_of_Nodes,'R',right);   
      AddNode(thenode,s1[Num_of_Nodes],dir);
      // get sub string
      maketree(thenode->LeftChild,s1,left,'L');
      maketree(thenode->RightChild,s1,right,'R');
   }
}





