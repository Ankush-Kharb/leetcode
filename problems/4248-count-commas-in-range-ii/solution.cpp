class Solution {
public:
    long long countCommas(long long n) {
        long long base = 1000;
        long long commas = 1;
        long long ans = 0;
        while(n >= base){
            long long end = base*1000 -1;
            long long count = min(n,end) - base + 1;

            ans += count*commas;
            commas++;
            base = base*1000;
        }
        return ans;

    }
};