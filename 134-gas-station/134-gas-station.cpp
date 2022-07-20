class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
       
        int i = 0;
        int n = gas.size();
       
        int count = 0;
        while(count < n)
        {
            if(gas[i] - cost[i] >= 0)
            {
                int remain  = gas[i] - cost[i];
                
                int index = i;
                
                i = (i+1)%n;
                count++;
                
                while(remain >= 0 && i != index)
                {      
                    remain += gas[i] - cost[i];    
                    
                    i = (i+1)%n;
                    count++;
                }
                
                if(i == index && remain >= 0) 
                    return i;     
            }
            else
            {
                i++;
                count++;
            }
        }
        return -1;
    }
};