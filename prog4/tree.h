#ifndef TREE_H
#define TREE_H


class Tree; //forward declaration

class TreeNode
{
   friend class Tree;
   public:
      TreeNode *LeftChild;
      char data;
      TreeNode *RightChild;
};


class Tree
{
   public:
      Tree() {root = 0; Num_of_Nodes = 0;};
      void inorder();
      void inorder(TreeNode*);
      void preorder();
      void preorder(TreeNode*);
      void postorder();
      void postorder(TreeNode*);
      void print_tree(TreeNode*, int);
      void print_tree();
      void AddNode(TreeNode*,char,char);
      void buildTree(char[], char[]);
      void maketree(TreeNode*,char[],char[],char);
      

   private:
      TreeNode *root;
       int Num_of_Nodes;
};
#endif
