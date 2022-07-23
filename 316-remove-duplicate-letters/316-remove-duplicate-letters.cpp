class Solution {
public:
    string removeDuplicateLetters(string s) {
        
        map<char,int> m;
        map<char,bool>x;
        for(int i = 0 ; i<s.size() ; i++)
        {
            m[s[i]]++;
            
        }
        
     
        
        stack<int>letter;
        
        
        for(int i = 0 ; i < s.size() ; i++)
        {
            m[s[i]]--;
            
            if(x[s[i]])continue;
                
          while(!letter.empty() && s[letter.top()] >= s[i] && m[s[letter.top()]] > 0)
          {
               x[s[letter.top()]]=false;
              letter.pop();
            
          }
                x[s[i]]=true;
                letter.push(i);
            
        }
        
        string ans = "";
        while(!letter.empty())
        {
            
            ans+=s[letter.top()];
         
            letter.pop();
        }
        reverse(ans.begin() , ans.end());
        return ans;
        
    }
};