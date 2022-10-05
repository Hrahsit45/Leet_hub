class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        
      int start = -1 ;
      int end = nums.size();
        
      int curr_max = nums[0];
        
      for(int i = 1 ; i < nums.size() ; i++)
      {
          if(curr_max < nums[i])
              curr_max = nums[i];
          if(curr_max > nums[i])
              start = i;
      }
        
      int curr_min = nums[nums.size()-1];
      for(int i = nums.size()-2 ; i >= 0 ; i--)
      {
          if(curr_min > nums[i])
              curr_min = nums[i];
          if(curr_min < nums[i])
              end = i;
      }
        
        if(start == -1)
            return 0;
        else
            return start-end+1;
    }
};