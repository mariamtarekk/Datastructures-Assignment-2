#include <iostream>
using namespace std ;

/* Binary tree Node */
class Node
{
public:
    int data ;
    Node *left ;
    Node *right ;
};

// utility function new Node of BST
Node *CreatNode(int data)
{
    Node * new_Node = new Node ;
    new_Node->left = NULL ;
    new_Node->right = NULL ;
    new_Node->data = data ;
    return new_Node ;
}

// A utility function to insert a new Node
//  with given key in BST and also maintain lcount ,Sum
Node * InsertNode(Node *root, int key)
{
    // If the tree is empty, return a new Node
    if (root == NULL)
        return CreatNode(key) ;

    // Tree isn't empty.
    //insert at LHS.
    if (root->data > key)
        root->left = InsertNode(root->left, key) ;
        //Insert at RHS.
    else if (root->data < key)
        root->right =InsertNode(root->right, key) ;

    // return the (unchanged) Node pointer
    return root ;
}

// function return sum of all element smaller than and equal to Kth smallest element
int CalculateSum(Node *root, int k, int &count)
{
    // Base cases(Tree is empty and all elements are greater than k)
    if (root == NULL)
        return 0 ;
    if (count > k)
        return 0 ;

    // Compute sum of elements in left subtree
    int result = CalculateSum(root->left, k, count) ;
    if (count >= k)
        return result ;

    // Add root's data
    result += root->data ;

    // Add current Node
    count++ ;
    if (count >= k)
        return result ;
    // If count is less than k, return right subtree Nodes
    return result + CalculateSum(root->right, k, count) ;
}

// Wrapper over kSmallestElementSum()
int ksmallestElementSum(Node *root, int k)
{
    int count = 0 ;
    CalculateSum(root, k, count) ;
}

int main()
{
    /*    54
        /    \
       51     75
      / \    /  \
    49   52  74  85

          */
    Node *root = NULL;
    root = InsertNode(root , 54) ;
    root = InsertNode(root , 51) ;
    root = InsertNode(root , 49) ;
    root = InsertNode(root , 52) ;
    root = InsertNode(root , 75) ;
    root = InsertNode(root , 85) ;
    root = InsertNode(root , 74) ;

    int k = 3 ;
    cout <<  ksmallestElementSum(root, k) <<endl ;


    /*    12
       /    \
      10     39
     / \    /  \
   40   42  4  11

         */

    Node *root1 = NULL;
    root1 = InsertNode(root1 , 12) ;
    root1 = InsertNode(root1 , 10) ;
    root1= InsertNode(root1 , 40) ;
    root1 = InsertNode(root1 , 42) ;
    root1 = InsertNode(root1 , 39) ;
    root1 = InsertNode(root1 , 11) ;
    root1 = InsertNode(root1 , 4) ;
    int k1 = 4 ;
    cout <<  ksmallestElementSum(root1, k1) <<endl ;

    /*  20
      /    \
     8     22
    /   \  /  \
    4   12 10  14
        */

    Node *root2 = NULL;
    root2 = InsertNode(root2, 20) ;
    root2 = InsertNode(root2, 8) ;
    root2 = InsertNode(root2, 4) ;
    root2 = InsertNode(root2, 12) ;
    root2 = InsertNode(root2, 22) ;
    root2 = InsertNode(root2, 14) ;
    root2 = InsertNode(root2, 10) ;

    int k2 = 3 ;
    cout <<  ksmallestElementSum(root2, k2) << endl ;

    /*
         1
        /  \
       2    3
      /      \
     4        5

    */

    Node *root3 = NULL;
    root3 = InsertNode(root3, 1) ;
    root3 = InsertNode(root3, 2) ;
    root3 = InsertNode(root3, 4) ;
    root3 = InsertNode(root3, 3) ;
    root3 = InsertNode(root3, 5) ;

    int k3 = 3 ;
    cout <<  ksmallestElementSum(root3, k3) << endl ;




    /*
    1
   / \
  4   2
  \   /
   5 3

   */

    Node *root4 = NULL;
    root4 = InsertNode(root4, 1) ;
    root4 = InsertNode(root4, 4) ;
    root4 = InsertNode(root4, 5) ;
    root4 = InsertNode(root4, 2) ;
    root4 = InsertNode(root4, 3) ;

    int k4 = 2 ;
    cout <<  ksmallestElementSum(root3, k4) << endl ;

    return 0 ;

}