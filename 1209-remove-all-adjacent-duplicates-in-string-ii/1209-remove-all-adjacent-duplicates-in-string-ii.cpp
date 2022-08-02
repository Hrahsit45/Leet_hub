class Solution {
public:
    string removeDuplicates(string s, int k) {
        
        vector <pair<char,int>>p;
        
        for(int i = 0 ; i<s.size(); i++)
        {
            if(p.empty())
            {
                p.push_back({s[i] , 1});
            }
            else
            {
                if(s[i] == p.back().first)
                {
                    p.push_back({s[i] , p.back().second + 1});
                }
                else
                {
                     p.push_back({s[i] , 1});
                }
            }
            
            if(p.back().second == k)
            {
                int x = k;
                while(x--)
                {
                    p.pop_back();
                }
            }
        }
        
        string ans = "";
        
        for(int i = 0; i<p.size() ; i++)
        {
            ans+=p[i].first;
        }
        return ans;
    }
};