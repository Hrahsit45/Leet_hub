class Solution {
public:
    string reorganizeString(string s) {
        
       unordered_map<char , int> mp;
        
       for(int i = 0 ; i < s.size() ; i++)
       {
           mp[s[i]]++;
       }
        
        priority_queue<pair<int,char>> pq;
        
        for(auto i : mp)
        {
            if(i.second > (s.size()+1)/2)
                return "";
            
            pq.emplace(i.second , i.first);
        }
        
        string ans = "";
        
        pair<int,char> prev(0,' ');
        
        while(!pq.empty())
        {
            pair<int , char> curr = pq.top();
            pq.pop();
            
            ans+= curr.second;
            
            curr.first--;
            
            if(prev.first > 0)
                pq.emplace(prev);
            
            prev = curr;
        }
        
         return ans;
    }
    
   
};