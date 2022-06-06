#include <iostream>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
        right(right) {}
};
class Solution
{
public:
    void  mirrortree(TreeNode*root)
    {
        if ( root==NULL)
        {
            return ;
        }
        TreeNode* temp ;
        temp = root->left ;
        root->left= root->right;
        root->right = temp ;
        mirrortree(root->left);
        mirrortree(root->right);
    }
    void print (TreeNode*root)
    {
        if ( root==NULL)
        {
            return ;
        }
        cout <<root->val<< "  " ;
        print( root-> left);
        print (root -> right) ;

    }
};
int main()
{
    Solution s ;
    TreeNode*root = new TreeNode(1);
    root ->left = new TreeNode(2);
    root ->right = new TreeNode(3);
    root ->left ->left = new TreeNode(4);
    root ->left->right = new TreeNode(5);
    cout<<"Tree before mirroring: ";
    s.print(root);
    cout<<endl;
    cout<<"Tree after mirroring: ";
    s.mirrortree(root);
    s.print(root);
    cout <<endl ;
///////////////////////////////////////////////////////////////////////////
    Solution s1;
    TreeNode*root1 = new TreeNode(3);
    root1 ->left = new TreeNode(4);
    root1 ->right = new TreeNode(5);
    root1->right->right =new TreeNode(2);
    root1 -> right -> left = new TreeNode (1);
    cout<<"Tree before mirroring: ";
    s.print(root1);
    cout<<endl;
    cout<<"Tree after mirroring: ";
    s.mirrortree(root1);
    s.print(root1);
    cout <<endl;

/////////////////////////////////////////////////////////////////////
Solution s2;
 TreeNode*root2 = new TreeNode(5);
    root2 ->left = new TreeNode(7);
    root2 ->right = new TreeNode(3);
    root2->left->right =new TreeNode(2);
    root2 -> left -> left = new TreeNode (4);
    cout<<"Tree before mirroring: ";
    s.print(root2);
    cout<<endl;
    cout<<"Tree after mirroring: ";
    s.mirrortree(root2);
    s.print(root2);
    cout << endl ;
///////////////////////////////////////////////////////////////////////////////////////////////
Solution s3;
 TreeNode*root3 = new TreeNode(6);
    root3 ->left = new TreeNode(5);
    root3 ->right = new TreeNode(2);
    root3->left->right =new TreeNode(4);
    root3 -> left -> left = new TreeNode (3);
    cout<<"Tree before mirroring: ";
    s.print(root3);
    cout<<endl;
    cout<<"Tree after mirroring: ";
    s.mirrortree(root3);
    s.print(root3);
    cout << endl;
/////////////////////////////////////////////////////////////////////////////////
Solution s4;
 TreeNode*root4 = new TreeNode(6);
    root4 ->left = new TreeNode(5);
    root4 ->right = new TreeNode(4);
    root4->right->right =new TreeNode(2);
    root4 -> right -> left = new TreeNode (3);
    cout<<"Tree before mirroring: ";
    s.print(root4);
    cout<<endl;
    cout<<"Tree after mirroring: ";
    s.mirrortree(root4);
    s.print(root4);
    cout <<endl ;


}