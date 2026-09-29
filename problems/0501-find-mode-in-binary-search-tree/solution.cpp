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
    void dfs(TreeNode* root, unordered_map<int,int>& freq, int& maxFreq) {
        if (root == NULL) return;

        freq[root->val]++;
        maxFreq = max(maxFreq, freq[root->val]);

        dfs(root->left, freq, maxFreq);
        dfs(root->right, freq, maxFreq);
    }

    vector<int> findMode(TreeNode* root) {
        unordered_map<int,int> freq;
        int maxFreq = 0;

        dfs(root, freq, maxFreq);

        vector<int> ans;
        for (auto &it : freq) {
            if (it.second == maxFreq) {
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};