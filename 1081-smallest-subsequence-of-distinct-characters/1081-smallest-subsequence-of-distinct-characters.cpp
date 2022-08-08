class Solution {
public:
    string smallestSubsequence(string s) {
        
        vector<bool> visited(26,false);
        
        vector<int> f(26, 0);
        
        stack<int> stk;
        
        for(int i = 0 ; i < s.size() ; i++)
        {
            f[s[i]-'a']++;
        }
        
        for(int i = 0 ; i < s.size() ; i++)
        {
            if(f[s[i]-'a'] >= 1 && visited[s[i] - 'a'] == false ){
              //  cout<<1<<" "<<i<<"\n";
        while(!stk.empty() && f[s[stk.top()]-'a'] >= 1 && s[i] < s[stk.top()])
            {
                
                visited[s[stk.top()] - 'a'] = false;
                stk.pop();
            }
            visited[s[i]-'a'] = true;
            stk.push(i); 
            }
            
            f[s[i]-'a']--;
                
        }
        
        string ans = "";
        
        while(!stk.empty())
        {
            ans = s[stk.top()] + ans;
            stk.pop();
        }
        
        
        return ans;
    }
};