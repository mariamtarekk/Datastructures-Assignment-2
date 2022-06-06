20201089_20200338_20200828_20200591_20200522#include <iostream>
using namespace std ;
//class node that has to pointers(pointer for left child and other pointer to right child)and the data in the node.
class Node{
public:
    int data ;
    Node *Left = nullptr ;
    Node *Right = nullptr ;
};
// mirror image function to convert the tree to its mirror image.
void MirrorImage(Node *node){
    if(node == NULL)
        return;
    else{
        Node *swap ;
        //Creat SubTrees
        MirrorImage(node-> Left);
        MirrorImage(node->Right);
        //Swap pointers
        swap = node->Left ;
        node->Left = node->Right ;
        node->Right = swap ;
    }
}
//Bool AreEqual function that return True if the Structure of the two trees is the same
bool AreEqual(Node *i , Node *j){
    if(i == NULL && j == NULL)
        return true ;
    if(i != NULL && j != NULL && AreEqual(i->Left , j->Left) && AreEqual(i->Right , j->Right))
        return true ;
    //if both conditions are false
    return false ;
}
/*Bool Foldable function that return true if the left subtree and right subtree are mirror images of
each other*/
bool isFoldable(Node *root){
    bool result ;
    //if Tree is empty then it considered Foldable.
    if(root == NULL)
        return true ;
    //convert left subtree to its image
    MirrorImage(root->Left);
    //compare left subtree with right subtree
    result = AreEqual(root->Left , root->Right);
    //Original left subtree back
    MirrorImage(root->Left);
    return result ;
}
//Allocate new node
Node *NewNode(int value){
    Node *newNode = new Node();
    newNode->data = value ;
    newNode->Left = NULL ;
    newNode->Right = NULL ;
    return newNode ;
}
int main(){
    /*
      1
     / \
    4   2
    \    /
     5  3

     */
    Node *Root = NewNode(1);
    Root->Left = NewNode(4) ;
    Root->Right = NewNode(2) ;
    Root->Left->Right = NewNode(5) ;
    Root->Right->Left = NewNode(3) ;
    if(isFoldable(Root) == true)
        cout << "Congratulations!, This Tree Is Foldable" << endl;
    else
        cout << "Unfortunately, This Tree Is not Foldable" << endl;

    /*
          1
         /  \
        2    3
       /      \
      4        5

     */
    Node *Root1 = NewNode(1) ;
    Root1->Left = NewNode(2) ;
    Root1->Right = NewNode(3) ;
    Root1->Left->Left = NewNode(4) ;
    Root1->Right->Right = NewNode(5) ;
    if(isFoldable(Root1) == true)
        cout << "Congratulations!, This Tree Is Foldable" << endl;
    else
        cout << "Unfortunately!!, This Tree Is not Foldable" << endl;


    /*
          1
         /  \
        2    3
       / \     \
      4   6     5

     */

    Node *Root2 = NewNode(1) ;
    Root2->Left = NewNode(2) ;
    Root2->Right = NewNode(3) ;
    Root2->Left->Left = NewNode(4) ;
    Root2->Left->Right = NewNode(6) ;
    Root2->Right->Right = NewNode(5) ;
    if(isFoldable(Root2) == true)
        cout << "Congratulations!, This Tree Is Foldable" << endl;
    else
        cout << "Unfortunately!!, This Tree Is not Foldable" << endl;


    /*
          1
         /  \
        2    3
       /    / \
      4     5  6

     */



    Node *Root3 = NewNode(1) ;
    Root3->Left = NewNode(2) ;
    Root3->Right = NewNode(3) ;
    Root3->Left->Left = NewNode(4) ;
    Root3->Right->Right = NewNode(6) ;
    Root3->Right->Left = NewNode(5) ;
    if(isFoldable(Root3) == true)
        cout << "Congratulations!, This Tree Is Foldable" << endl;
    else
        cout << "Unfortunately!!, This Tree Is not Foldable" << endl;


    Node *Root4 = NewNode(-1);
    if(isFoldable(Root4) == true)
        cout << "Congratulations!, This Tree Is Foldable" << endl;
    else
        cout << "Unfortunately!!, This Tree Is not Foldable" << endl;

    return 0 ;
}