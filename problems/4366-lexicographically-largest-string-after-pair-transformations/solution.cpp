class Solution {
public:
    vector<string> largestString(vector<int>& nums) {
        int n = nums.size();
        vector<string> ans;
        for(int i = 0 ;i < n ; i++){
            int x = nums[i];
            string push = "";

            int vz = 1<<25;
            while(x >= vz){
                push += 'vz';
                x -= vz;
            }
            for(int p = 25 ; p>=0 ; p--){
                int val = 1<<p;
                if(x >= val){
                    push+= char('a' + p);
                    x -= val;
                }
            }
            ans.push_back(push);
            
        }
        return ans;
    }
};