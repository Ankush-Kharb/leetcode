class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> bits;
        while(n!=0)
        {
            bits.push_back(n&1);
            n = n/2;
        }
        // reverse(bits.begin(),bits.end());

        vector<int> powers;

        long long int num = 1;
        for(int i = 0;i<bits.size();i++)
        {
            if(bits[i]) powers.push_back(num);
            num = num*2;
        }
        vector<int> ans;

        for(int i = 0;i<queries.size();i++)
        {
            int s = queries[i][0];
            int e = queries[i][1];

            long long int temp = 1;

            for(int i = s;i<=e;i++)
            {
                temp = ((temp% 1000000007) * (powers[i]% 1000000007)) % 1000000007;
            }

            ans.push_back(temp);
        }

        return ans;
    }
};