class Solution {
public:
    int getScore(vector<int> & arr){
        int m = arr.size();
        if(m<=1)return 0;
        vector<int> pref(m),suff(m);
        pref[0] = arr[0];
        for(int i = 1 ; i<m ; i++){
            pref[i] = gcd(pref[i-1] , arr[i]);
        }
        suff[m-1] = arr[m-1];

        for(int i = m-2 ; i>= 0 ; i--){
            suff[i] = gcd(suff[i+1] , arr[i]);
        }

        int score = 0 ;
        for(int i = 0 ; i<m-1 ;i++ ){
            if(pref[i] == suff[i+1]){
                score++;
            }
        }
        return score;
    }
    int maxValidSplits(vector<int>& nums) {
        int n = nums.size();
        int ans = getScore(nums);

        for(int i = 0; i< n ;i++){
            vector<int> arr;
            for(int j = 0; j<n ;j++){
                if(j != i){
                    arr.push_back(nums[j]);
                }
            }
            ans = max(ans , getScore(arr));
        }
        return ans;
    }
};