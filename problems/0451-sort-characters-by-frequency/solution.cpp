class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mpp;
        
        for(int i = 0 ; i<s.size() ;i++){
            mpp[s[i]] += 1;
        }
       
        priority_queue <pair<int,char>> pq;
        for(auto it : mpp){
            
            pq.push({it.second,it.first});

        }
        string st = "";
        while(!pq.empty())
        {
            int cnt = pq.top().first;
            while(cnt!=0)
            {
                st.push_back(pq.top().second);
                cnt--;
            }
            pq.pop();
        }
        return st;
    }
};