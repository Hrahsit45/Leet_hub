/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head , ListNode* last = NULL) {
        
        if(head == last)
            return NULL;
        
     
        
//      ListNode* head2 = NULL;
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        
        while(fast != last && fast->next != last)
        {
            slow = slow->next;
            fast = fast->next->next;
           
        }
        int value = slow->val;
        
//         slow = NULL;
   
         TreeNode* mid = new TreeNode(value) ;
        
         mid->left =  sortedListToBST(head , slow);
         mid->right = sortedListToBST(slow->next , last);
        
        return mid;
    }
   
};