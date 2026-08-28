class Solution {
public:
    int sum(vector<int> &weights){
        int n = weights.size();
        int sum = 0;
        for(int i = 0; i<n;i++){
            sum += weights[i];
        }return sum;
    }
     


    int calculated_days(vector<int>& weights , int mid){
        int n = weights.size();
        int count = 0;
        int day = 1;
        for(int i = 0;i<n;i++){
            if(count + weights[i] > mid){
                day++;
                count = 0;
            }
            count += weights[i];
            

        }return day;
        
    }






    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int low = *max_element(weights.begin(),weights.end());
        int high = sum(weights);
        int mid;
        int calculated_day;
        int ans = high;
        if(n==days)return *max_element(weights.begin(),weights.end());
        while(low<=high){
            mid = (low+(high - low)/2);
            calculated_day = calculated_days(weights , mid);
            if ( calculated_day <= days) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid+1;
            }
        }return ans;
        
    }
};