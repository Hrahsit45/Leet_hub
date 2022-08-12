class Solution {
public:
    int minDistance(string word1, string word2) {
        
        vector<vector<int>> dp(word1.size()+1 ,vector<int> (word2.size()+1 ,-1));
        return solver(word1.size() , word2.size() ,  dp , word1 , word2);
    }
    
    int solver(int i , int j , vector<vector<int>> &dp , string w1 , string w2 )
    {
        if(i == 0 && j == 0)
            return 0;
        if(i == 0 )
            return j;
        if(j == 0)
            return i;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        if(w1[i-1] == w2[j-1])
        {
            return dp[i][j] = solver(i-1 , j-1 , dp , w1 , w2);
        }
        
        return dp[i][j] = 1 + min(solver(i-1 , j , dp , w1 , w2) , min(solver(i , j-1 , dp , w1  , w2) , solver(i-1 , j-1 , dp , w1 , w2)));
    }
};