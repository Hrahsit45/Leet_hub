class Solution {
public:
    int longestValidParentheses(string s) {
        
        stack<pair<char,int>> ans;
        
        int len = 0;
        for(int i = 0 ; i<s.size() ; i++)
        {
            if(s[i] == '(')
                ans.push({'(' , i});
            else if(!ans.empty() && ans.top().first != s[i]) 
            {
              //  cout<<ans.top().first<<" "<<s[i]<<" ";
                ans.pop();
                int length = ans.empty()?i+1:i-ans.top().second;
                len = max(length , len);
            }
            else
            {
                ans.push({')' , i});
            }
           // cout<<len<<"\n";
        }
        return len;
    }
};