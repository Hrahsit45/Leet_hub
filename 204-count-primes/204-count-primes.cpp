class Solution {
public:
    int countPrimes(int n) {
        
        vector<bool> prime(n , false);
        
        int ans = 0;
        
        for(long long int i = 2 ; i < n ; i++)
        {
            if(prime[i] == true)
            continue;
            
            ans++;
            
            for(long long int j = i*i ; j < n ; j+=i)
            {
                prime[j] = true;
            }
        }
        
        return ans;
    }
};