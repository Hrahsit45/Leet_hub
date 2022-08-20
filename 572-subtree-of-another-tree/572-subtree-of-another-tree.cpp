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
    string genrate_1(TreeNode* root , string &s , bool &flag)
    {
        if(!root)
            return "0";
        
        string s1 = to_string(root->val);
        
        s1 += genrate_1(root->left , s , flag);
        s1 += genrate_1(root->right , s , flag);
        
        if(s1 == s)
            flag = true;
        
        return s1;
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        
        string s ;
        
        s = genrate(subRoot);
        
        cout<<s<<"\n";
        
        bool flag = false;
        
        s = genrate_1(root , s , flag);
        
        return flag;
        
    }
    
    string genrate(TreeNode* root) {
        if(!root)
            return "0";
        
        string s = to_string(root->val);
        
        s += genrate(root->left);
        s += genrate(root->right);
        
        return s;
    }
};