class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        vector<int> dp(s.size()+1 , 0);
        
        dp[0] = 1;
        
        for(int i = 1 ; i <= s.size(); i++)
        {
            string word = "";
            for(int j = i - 1 ;  j>= 0 ; j-- )
            {
                word = s[j]+word;
                if(dp[j])
                {
                    
                    
                    if(find(wordDict.begin() , wordDict.end() , word) != wordDict.end())
                    {
                        dp[i] = 1;
                        break;
                    }
                }
            }
        }
        
        return dp[s.size()];
    }
};