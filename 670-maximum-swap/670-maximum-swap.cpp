class Solution {
public:
    int maximumSwap(int num) {
        
        int maxdigit = -1;
        int maxidx =  -1;
        int leftidx = -1;
        int rightidx = -1;
        
        string s = to_string(num);
        
        for(int i = s.size()-1 ; i>= 0 ; i--)
        {
            if(s[i] - '0' > maxdigit)
            {
                maxdigit = s[i] - '0';
                maxidx  = i;
                continue;
            }
            if(s[i] - '0' < maxdigit)
            {
                leftidx = i;
                rightidx = maxidx;
            }
        }
        
        if(leftidx == -1)
            return num;
        
        swap(s[leftidx] , s[rightidx]);
        
        num = stoi(s);
        
        return num;
        
    }
};