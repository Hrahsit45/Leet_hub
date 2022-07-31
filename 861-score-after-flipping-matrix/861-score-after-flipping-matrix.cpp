class Solution {
public:
    int matrixScore(vector<vector<int>>& a) {
        
        vector<int> col_freq(a[0].size());
        
        for(int i = 0 ; i<a.size() ; i++)
        {
            if(a[i][0] == 1)
            {
                 for(int j = 1 ; j < a[i].size() ; j++)
            {
                if(a[i][j] == 1)
                {
                    col_freq[j]++;
                }
            }
            }
            else
            {
            a[i][0]=1;
            for(int j = 1 ; j<a[i].size() ; j++)
            {
                if(a[i][j] == 0)
                {
                    col_freq[j]++;
                    a[i][j] = 1;
                }
                else
                    a[i][j]=0;
            }
            }
        } 
        
//             for(int i = 0 ; i<a.size() ; i++)
//         {
//             for(int j = 0 ; j< a[i].size() ; j++)
//             {
//                 cout<<a[i][j]<<" ";
//             }
//             cout<<"\n";
//         }
        
        for(int j = 1 ; j < a[0].size() ; j++)
        {
             if(col_freq[j] >= ceil(1.0*a.size()/2))continue;
          
            
            for(int i = 0 ; i<a.size() ; i++)
            {
                if(a[i][j] == 0)
                {
                    a[i][j] = 1;
                }
                else
                    a[i][j] = 0;
            }
        }   
        
    
        
          int result = 0,sum;
        for(vector<int> v : a){
            sum = 0;
            for(int j = v.size()-1;j >= 0 ;j--){
                if(v[j] == 1)
                    sum += pow(2,v.size()-1-j);
                
            }
            
            result += sum;
        }
        
        return result;
    }
};