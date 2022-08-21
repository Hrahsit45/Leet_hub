class Solution {
public:
    int jump(vector<int>& A) {
        
        
        if(A.size()== 1)
            return 0;
        
         int best = A[0];
        
        int curr = A[0];
        
        int jump = 1;
        
        for(int i  = 0 ; i < A.size()-1;  i++)
        {

            
            if(A[i] == 0 && best == 0)
            return 0;
          
            best = max(best , A[i]);
            
            if(curr == 0)
            {
                jump++;
                curr = best;
            }
            
            curr--;
            best--;
        }
        
        return jump;
    }
};