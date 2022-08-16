class Solution {
public:
    
    
    
    int maxProfit(vector<int>& a) {
        
    vector<vector<int>> dp(2 , vector<int> (2 , 0));
    
    dp[0][0] = INT_MIN;
    dp[1][0] = 0;
    dp[0][1] = INT_MIN;
        
        for(int i = 0 ; i < a.size() ; i++)
        {
            
            //1.buy
            dp[0][0] = max(dp[0][0] , -a[i]);
                
            //2.sell
            dp[1][0] = max(dp[1][0] , dp[0][0]+a[i]);
  
            //when one chance is left 
            
            //1.buy
            dp[0][1] = max(dp[1][0]-a[i] , dp[0][1]);
            
            //2.sell
            dp[1][1] = max(dp[0][1] + a[i] , dp[1][1]);
            
              
        }
        
        return dp[1][1];
    }
};