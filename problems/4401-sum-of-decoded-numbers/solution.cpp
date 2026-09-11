class Solution {
public:
    int MOD = 1e9 + 7;
    long long pow(long long a , long long b){
        long long ans = 1;
        while(b > 0){
            if(b%2 == 1){
                ans = (ans*a)%MOD;
            }
            a = (a*a)%MOD;
            b /= 2;
        }
        return ans;
    }
    int sumDecoded(vector<long long>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            long long width = nums[i] % 10;
            long long d = nums[i] / 10;
            string num = to_string(d);
            string xi = num.substr(0, width);
            string yi = num.substr(width );
            long long x = 0;  if (xi.size()>0) { x = stoll(xi); }
            long long y = 0; if (yi.size()>0) { y = stoll(yi); }

            nums[i] = pow(x, y);
        }
        int ans = 0;
        for (auto it : nums) {
            ans = (ans + it) % MOD;
        }
        return ans;
    }
};