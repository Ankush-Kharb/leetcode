class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        
        int count0 = 0,count1 = 0 ,count2 = 0;
        for (int i = 0;i<n;i++){
            if(nums[i]==0){count0++;}
            if ( nums[i]==1){count1++;}
            if(nums[i]==2){count2++;}
        }
        nums.erase(nums.begin(),nums.end());
        nums.insert(nums.begin(),count0,0);
        nums.insert(nums.begin()+count0,count1,1);
        nums.insert(nums.begin()+count0+count1,count2,2);
        
    }
};