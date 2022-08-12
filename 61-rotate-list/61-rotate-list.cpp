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
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) 
    {
        
        if(!head || head->next == NULL || k == 0)
            return head;
        
        ListNode* l = head;
        
        int len = 0;
        while(l->next!=NULL)
        {
            l = l->next;
            len++;
        }
    
        
        k = k % (len+1);
        k = len + 1 - k;
        
        if(k == 0)   return head;
        
        l->next = head;
    //    l = l->next;
        
       // ListNode* curr = head;
       
        while(k--)
        {
          l = l->next;
        }
        
        head = l->next;
        l->next = NULL;
        
        
        return head;
        
    }
};