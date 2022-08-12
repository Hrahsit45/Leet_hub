/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head , Node* last = NULL) {
      
        if(!head)
            return head;
        
      Node* curr = head;
        
     // if(curr->next == NULL && curr->child != NULL)
     // {
     //          Node*  node = flatten(curr->child , curr->next);
     //          curr->next = node;
     //          node->prev = curr;
     //          curr->child = NULL;    
     // }
     Node* prev ;
    while(curr)
      {
          prev = curr;
          if(curr->child == NULL)
          {
              curr = curr->next;
          }
          else
          {
              Node*  node = flatten(curr->child , curr->next);
              curr->next = node;
              node->prev = curr;
              curr->child = NULL;       
          }
      }
        
        prev->next = last;
        if(last)
        last->prev = prev;
        return head;
    }
};