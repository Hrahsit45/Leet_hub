/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* right;
    
    TreeNode* bstToGst(TreeNode* root) {
        
        if(!root)
            return NULL;
        
        bstToGst(root->right);
        
        if(right)
        root->val+=right->val;
            
        right = root;
        
        bstToGst(root->left);
        
        return root;
    }
};