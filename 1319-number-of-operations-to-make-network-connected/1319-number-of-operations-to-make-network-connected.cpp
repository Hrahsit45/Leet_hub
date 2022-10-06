class Solution {
public:

    int makeConnected(int n, vector<vector<int>>& connections) {
        
        
        if(connections.size() < n-1)
            return -1;
        
        vector<vector<int>> adj(n);
        
        for(int i =  0 ; i < connections.size() ; i++)
        {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        
        stack<int> s;
        vector<int> vis(n);
        int left = 0;
        
        for(int i = 0 ;  i < n ; i++)
        {
            if(vis[i] != 1)
            {
                left++;
                s.push(i);
                while(!s.empty())
                {
                    int u = s.top();
                    s.pop();
                    
                    if(!vis[u])
                    {
                        vis[u] = 1;
                        for(auto v : adj[u])
                        {
                            if(vis[v]==0)
                            {
                                s.push(v);
                            }
                        }
                    }
                }
            }
        }
        return left-1;
    }
};