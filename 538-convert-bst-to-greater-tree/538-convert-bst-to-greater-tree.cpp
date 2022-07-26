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
    TreeNode *Right;
    TreeNode* convertBST(TreeNode* root , TreeNode *r=NULL) {
        
       if(!root)
           return root;
        
        
        // if(Right)
        //     root->val += Right->val;
        
        
        convertBST(root->right , Right);
    
        if(Right)
            root->val += Right->val;
        
        Right = root;
        
        convertBST(root->left , Right);
        
        
        // cout<<root->val<<"\n";
        
    
        return root;
         
    }
};