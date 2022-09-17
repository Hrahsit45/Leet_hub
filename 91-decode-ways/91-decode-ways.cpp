class Solution {
public:
    
    int numDecodings(string s) {
      
        if(s.length() == 0)
            return 0;
        int n = s.length();
        vector<int> dp(n+1);
        
        
        dp[0] = 1;
        dp[1] = s[0]!='0'?1:0;
       // cout<<dp[0]<<" "<<dp[1]<<" ";
       for(int i =2 ; i< n+1 ; i++)
       {
           int one = s[i-1] - '0';
           int two = 10*(s[i-2] - '0') + s[i-1]-'0';
      //     cout<<one<<" "<<two<<" ";
           if(one >=1 && one <=9)
               dp[i] = dp[i-1] + dp[i];
           
           if(two >=10 && two <= 26)
               dp[i] = dp[i-2] + dp[i];
           
   //         cout<<dp[i]<<" ";
       }
        
        return dp[n];
    }
};