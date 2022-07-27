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
    int k;
    Solution()
    {
        k = 0;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder , int upper_value = INT_MAX) {
        
        if(k >= preorder.size())
            return NULL;
        
        TreeNode* root;
        if(preorder[k] <= upper_value)
        {
           root = new TreeNode(preorder[k++]);
        }
        else
        return NULL;
        
        root->left = bstFromPreorder(preorder , root->val);
        root->right = bstFromPreorder(preorder , upper_value);
        
        return root;
    }
};