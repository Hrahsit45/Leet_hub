class Solution {
public:
    int jump(vector<int>& a) {
        
        if(a.size() == 1)
            return 0;
     
        int jumps = 0;
        int steps_allowed = 0;
        int best = 0;
        int n = a.size();
        
        for(int i = 0 ; i < a.size() ; i++)
        {
            if(best < 0)
                return -1;
            
            if(steps_allowed == 0 && i!=n-1)
            {
                steps_allowed = max(a[i] , best);
                jumps++;
            }
            
            best = max(best , a[i]);
            steps_allowed--;
            best--;
            
          
        }
        
        return jumps;
        
    }
};