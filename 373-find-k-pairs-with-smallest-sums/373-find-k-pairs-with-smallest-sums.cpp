class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        
        priority_queue< pair<int,pair<int,int>> , vector<pair<int , pair<int , int> >> , greater<pair<int,pair<int,int> >> > pq;
        
        pq.push({nums1[0] + nums2[0] , {0 , 0}});
        
        vector<vector<int>> ans;
        
        while(pq.size() > 0 && ans.size() != k)
        {
            pair<int,pair<int,int>> curr = pq.top();
            pq.pop();
            
            ans.push_back({nums1[curr.second.first] , nums2[curr.second.second]});
            
            int i = curr.second.first;
            int j = curr.second.second;
            
            if(j==0&&i+1<nums1.size())
            {
                 pq.push({nums1[i+1] + nums2[j] , {i+1, j}});
            }
            if(i<nums1.size()&&j+1<nums2.size())
            {
                 pq.push({nums1[i] + nums2[j+1] , {i , j+1}});
            }
        }
        
        return ans;
    }
};