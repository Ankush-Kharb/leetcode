class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n= nums.size();
        int diff;
        int k = n-1;
        int count = 0;
        set<vector<int>> ans;
        for(int i = 0; i<n ;i++){
            diff = 0-nums[i];
            int j = i+1;
            while(j<n && j!= k && i!=k){
                if(nums[j]+nums[k] == diff){
                    vector<int> temp = {nums[i],nums[j],nums[k]};
                    sort(temp.begin(),temp.end());
                   
                  
                    ans.insert(temp);
                    j++;
                    k--;

                }
                else if (nums[j]+nums[k] > diff){
                    k--;
                }
                else if (nums[j]+nums[k] < diff){
                    j++;
                }
            }
            k = n-1;

        }
         vector<vector<int>> ans1;
         for(vector<int> v:ans)
         {
            ans1.push_back(v);
         }
        cout<< count;
        
        return ans1;
        
    }
};