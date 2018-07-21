/*
    Name: Path Sum III(LeetCode 437) 
    Copyright: 
    Author: Homosapiens
    Date: 21/07/18 10:52
    Description: 求一颗二叉树内，所有和为num的路径数，不一定包含当前节点(根节点) 
    讨论当前节点值是否在路径上 
*/
#include <iostream>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};
class Solution{
    public: 
        int pathSum(TreeNode* root ,int num){
            if(root==NULL)
                return 0;
            //包含两种不包含当前节点的情况,在左右子树中寻找 
            return findPath(root,num)+pathSum(root->left,num)+pathSum(root->right,num);     
        }
    private:
        //路径包含当前节点 
        int findPath(TreeNode* node,int num){
            if(node==NULL)
                return 0;
            int res=0;
            //该节点的值为num(递归终止条件)
            if(node->val==num)
                res+=1;
            //寻找包含该节点的和为num的路径 
            res+=findPath(node->left,num-node->val);
            res+=findPath(node->right,num-node->val);
            return res;
        }
};
int main() {
    //建树 
    /*****************
     * 测试用例:
     *
     *       10
     *      /  \
     *     5   -3
     *    / \    \
     *   3   2   11
     *  / \   \
     * 3  -2   1
     *****************/
    TreeNode* node1 = new TreeNode(3);
    TreeNode* node2 = new TreeNode(-2);
    TreeNode* node3 = new TreeNode(3);
    node3->left = node1;
    node3->right = node2;
    TreeNode* node4 = new TreeNode(1);
    TreeNode* node5 = new TreeNode(2);
    node5->right = node4;
    TreeNode* node6 = new TreeNode(5);
    node6->left = node3;
    node6->right = node5;
    TreeNode* node7 = new TreeNode(11);
    TreeNode* node8 = new TreeNode(-3);
    node8->right = node7;
    TreeNode* node9 = new TreeNode(10);
    node9->left = node6;
    node9->right = node8;
    cout << Solution().pathSum(node9, 8) << endl;
    return 0;
}