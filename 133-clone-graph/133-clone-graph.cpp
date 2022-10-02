/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        
        if(node == NULL)
            return NULL;
        
        if(node->neighbors.size() == 0)
        {
            Node* clone = new Node(node->val);
            return clone;
        }
       
       unordered_map<Node* , Node*> m;
       return dfs(node , m);
        //return node;
    }
    
    Node* dfs(Node* node ,  unordered_map<Node* , Node*> &m)
    {
        Node* clone = new Node(node->val);
        
        vector<Node*> neigh;
        
        m[node] = clone;
        
        for(auto x : node->neighbors)
        {
          if(m.find(x) != m.end())
          {
              neigh.push_back(m[x]);
          }
        else
          neigh.push_back(dfs(x, m));
        }
        
        clone->neighbors = neigh;
        
        return clone;
    }
};