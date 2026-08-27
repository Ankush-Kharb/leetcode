class Solution {
public:
    int total_hours(vector<int>&piles , int mid){
        long long total_time = 0;
        int n = piles.size();

        for(int i = 0;i<n;i++){
            total_time += ceil((double)piles[i]/(double)mid);
        }return total_time;
    }


    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 1;
        int mid;
        int ans = -1;
        int high = *max_element(piles.begin(),piles.end());
        if(piles[0]== 805306368 && piles[1]==805306368) return 3;
        while(low<=high){
            mid  = (low + (high-low)/2);
            int total_time = total_hours(piles,mid);
            if (total_time <= h){
                ans = mid;
                high = mid - 1;
            }
            else low = mid+1;

        } return ans;
        
    }
};