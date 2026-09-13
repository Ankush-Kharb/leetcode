class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int ,vector<int>> mp;
        unordered_map<int,int> freq;

        for(int i = 0; i< nums.size();i++){
            freq[nums[i]]++;
            mp[nums[i]].push_back(i);
        }
        int count = 0;
        for(auto & [value , posi ] : mp){
            if(freq[value] >= 3){
                int space = posi[1]-posi[0];
                bool flag = true;
                for(int j = 2 ; j< posi.size() ;j++){
                    if(posi[j] - posi[j-1] != space){
                        flag = false;
                        break;
                    }
                }
                if(flag)count++;
            }
        }
        return count;
    }
};