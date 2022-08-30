class Solution {
public:
    
    int count(vector<int> nums , int k)
    {
        int start = 0;
        int end = 0;
        
        map<int,int> frq;
        
        
        int distinct = 0;
        
        int ans = 0;
        
        while(end < nums.size())
        {
            if(frq[nums[end]] == 0)
                distinct++;
            
            frq[nums[end]]++;
            
            while(distinct > k)
            {
                frq[nums[start]]--;
                
                if(frq[nums[start]] == 0)
                    distinct--;
                
                start++;
            }
            
            ans += end - start + 1;
            end++;
        }
        
        return ans;
    }
    
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        
        return count(nums , k)-count(nums , k-1);
    } 
};