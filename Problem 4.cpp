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
    bool isSymmetric(TreeNode*root,TreeNode*root2 )
    {
        if (root== NULL &&root2 == NULL)
            return true ;
        else if (root ==NULL ||root2 == NULL)
            return false;
        else if (root->val == root2 ->val)
        {
            return( isSymmetric(root -> left,root2 ->right)&&isSymmetric(root -> right,root2 ->left));
        }
    }
};

int main()

{
    Solution s1 ;
    TreeNode*root = new TreeNode(1);
    root ->left = new TreeNode(2);
    root ->right = new TreeNode(2);
    root ->left ->left = new TreeNode(3);
    root ->left->right = new TreeNode(4);
    root -> right -> right = new TreeNode(4);
    root -> right -> left = new TreeNode(3);
    if(s1.isSymmetric(root,root)){
        cout << "true \n" ;}
    else
        cout <<"false \n";
//////////////////////////////////////
    Solution s2 ;
    TreeNode*root2 = new TreeNode(1);
    root2 ->left = new TreeNode(2);
    root2 ->right = new TreeNode(2);
    root2 ->left->right = new TreeNode(3);
    root2 -> right -> right = new TreeNode(3);
    if(s2.isSymmetric(root2,root2))
        cout << "true \n" ;
    else
        cout <<"false \n";

////////////////////////////////////////////
    Solution s3;
    TreeNode*root3 = new TreeNode(1);
    root3 ->left = new TreeNode(2);
    root3 ->right = new TreeNode(3);
    root3 ->left ->left = new TreeNode(4);
    root3 -> right -> right = new TreeNode(4);
    if (s3.isSymmetric(root3,root3))
        cout << "true \n" ;
    else
        cout <<"false \n";
////////////////////////////////////////////////////
    Solution s4 ;
    TreeNode*root4 = new TreeNode(1);
    root4 ->left = new TreeNode(2);
    root4 ->right = new TreeNode(2);
    root4 ->left ->left = new TreeNode(3);
    root4 -> right -> right = new TreeNode(3);
    if(s4.isSymmetric(root4,root4))
        cout << "true \n" ;
    else
        cout <<"false \n";
//////////////////////////////////////////////////////
    Solution s5;
    TreeNode*root5 = new TreeNode(1);
    root5 ->left = new TreeNode(2);
    root5 ->right = new TreeNode(2);
    root4 ->left ->right = new TreeNode(3);
    root4 -> right -> left = new TreeNode(3);
    if(s5.isSymmetric(root5,root5))
        cout<<"True\n";
    else
        cout<<"False\n";
}