class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
      
        stack<int> s;
        
        int area = 0;
        
        int n = heights.size();
        
        for(int i = 0 ; i<=n ; i++)
        {
            int h = i < n ? heights[i] : 0;
            
            while(!s.empty() && h < heights[s.top()])
            {
                int curr = heights[s.top()];
                s.pop();
                int x = s.empty()?-1:s.top();
                int cal = curr*(i - x - 1);
                area = max(cal , area);
            }
            
            s.push(i);
        }
        
        return area;
    }
};