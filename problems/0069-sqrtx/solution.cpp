class Solution {
public:
    int mySqrt(int x) {
        int low = 1;
        int high = x;
        int mid;
        while(low<=high){
            mid = (low + (high - low)/2);
            if ((double)mid*mid == x) return mid;
            if ((double)mid*mid > x)high = mid-1;
            else low = mid+1;
        }return high;
        
    }
};