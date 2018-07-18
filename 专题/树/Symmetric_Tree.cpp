/*
	Name: Symmetric Tree
	Copyright: 
	Author: Homosapiens
	Date: 18/07/18 23:37
	Description: 给定一个二叉树，判断是否对称 
*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    bool checkNode(TreeNode* node1,TreeNode* node2){
        if(node1==NULL&&node2==NULL)
            return true;
        if(node1==NULL||node2==NULL)
            return false;
        if(node1->val!=node2->val)
            return false;
        else{
            return checkNode(node1->left,node2->right)&&checkNode(node2->left,node1->right);
        }
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(!root)
            return true;
        return checkNode(root->left,root->right);
    }
};
