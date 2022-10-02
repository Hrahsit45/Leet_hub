class Solution {
public:
    string removeDuplicateLetters(string s) {
       
        stack<char> ans;
        
        unordered_map<char,int> m;
        unordered_map<char,bool> check;
        
        for(int i = 0 ; i < s.size() ; i++)
        {
            m[s[i]]++;
            check[s[i]]=false;
        }
        
      
        
        for(int i = 0 ; i < s.size() ; i++)
        {
            
            while(!ans.empty() && !check[s[i]] && s[i] <= ans.top() && m[ans.top()] >= 1)
            {
                check[ans.top()] = false;
                ans.pop();
            }
            if(check[s[i]] == false)
            {
                ans.push(s[i]);
                check[s[i]] = true;
            }
            m[s[i]]--;       
        }
        
        string res = "";
        
        while(!ans.empty())
        {
            res = ans.top() + res;
            ans.pop();
        }
        
        return res;
    }
};