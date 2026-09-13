class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        vector<vector<int>> posi(101);
        vector<int> freq(101,0);
        int n = nums.size();
        for(int i = 0 ; i<n ;i++){
            freq[nums[i]]++;
            posi[nums[i]].push_back(i);
            
        }
        int count= 0;
        for(int i = 0; i<= 100 ; i++){
            if(freq[i] == 3){
                int a = posi[i][0];
                int b = posi[i][1];
                int c = posi[i][2];
                if(b-a == c-b)count++;
            }
        }
        return count;
    }
};