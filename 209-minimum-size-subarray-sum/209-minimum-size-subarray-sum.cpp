class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        
        int ans = nums.size()+1;
        
        int start = 0;
        int end = 0;
        int sum = 0;
        
        while(end < nums.size())
        {
            if(sum < target)
            {
                sum+=nums[end];
            }
            if(sum >= target)
            {
                while(start <= end && sum >= target)
                {
                    ans = min(ans , end - start + 1);
                    sum-=nums[start++];
                }
            }
            end++;
        }
        
        if(ans == nums.size()+1)
            return 0;
        
        return ans;
    }
};