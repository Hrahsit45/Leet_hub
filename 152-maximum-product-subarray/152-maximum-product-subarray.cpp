class Solution {
public:
    int maxProduct(vector<int>& a) {
      
        int min_prod = a[0];
        int max_prod = a[0];
        int ans = a[0];
        
        for(int i = 1 ; i < a.size() ; i++)
        {
           if(a[i] < 0)
           swap(min_prod , max_prod);
            
            min_prod = min(a[i] , min_prod * a[i]);
            max_prod = max(a[i] , max_prod * a[i]);
            
         ans = max(ans , max_prod);   
            
        }
        return ans;
    }
};