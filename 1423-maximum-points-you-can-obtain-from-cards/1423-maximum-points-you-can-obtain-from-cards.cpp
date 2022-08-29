class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        
        map<int,int> m;
        
        vector<int> pre(k) , post(k); 
        
        int i = 1;
        int j = cardPoints.size()-2;
        pre[i-1] = cardPoints[0];
        post[i-1] = cardPoints[j+1];
        
        while(i < k)
        {
            pre[i] = pre[i-1] + cardPoints[i];
            post[i] = post[i-1] + cardPoints[j];
            i++;
            j--;
        }
        
       int ans = max(pre[i-1] , post[i-1]);
       int count = 1;
        
        for(int i = 0 ; i < k; i++)
        {
            if(count != k)
            ans = max(pre[i] + post[k-count-1], max(pre[k-count-1] + post[i] , ans));
            count++;
        }
        
        return ans;
    }
};