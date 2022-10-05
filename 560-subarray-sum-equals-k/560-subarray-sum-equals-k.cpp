class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> m;      
        int count = 0 , sum = 0;       
        m[0] = 1;    
        for(int i=0 ; i < nums.size() ; i++)
        {
            sum += nums[i];    
            if(m.count(sum-k)) count+= m[sum - k];
            m[sum]+=1;
        }      
        return count;
    }
};