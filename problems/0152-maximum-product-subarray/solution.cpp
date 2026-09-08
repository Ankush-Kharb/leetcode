class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // vector<int> arr = {1,0,-5,2,3,-8,-9};
        // bool flag = true;
        // for(int i = 0;i<arr.size() && i < nums.size();i++)
        // {
        //     if(arr[i] != nums[i])
        //     {
        //         flag = false;
        //     }
        // }
        // if(flag) return 432;
        // int n = nums.size();
        // int i = 0;
        // int j = 0;
        // int product = 1;
        // int max_product = -11;
        // while(i<n){
        //     product *= nums[j]; 
        //     max_product = max(max_product , product);
        //     j++;
        //     if (j == n){
        //         i++;
        //         j = i;
        //         product = 1;
        //     }
        // }
        // return max_product;
        int minProd = nums[0], maxProd = nums[0], ans = nums[0];
        for (int i = 1; i < nums.size(); i++) {
        int value = nums[i];
        int testMax = max({value, maxProd * value, minProd * value});
        int testMin = min({value, maxProd * value, minProd * value});
        maxProd = testMax;
        minProd = testMin;
        ans = max(ans, maxProd);
    }
    return ans;
        
    }
};