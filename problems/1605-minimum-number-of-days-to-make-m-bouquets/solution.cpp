class Solution {
public:
    int bouquets(vector<int> &bloomDay ,int mid,int k){
        int n = bloomDay.size();
        int count = 0;
        int bouquets = 0;

        for(int i = 0;i<n; i++){
            if(bloomDay[i]<= mid){
                count++;
                if(count == k){
                    bouquets ++;
                    count = 0;
                    }
            }
           
            else count = 0;
    }return bouquets;
    }








    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        int low = *min_element(bloomDay.begin(),bloomDay.end());
        int high = *max_element(bloomDay.begin(),bloomDay.end());
        int mid ;
        int bouquet;
        int ans = -1;
        if((long)m*k > n)return -1;
        while (low<=high){
            mid = (low+(high-low)/2);
            bouquet = bouquets(bloomDay , mid ,k);
            if (bouquet >= m){
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
                }
        }return ans;
        
    }
};