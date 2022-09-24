class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        vector<int> ans(nums.size() , 1);
        
        int curr = 1;
        
        int n = nums.size();
        
        for(int i = 0 ; i < n ; i++)
        {
            ans[i] *= curr;
            curr *= nums[i];
        }
        
        curr = 1;
        
        for(int i = n-1 ; i >= 0 ; i--)
        {
            ans[i] *= curr;
            curr *= nums[i];
        }
        
        return ans;
    }
};