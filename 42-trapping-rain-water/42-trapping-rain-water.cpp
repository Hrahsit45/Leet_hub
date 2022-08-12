class Solution {
public:
    int trap(vector<int>& height) {
        
        int left = 0;
        int right = height.size()-1;
        
        int leftmax = 0;
        int rightmax = 0;
        
        int ans = 0;
        
        while(left <= right)
        {
            if(height[left] < height[right])
            {
                if(height[left] < leftmax)
                {
                    ans += leftmax-height[left];
                    left++;
                }
                else
                {
                    leftmax = height[left];
                    left++;
                }
            }
            else
            {
                if(height[right] < rightmax)
                {
                    ans += rightmax-height[right];
                    right--;
                }
                else
                {
                    rightmax = height[right];
                    right--;
                }
            }
        }
        
        return ans;
    }
};