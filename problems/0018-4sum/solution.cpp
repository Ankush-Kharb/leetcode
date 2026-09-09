class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        long long diff_1 = 0;
        int n = nums.size();
        long long diff_2 = 0;
        int b;
        if(n<4)return {};
        set<vector<int>> ans;
        for(int a = 0 ; a< n-3 ;a++){
            diff_1 = target - nums[a];
            for(int b = a+1; b< n-2; b++){
                int c = b+1; 
                int d = n-1;
                diff_2 = diff_1 - nums[b];
                while(c<d){
                if(nums[c]+nums[d]== diff_2){
                    vector<int> temp = {nums[a],nums[b],nums[c],nums[d]};
                    ans.insert(temp);
                    c++;
                    d--;
                }
                else if (nums[c]+nums[d] > diff_2){
                    d--;
                }
                else if (nums[c]+nums[d] < diff_2){
                    c++;
                }
                }
            }

        }
         vector<vector<int>> ans1;
         for(vector<int> v:ans)
        {
            ans1.push_back(v);
        }
        
        return ans1;
        
    }
};