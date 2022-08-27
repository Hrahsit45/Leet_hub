class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        if(!pairs.size()) return 0;
        sort(pairs.begin(), pairs.end() , comp);
        
        int ans = 1;
        int cur_min = pairs[0][1];
        
        for(int i = 1 ; i<pairs.size(); i++)
        {
            if(cur_min < pairs[i][0])
            {
                ans++;
                cur_min = pairs[i][1];
            }
            else
            {
                cur_min =  min(cur_min , pairs[i][1]);
            }
        }
        
        return ans;
		
    }
    static bool comp (vector<int> a , vector<int> b)
    {
        return a[0]<b[0];
    }
};