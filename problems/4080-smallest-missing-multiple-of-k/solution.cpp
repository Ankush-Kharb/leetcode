class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> st(nums.begin(), nums.end());
        int i = 2;
        int temp = k;
        while(true){
            if(st.find(temp) != st.end()){
                temp = k*i;
                i++;
            }
            else return temp;
        }
        return -1;
    }
};