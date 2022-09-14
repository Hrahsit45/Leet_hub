class Solution {
public:
    vector<int> memo;
    
    int numTrees(int n) {
        
         vector< long long int> catalan(n+1);
        
        catalan[0] = catalan[1] = 1;
        
        for(int i = 2 ; i<= n ; i++)
        {
            //catalan[i] = 0;
            for(int j = 0 ; j<i ; j++)
            {
                catalan[i] += catalan[j]*catalan[i - j - 1];
            }
        }
        return catalan[n];  
        
//         memo.resize(n+1 , 0);
        
//         return count(n);
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