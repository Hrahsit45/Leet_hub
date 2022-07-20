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
    int depth ;
    int deepestLeavesSum(TreeNode* root  ) {
        
        int sum = 0;
        int depth = 0;
        int h = 0;
        solve(root , depth , h , sum);
        return sum ;       
    }
    void solve(TreeNode* root , int &depth , int h , int &sum)
    {
        if(!root)
            return ;
          
        if(!root->left && !root->right)
        {
            if(h == depth)
                sum+=root->val;
            if(h > depth)
                sum =root->val;
            depth = max(h , depth);       
        }
        
        solve(root->left , depth , h+1 , sum);
        solve(root->right , depth , h+1 , sum);
    }
};