class Solution {
public:
    int maxProfit(vector<int>& a) {
        
       int sell = 0;
       int buy = INT_MIN;
        
       for(int i = 0 ; i<a.size() ; i++)
       {
           buy = max(buy , sell - a[i]);
           sell = max(sell , buy + a[i]);
       }
        
        return sell;
    }
};