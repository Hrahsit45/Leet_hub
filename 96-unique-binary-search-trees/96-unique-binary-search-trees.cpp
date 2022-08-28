class Solution {
public:
    vector<int> memo;
    
    int numTrees(int n) {
        
        memo.resize(n+1 , 0);
        
        return count(n);
    }
    
    int count(int n)
    {
       if(n <= 1)
           return 1;
        
        if(memo[n] != 0)
            return memo[n];
        
        for(int i = 0 ; i < n ;i++)
        {
            memo[n] += count(i)*count(n-i-1);
        }
        
        return memo[n];
    }
};