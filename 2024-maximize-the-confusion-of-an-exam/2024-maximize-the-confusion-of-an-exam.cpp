class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        
        int frq[2]={0,};
        
        int end = 0 ;
        int start = 0;
        
        int ans =0;
        
        while(end < answerKey.size()){
        
            if(answerKey[end] == 'T')
                frq[0]++;
            else
                frq[1]++;
            
           
            while(frq[0] > k && frq[1] > k)
            {
                if(answerKey[start] == 'T')
                frq[0]--;
            else
                frq[1]--;
                
                start++;
            }
        
            ans = max(ans , end - start + 1);
            end++;
        }
        
        return ans;
    }
};