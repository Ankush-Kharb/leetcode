/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void pathHere(TreeNode* root, int& targetSum, vector<vector<int>>& ans,
              int& sum, vector<int>& path) {
        if (root == NULL) {
            return;
        }
        sum = sum + root->val;
        path.push_back(root->val);
        if (root->left == NULL && root->right == NULL) {
            if (sum == targetSum) {
                ans.push_back(path);
            }
            sum -= root->val;
            path.pop_back();
            return;
        }
        pathHere(root->left, targetSum, ans, sum, path);
        pathHere(root->right, targetSum, ans, sum, path);
        sum -= root->val;
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> path;
        int sum = 0;
        pathHere(root, targetSum, ans, sum, path);
        return ans;
    }
};