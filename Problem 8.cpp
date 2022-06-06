#include<iostream>
#include<string>
#include<map>
using namespace std;

class Node{
public :
    Node *left;
    Node *right;
    char info;
    Node(){
        left = NULL;
        right = NULL;
    }
    Node(char in, Node* le = NULL ,Node* ri = NULL){
        left = le;
        right= ri;
        info = in;
    }
};

char search(string preOrder, string inOrder){
    int index = 1e9;
    for(int i = 0 ; i < inOrder.size() ; ++i){
        char x = inOrder[i];
        for(int j = 0 ; j < preOrder.size() ; ++j){
            if(preOrder[j] == x){
                index = min(index , j);
                break;
            }
        }
    }
    return preOrder[index];
}


void buildTree(string preOrder , string inOrder  , Node*& root ){
    if(inOrder.size() <= 0){
        root = NULL;
        return;
    }
    char x = search(preOrder , inOrder);
    root->info = x;

    string left = "" , right = "";
    bool check = false;
    for(int i = 0 ; i < inOrder.size() ; ++i ){
        if( x == inOrder[i]){
            check = true;
        }
        else if(check){
            right += inOrder[i];
        }
        else{
            left += inOrder[i];
        }
    }

    root->left = new Node;
    buildTree(preOrder , left , root->left);
    root->right = new Node;
    buildTree(preOrder , right , root->right);

}

void postOrder(Node* root){
    if(root == NULL)return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->info;
}

void printPostOrder(string preOrder, string inOrder){
    Node* root = new Node;
    buildTree(preOrder , inOrder  , root);
    postOrder(root);
}


int main(){
    string inOrder , preOrder;
    /* Test case 1
        preOrder :  ABFGC
        InOrder :   FBGAC
        postOrder : FGBCA
    */
    cout << "Enter the preOrder of the first tree : ";
    cin >> preOrder;
    cout << "Enter the inOrder of the first tree : ";
    cin >> inOrder ;
    cout << "The PostOrder of the tree is : ";
    printPostOrder(preOrder , inOrder);
    cout << endl << endl;


    /* Test case 2
        preOrder :  ACBE
        InOrder :   BCAE
        postOrder : BCEA
    */
    string inOrder1 , preOrder1;
    cout << "Enter the preOrder of the second tree : ";
    cin >> preOrder1;
    cout << "Enter the inOrder of the second tree : ";
    cin >> inOrder1 ;
    cout << "The PostOrder of the tree is : ";
    printPostOrder(preOrder1 , inOrder1);
    cout << endl << endl;


    /* Test case 3
        preOrder :  CFBAG
        InOrder :   BFACG
        postOrder : BAFGC
    */
    string preOrder2 , inOrder2;
    cout << "Enter the preOrder of the third tree : ";
    cin >> preOrder2;
    cout << "Enter the inOrder of the third tree : ";
    cin >> inOrder2 ;
    cout << "The PostOrder of the tree is : ";
    printPostOrder(preOrder2 , inOrder2);
    cout << endl << endl;


    /* Test case 4
        preOrder :  FGBCA
        InOrder :   BGCFA
        postOrder:  BCGAF
    */
    string preOrder3 , inOrder3;
    cout << "Enter the preOrder of the fourth tree : ";
    cin >> preOrder3;
    cout << "Enter the inOrder of the fourth tree : ";
    cin >> inOrder3 ;
    cout << "The PostOrder of the tree is : ";
    printPostOrder(preOrder3 , inOrder3);
    cout << endl << endl;


    /* Test case 5
        preOrder :  ACEGFRB
        InOrder :   ECGARFB
        postOrder:  EGCRBFA
    */
    string preOrder4 , inOrder4;
    cout << "Enter the preOrder of the fifth tree : ";
    cin >> preOrder4;
    cout << "Enter the inOrder of the fifth tree : ";
    cin >> inOrder4 ;
    cout << "The PostOrder of the tree is : ";
    printPostOrder(preOrder4 , inOrder4);
    cout << endl << endl;

}