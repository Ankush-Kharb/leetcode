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
    long long func(TreeNode* root, long long &maxi, long long totalSum) {
        if (root == NULL) return 0;

        long long lSum = func(root->left, maxi, totalSum);
        long long rSum = func(root->right, maxi, totalSum);

        long long currSum = root->val + lSum + rSum;

        maxi = max(maxi, currSum * (totalSum - currSum));

        return currSum;
    }

    int maxProduct(TreeNode* root) {
        long long maxi = 0;

        long long totalSum = func(root, maxi, 0);
        maxi = 0;
        func(root, maxi, totalSum);

        return maxi % 1000000007;
    }
};