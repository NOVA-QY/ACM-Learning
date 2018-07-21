/*
    Name: Lowest Common Ancestor of a Binary Search Tree(leetcode 235) 
    Copyright: 
    Author: Homosapiens
    Date: 21/07/18 12:12
    Description: 在给定的一棵二分搜索树中，求两个节点的最近公共祖先 
    分三种情况：
    1.p、q两节点分别在根节点的左、右子树中，返回root
    2.p、q两节点分别在根节点的左子树中，在左子树中继续查找
    3.p、q两节点分别在根节点的右子树中，在右子树中继续查找
*/
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        assert(p!=NULL && q!=NULL);
        if(root==NULL)
            return NULL;
        if(p->val<root->val && q->val<root->val)
            return lowestCommonAncestor(root->left , p, q);
        if(p->val>root->val && q->val>root->val)
            return lowestCommonAncestor(root->right , p, q);
        return root;
    }
};