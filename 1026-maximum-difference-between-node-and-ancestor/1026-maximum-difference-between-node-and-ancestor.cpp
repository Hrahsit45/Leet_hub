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
    int maxAncestorDiff(TreeNode* root) {
        
        if(!root)
            return 0;
        
        int root_value = 0;
        int child_value = 0;
        
        root_value = find_dis(root , root);
        child_value = max(maxAncestorDiff(root->left),maxAncestorDiff(root->right));
        
        return max(root_value , child_value);
    }
    
    int find_dis(TreeNode* root , TreeNode* parent)
    {
        if(!root)
            return 0;
        
        int ans = abs(parent->val - root->val);
        
        int ans2 = max(find_dis(root->left , parent),
                       find_dis(root->right , parent));
        
        return max(ans , ans2);
        
    }
};