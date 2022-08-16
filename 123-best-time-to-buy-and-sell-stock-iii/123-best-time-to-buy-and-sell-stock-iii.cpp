class Solution {
public:
    
    
    
    int maxProfit(vector<int>& a) {
        
   
    
      int buy1 = INT_MIN;
      int sell = 0;
        
     int buy2 = INT_MIN;
     int sell2 = 0;
        
        for(int i = 0 ; i < a.size() ; i++)
        {
            
            
          buy1 = max(buy1 , -a[i]);
          sell = max(sell , buy1 + a[i]);
            
          buy2 = max(buy2 , sell-a[i]);
          sell2 = max(sell2 , buy2+a[i]);  
           
              
        }
        
        return sell2;
    }
};