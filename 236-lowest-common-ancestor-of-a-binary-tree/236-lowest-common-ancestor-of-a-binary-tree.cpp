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
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)
            return NULL;
        
        if((root->val == p->val || root->val == q->val))
            return root;
        
        TreeNode* left = NULL;
        TreeNode* right = NULL;
        
        left = lowestCommonAncestor(root->left , p , q);
        right = lowestCommonAncestor(root->right , p , q);
        
         if(left && right)
             return root;
        else if(!left)
            return right;
        else
            return left;      
        }
        
    
};