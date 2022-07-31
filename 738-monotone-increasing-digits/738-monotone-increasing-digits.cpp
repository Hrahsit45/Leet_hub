class Solution {
public:
    int monotoneIncreasingDigits(int n) {
         
        string s = to_string(n);
        int i ;int idx = s.size()-1;
        int rdx = idx;
        char m = s[s.size()-1];
        for( i = s.size()-2 ; i >= 0 ; i--)
        {
            if(s[i] > m || (s[i] == m && idx != i+1 && rdx!=i+1))
            {
                int digit = s[i]-'0';
                if(digit == 0)
                    m = '9';
                else
                    m = char(digit-1 + '0');
                
                idx = i;
                rdx = i;
                cout<<m<<"\n";
            }
            else
            {
                m = s[i];
                rdx = i;
            }
           
        }     
        
        if(idx == s.size()-1)
            return n;
        
        int digit = s[idx]-'0';
                if(digit == 0)
                    m = '9';
                else
                    m = char(digit-1 + '0');
        s[idx] = m;
        
        for(int i = idx+1 ; i < s.size()  ; i++)
        {
            s[i] = '9';
        }
        
        n = stoi(s);
        
        return n;
    }
};