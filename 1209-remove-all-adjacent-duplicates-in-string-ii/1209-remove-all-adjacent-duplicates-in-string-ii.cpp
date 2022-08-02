class Solution {
public:
    string removeDuplicates(string s, int k) {
        
        stack <pair<char,int>>p;
        
        for(int i = 0 ; i<s.size(); i++)
        {
            if(p.empty())
            {
                p.push({s[i] , 1});
            }
            else
            {
                if(s[i] == p.top().first)
                {
                    p.push({s[i] , p.top().second + 1});
                }
                else
                {
                     p.push({s[i] , 1});
                }
            }
            
            if(p.top().second == k)
            {
                int x = k;
                while(x--)
                {
                    p.pop();
                }
            }
        }
        
        string ans = "";
        
        while(!p.empty())
        {
            ans+=p.top().first;
            p.pop();
        }
        
        reverse(ans.begin() , ans.end());
        
        return ans;
    }
};