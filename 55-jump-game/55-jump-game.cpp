class Solution {
public:
    bool canJump(vector<int>& nums) {

        int n = nums.size() ;
        if(n == 1) return true;
        
        int steps  = 0 ;
        
        for(int i = 0 ; i < n ; i++)
        {
            steps = max(steps , nums[i]);
            steps--;
      
            if(steps < 0 && i != n-1)
                return false;
        }
        
        return true;
    }
};