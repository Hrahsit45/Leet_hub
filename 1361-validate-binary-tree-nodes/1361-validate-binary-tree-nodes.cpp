class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        
        vector<int> in(leftChild.size() , 0);
        
        for(int i = 0 ; i<leftChild.size() ; i++)
        {
            if(leftChild[i]!=-1 && in[leftChild[i]]++==1)
                return false;
            if(rightChild[i]!=-1 && in[rightChild[i]]++==1)
                return false;
        }
        
        int root = -1;
        
        for(int i = 0 ; i<leftChild.size() ; i++)
        {
            if(in[i] == 0)
            {
                if(root == -1)
                    root=i;
                else
                    return false;
            }
        }
        
        if(root == -1)
            return false;
        
         return countNodes(leftChild,rightChild,root)==n;
     
    }
    int countNodes(vector<int> &l,vector<int> &r,int root)   // DFS from root to validate that all nodes are visited.
    {
        if(root==-1)
            return 0;
        return 1+countNodes(l,r,l[root])+countNodes(l,r,r[root]);
    }
  
};