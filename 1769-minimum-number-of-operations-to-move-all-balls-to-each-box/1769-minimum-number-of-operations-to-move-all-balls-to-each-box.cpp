class Solution {
public:
    vector<int> minOperations(string boxes) {
        
        vector<int> left(boxes.size(), 0);
        vector<int> right(boxes.size() , 0);
        
        int count = boxes[0]-'0';
        for(int i = 1 ; i< boxes.size() ; i++)
        {
            left[i] = left[i-1] + count;
            count+= boxes[i]-'0' ;
        }
        count = boxes[boxes.size()-1]-'0';
        for(int i = boxes.size()-2 ; i>= 0 ; i--)
        {
            right[i] = right[i+1]+count;
            count+=boxes[i]-'0';
        }
        
        vector<int> ans(boxes.size());
        
        for(int i = 0; i < boxes.size(); i++)
        {
            if(i == 0)
            {
                ans[i] += right[i];
            }
            else if(i == boxes.size()-1)
            {
                ans[i] += left[i];
            }
            else
            {
                ans[i] = left[i] +right[i];        
            }
        }
        
        return ans;
    }
};