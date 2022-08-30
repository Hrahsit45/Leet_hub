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
    TreeNode* deleteNode(TreeNode* root, int key) {
        
        if(!root)
            return NULL;
        
        
        if(root->val == key)
        {
            //case 1: leaf node
            if(!root->left && !root->right)
            {
                return NULL;
            }
            
            //case 2: has right subtree
            if(root->right)
            {
                int temp = 0;
                root->right = find(root->right , temp);
                root->val = temp;
                return root;
            }
            
            //case 3: has only left subtree
            return root->left;
            
        }
        
        root->left = deleteNode(root->left , key);
        root->right = deleteNode(root->right , key);
        
        return root;
    }
    
    TreeNode* find(TreeNode* root , int &temp)
    {
       if(!root)
           return NULL;
        
        if(!root->left){
            temp = root->val;
            return root->right;
        }
        
        root->left = find(root->left , temp);
        return root;
    }
};