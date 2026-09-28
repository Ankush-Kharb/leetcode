/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int calculate(TreeNode* root, unordered_map<int,int>& freq, int& maxFreq) {
        if (root == NULL) {
            return 0;
        }

        int lSum = calculate(root->left, freq, maxFreq);
        int rSum = calculate(root->right, freq, maxFreq);

        int sum = lSum + rSum + root->val;   
        freq[sum]++;                         
        maxFreq = max(maxFreq, freq[sum]);  

        return sum;
    }

    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int,int> freq;
        int maxFreq = 0;

        calculate(root, freq, maxFreq);

        vector<int> ans;
        for (auto& it : freq) {
            if (it.second == maxFreq) {
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};