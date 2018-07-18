class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!q&&!p)
            return true;
        else if(q&&!p)
            return false;
        else if(!q&&p)
            return false;
        else{
            if(p->val!=q->val)
                return false;
            else 
                return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
        }
    }
};
