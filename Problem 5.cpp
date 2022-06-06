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
    bool isSameTree(TreeNode* p, TreeNode* q)
    {
        if(p == NULL && q == NULL)
        {
            return true;
        }
        else if (p== NULL || q == NULL )
        {
            return false;
        }
        else if(p->val == q->val)
            return (isSameTree(p->left,q->left)&&isSameTree(p->right,q->right));
        return false ;
    }

};
int main()
{
    Solution s1 ;
    TreeNode*rootP = new TreeNode(1);
    rootP ->left = new TreeNode(2);
    rootP-> right = new TreeNode(3);
    TreeNode*rootq = new TreeNode(1);
    rootq ->left = new TreeNode(2) ;
    rootq ->right = new TreeNode(3);
    if (s1.isSameTree(rootP,rootq))
        cout<<"true \n";
    else
        cout <<"false \n";
/////////////////////////////////////////////////////////////
    Solution s2 ;
    TreeNode*rootP1 = new TreeNode(1);
    rootP1 ->left = new TreeNode(2);
    TreeNode*rootq1 = new TreeNode(1);
    rootq1 ->left = new TreeNode(NULL) ;
    rootq1 ->right = new TreeNode(2);
    if (s2.isSameTree(rootP1,rootq1))
        cout<<"true \n";
    else
        cout <<"false \n";
////////////////////////////////////////////////////////
    Solution s3 ;
    TreeNode*rootP2 = new TreeNode(1);
    rootP2 ->left = new TreeNode(2);
    rootP2-> right = new TreeNode(1);
    TreeNode*rootq2 = new TreeNode(1);
    rootq2 ->left = new TreeNode(1) ;
    rootq2->right = new TreeNode(2);
    if (s3.isSameTree(rootP2,rootq2))
        cout<<"true \n";
    else
        cout <<"false \n";
/////////////////////////////////////////////////////
    Solution s4 ;
    TreeNode*rootP3 = new TreeNode(1);
    rootP3 ->left = new TreeNode(2);
    rootP3-> right = new TreeNode(5);
    TreeNode*rootq3 = new TreeNode(1);
    rootq3 ->left = new TreeNode(2) ;
    rootq3 ->right = new TreeNode(5);
    if (s4.isSameTree(rootP3,rootq3))
        cout<<"true \n";
    else
        cout <<"false \n";
//////////////////////////////////////////////////////////////////////
    Solution s5 ;
    TreeNode*rootP4 = new TreeNode(1);
    rootP4 ->left = new TreeNode(2);
    rootP4-> right = new TreeNode(5);
    TreeNode*rootq4 = new TreeNode(1);
    rootq4 ->left = new TreeNode(5) ;
    rootq4 ->right = new TreeNode(2);
    if (s5.isSameTree(rootP4,rootq4))
        cout<<"true \n";
    else
        cout <<"false \n";



}