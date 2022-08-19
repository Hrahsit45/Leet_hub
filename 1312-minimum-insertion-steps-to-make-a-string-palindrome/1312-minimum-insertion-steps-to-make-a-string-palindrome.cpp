class Solution {
public:
    vector<vector<int>> memo;
    
    int minInsertions(string s) {
        
         memo.resize(s.length(), vector<int> (s.length() , -1));
        
        return solver(0 , s.length() - 1 , s );
    }
    
    int solver(int i , int j , string &s )
    {
        if(i >= j)
            return 0;
        
        if(memo[i][j] != -1)
            return memo[i][j];
        
        if(s[i] == s[j])
        {
            return memo[i][j] = solver(i+1 , j-1 , s );
        }
        
        return memo[i][j] = 1+min(solver(i+1 , j , s ),solver(i , j-1 , s ));
    }
};