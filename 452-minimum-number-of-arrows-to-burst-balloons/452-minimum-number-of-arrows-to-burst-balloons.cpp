class Solution {
public:
    
    static bool cmp(vector<int> &a , vector<int> &b)
    {
       return  a[1] < b[1]; 
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        
        int count = 0;
        
        sort(points.begin() , points.end() , cmp);
        
        int mi = 0;
        
        for(int i = 0 ; i < points.size() ; i++)
        {
            if(mi < points[i][0] || count == 0)
            {
                count++;
                mi = points[i][1];
            }
        }
        
        return count;
        
    }
};