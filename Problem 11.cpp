#include<bits/stdc++.h>
using namespace std;
int max_fun(int a, int b){return (a >= b) ? a:b;}
template <class T>
class BSTNode{
public:
    BSTNode *lchild;
    T data;
    BSTNode *rchild;
    BSTNode(){
        rchild = NULL;
        lchild = NULL;
    }
    BSTNode(T item,BSTNode *right=0,BSTNode *left=0){
        data = item;
        rchild = right;
        lchild = left;
    }
    T getdata(){return data;}
    BSTNode* getright(){return rchild;}
    BSTNode* getleft(){return lchild;}

};
template <class T>
class BTSFCI{
public:
    BSTNode<T> *root;
    BTSFCI(){root = NULL;}
    BSTNode<T>* create_Node(T DATA, BSTNode<T>* ptr) {
        if (ptr == NULL)
        {
            ptr = new BSTNode<T>;
            ptr->data = DATA;
            ptr->lchild = ptr->rchild = NULL;
        }

        else if (DATA > ptr->data)
            ptr->rchild = create_Node(DATA, ptr->rchild);

        else if (DATA < ptr->data)
            ptr->lchild = create_Node(DATA, ptr->lchild);

        return ptr;
    }
    void Insert(T val){
        root = create_Node(val,root);
    }
    void preorder(BSTNode<T>*ptr){
        if (ptr !=NULL)
        {
            cout<<ptr->data<<" ";
            preorder(ptr->lchild);
            preorder(ptr->rchild);
        }

    }
    void printPreOrder(){
        preorder(root);
    }
    void inorder(BSTNode<T>*ptr){
        if (ptr !=NULL)
        {
            inorder(ptr->lchild);
            cout<<ptr->data<<" ";
            inorder(ptr->rchild);
        }

    }
    void PrintInOrder(){
        inorder(root);
    }
    void postorder(BSTNode<T>*ptr){
        if (ptr !=NULL)
        {
            postorder(ptr->lchild);
            postorder(ptr->rchild);
            cout<<ptr->data<<" ";

        }

    }
    void PrintPostOrder(){
        postorder(root);
    }
    void PrintInRange( BSTNode<T> *root,int k1, int k2){
        if ( NULL == root )
            return;
        if ( k1 < root->data )
        {
            PrintInRange(root->lchild, k1, k2);
        }
        if ( k1 <= root->data && k2 >= root->data )
            cout<<root->data<<" ";
        if (k2 > root->data)
            PrintInRange(root->rchild,k1,k2);
    }
    bool flag;
    int checker(BSTNode<T>*ptr){
        if(!ptr)
            return 0;
        int l = 1 + checker(ptr->lchild);
        int r = 1 + checker(ptr->rchild);
        if(abs(l - r) > 1)
            flag = false;
        return max_fun(l, r);
    }
    bool isBalanced(BSTNode<T>* root) {
        flag = true;
        checker(root);
        return flag;
    }
};
template <class T2>
bool check(BSTNode<T2> *ptr,BSTNode<T2> *nptr){
    if (ptr == NULL && nptr==NULL)
    {
        return true;
    }
    if (ptr != NULL && nptr!=NULL)
    {
        if ((ptr->data == nptr->data)&&
            check(ptr->lchild,nptr->lchild )&&
            check(ptr->rchild,nptr->rchild )){
            return true;
        }

    }
    return false;
}
template <class T2>
bool SubTree(BSTNode<T2> *t1,BSTNode<T2> *t2){
    if (t2== NULL)
    {
        return true;
    }
    if (t1 == NULL)
    {
        return false;
    }
    if (check(t1,t2))
    {
        return true;
    }

    return SubTree(t1->lchild,t2) ||
           SubTree(t1->rchild,t2);
}
template <class T2>
bool IsSubTree(BTSFCI<T2> m,BTSFCI<T2> n){
    if (SubTree(m.root,n.root))
    {
        cout<<"The Tree 2 is a SubTree of Tree 1\n";
    }
    else{
        cout<<"The Tree 2 is not a SubTree of Tree 1\n";

    }
    cout<<endl;

}

int main(){
//     tree1:5,3,7,2,4,9,1,8,10||tree2: 9,8,10||trees3: 3,2,4,1
//     tree4:1,2,3,4,5,6,7||tree5:2,4,5
    cout<<"My Five Trees:\n"<<"____________\n"<<endl;
    BTSFCI<int> tree1,tree2,tree3,tree4,tree5;
    tree1.Insert(5);
    tree1.Insert(3);
    tree1.Insert(7);
    tree1.Insert(2);
    tree1.Insert(4);
    tree1.Insert(9);
    tree1.Insert(1);
    tree1.Insert(8);
    tree1.Insert(10);
    cout<<"PreOrder travel of tree 1:[ "  ;
    tree1.printPreOrder();
    cout<<" ]\n\n";

    tree2.Insert(9);
    tree2.Insert(8);
    tree2.Insert(10);
    cout<<"PreOrder travel tree 2:[ "  ;
    tree2.printPreOrder();
    cout<<" ]\n\n";

    tree3.Insert(3);
    tree3.Insert(2);
    tree3.Insert(4);
    tree3.Insert(1);
    cout<<"PreOrder travel tree 3:[ "  ;
    tree3.printPreOrder();
    cout<<" ]\n\n";

    tree4.Insert(54);
    tree4.Insert(51);
    tree4.Insert(75);
    tree4.Insert(49);
    tree4.Insert(52);
    tree4.Insert(74);
    tree4.Insert(85);
    cout<<"PreOrder travel tree 4:[ "  ;
    tree4.printPreOrder();
    cout<<" ]\n\n";

    tree5.Insert(75);
    tree5.Insert(74);
    tree5.Insert(85);
    cout<<"PreOrder travel tree 5:[ "  ;
    tree5.printPreOrder();
    cout<<" ]\n"<<"_______________________________________________________________________________\n\n";


    cout<<"Test Function Print in range:\n"<<"_________________________\n"<<endl;
    for (int i = 0; i < 5; i++){ //printrangefinish
        int k1,k2;
        k1 = i+7;
        k2 = i +12;
        cout<<"your range "<<i+1<<" is: ["<<k1<<","<<k2<<" ]: ";
        cout<<"--> [ ";
        tree1.PrintInRange(tree1.root,k1,k2);
        cout<<" ].\n"<<endl;
    }
    cout<<"_______________________________________________________________________________\n\n";

    cout<<"Test Function Tree is balance:\n"<<"_________________________"<<endl;
    for (int i = 1; i <=5; i++) // is balance function finshed
    {
        if (i == 1)
        {
            if(tree1.isBalanced(tree1.root)){
                cout<<endl<<"Tree 1 Is Balance "<<endl;
            }
            else
                cout<<endl<<"Tree 1 Is Not Balance "<<endl;
        }
        if (i == 2)
        {
            if(tree2.isBalanced(tree2.root)){
                cout<<endl<<"Tree 2 Is Balance "<<endl;
            }
            else
                cout<<endl<<"Tree 2 Is Not Balance "<<endl;
        }if (i == 3)
        {
            if(tree3.isBalanced(tree3.root)){
                cout<<endl<<"Tree 3 Is Balance "<<endl;
            }
            else
                cout<<endl<<"Tree 3 Is Not Balance "<<endl;
        }if (i == 4)
        {
            if(tree4.isBalanced(tree4.root)){
                cout<<endl<<"Tree 4 Is Balance "<<endl;
            }
            else
                cout<<endl<<"Tree 4 Is Not Balance "<<endl;
        }if (i == 5)
        {
            if(tree5.isBalanced(tree5.root)){
                cout<<endl<<"Tree 5 Is Balance "<<endl;
            }
            else
                cout<<endl<<"Tree 5 Is Not Balance "<<endl;
        }

    }
    cout<<"_______________________________________________________________________________\n\n";

    cout<<"Test Function is subtree:\n"<<"_________________________"<<endl;
    for (int i = 1; i <=5; i++)
    {
        if (i == 1)
        {
            IsSubTree(tree1,tree2);
        }
        if (i == 2)
        {
            IsSubTree(tree1,tree3);
        }
        if (i == 3)
        {
            IsSubTree(tree4,tree2);
        }
        if (i == 4)
        {
            IsSubTree(tree4,tree5);
        }
        if (i == 5)
        {
            IsSubTree(tree3,tree2);
        }


    }

    return 0;
}