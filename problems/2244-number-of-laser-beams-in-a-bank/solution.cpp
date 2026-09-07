class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n = bank.size();
        int m = bank[0].size();
        int i = 0;
        int j =0;
        int count = 0;
        vector<int> lasers;
        while(i<n){
            while(j<m){
            if(bank[i][j]=='1'){
                count++;
                
            }
            j++;
            }
            if (count != 0)lasers.push_back(count);

            count = 0;
            i++;
            j = 0;
        }
        int ans = 0;
        if(lasers.size()==0 || lasers.size()==1)return ans;
        for(int i = 0; i<lasers.size()-1;i++){
        ans += lasers[i]*lasers[i+1];
        }
        return ans;
        
    }
};