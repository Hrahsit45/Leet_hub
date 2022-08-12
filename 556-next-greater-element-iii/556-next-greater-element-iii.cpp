class Solution {
public:
    int nextGreaterElement(int n) {
        
        string nums = to_string(n);
       // cout<<num;
       // int i = num.size()-1;
        
         int i = nums.size()-1;
         int k = i;
        
        while(i > 0 && nums[i-1] >= nums[i])
            i--;
        
        if(i == 0 || (nums.size()>= 10 && nums >= "2147483486") )
            return -1;
        
        for(int j = i ; j < k ; j++ , k--)
            swap(nums[j],nums[k]);
        
        if(i > 0)
        {
            k = i--;
            
            while( k < nums.size() && nums[k] <= nums[i])
                k++;
            
            if (k < nums.size()){
            swap(nums[i] , nums[k]);
                
            }
            
        }
        
      
        //cout<<nums<<"\n";
        if((nums.size()>= 10 && nums > to_string(INT_MAX)))
        return -1;
         long a = stoi(nums) ;
        return a > INT_MAX ? -1 : a;
    }
};