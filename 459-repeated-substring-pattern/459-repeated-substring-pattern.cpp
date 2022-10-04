class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        
        vector<int> lps(s.size());
        
        int i = 1;
        int len = 0;
        
        while(i < s.size())
        {
            if(s[i] == s[len])
            {
                len++;
                lps[i] = len;
                i++;
            }
            else
            {
                if(len != 0)
                {
                    len = lps[len-1];
                }
                else
                {
                    len = 0;
                    lps[i] = 0;
                    i++;
                }
            }
        }
        
        if(lps[s.size()-1] && (lps[s.size()-1] % (s.size() - lps[s.size()-1] )) == 0)
            return true;
        else
            return false;
    }
    
};