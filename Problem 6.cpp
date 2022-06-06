#include <iostream>
#include<cctype>
#include<string>
using namespace std;

class Node{
public:
    string expression ;
    Node* left;
    Node* right;
    Node(){
        left = nullptr ;
        right = nullptr ;
    }
    Node(string ex){
        expression = ex ;
        left = nullptr ;
        right = nullptr ;
    }
};

void preOrder(Node* root){
    if(root == NULL){
        return ;
    }
    cout<< root->expression ;
    preOrder(root->left);
    preOrder(root->right);
}
int evaluateTree(Node* treenode){
    if(treenode == NULL){
        return 0;
    }
    if(treenode->left==NULL && treenode->right==NULL ){
        return stoi(treenode->expression) ;
    }
    int leftValue = evaluateTree(treenode->left);
    int rightValue = evaluateTree(treenode->right);
    string operation = treenode->expression ;
    if (operation =="+")
        return leftValue+rightValue ;
    else if (operation =="-")
        return leftValue-rightValue ;
    else if (operation =="*")
        return leftValue*rightValue ;
    else if (operation =="/")
        return leftValue/rightValue ;
}




int main(){
    //Test case 1
    Node* tree = new Node("+") ;
    tree->left = new Node ("3") ;
    tree->right = new Node ("*") ;
    tree->right->left = new Node ("4") ;
    tree->right->right = new Node ("/") ;
    tree->right->right->left = new Node ("8") ;
    tree->right->right->right = new Node ("2") ;
    cout << "The PreOrder of the tree is : " ;
    preOrder(tree);
    cout<< endl << "test case 1: expression aftre evaluated  = "<< evaluateTree(tree) <<endl << endl; // expression = 19

    //Test case 2
    Node* tree1;
    tree1 = new Node("+") ;
    tree1->left = new Node ("9") ;
    tree1->right = new Node ("/") ;
    tree1->right->left = new Node ("144") ;
    tree1->right->right = new Node ("*") ;
    tree1->right->right->left = new Node ("3") ;
    tree1->right->right->right = new Node ("4") ;
    cout << "The PreOrder of the tree is : " ;
    preOrder(tree1);
    cout<< endl  << "test case 2 : expression aftre evaluated = "<< evaluateTree(tree1) << endl << endl; // expression = 21

    //Test case 3
    Node* tree2 ;
    tree2 = new Node("+");
    tree2->left = new Node("-");
    tree2->left->right = new Node("2");
    tree2->left->left = new Node("/");
    tree2->left->left->left = new Node("9");
    tree2->left->left->right = new Node("3");
    tree2->right = new Node ("*");
    tree2->right->left = new Node("5");
    tree2->right->right = new Node("9");
    cout << "The PreOrder of the tree is : " ;
    preOrder(tree2);
    cout<< endl  << "Test case 3 : expression aftre evaluated = " << evaluateTree(tree2) << endl << endl;

    //Test case 4
    Node*tree3;
    tree3 = new Node("*");
    tree3 -> left = new Node("*");
    tree3 -> left-> left = new Node("2");
    tree3 -> left -> right = new Node("4");
    tree3->right = new Node("5");
    cout << "The PreOrder of the tree is : " ;
    preOrder(tree3);
    cout << endl << "Test case 4 : expression aftre evaluated = " << evaluateTree(tree3) << endl << endl;

    //Test case 5
    Node* tree4 ;
    tree4 = new Node("/");
    tree4 ->left = new Node("8");
    tree4->right = new Node("*");
    tree4->right -> left = new Node("2");
    tree4 ->right -> right = new Node ("2");
    cout << "The PreOrder of the tree is : " ;
    preOrder(tree4);
    cout << endl << "Test case 5 : expression aftre evaluated = " << evaluateTree(tree4) << endl << endl;
}