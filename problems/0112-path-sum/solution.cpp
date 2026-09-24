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
    bool SUM(TreeNode* root, int targetSum, int sum) {
        if (root == NULL) {
            return false;
        }

        sum = sum + root->val;

        // leaf node
        if (root->left == NULL && root->right == NULL) {
            return sum == targetSum;
        }

        return SUM(root->left, targetSum, sum) ||
               SUM(root->right, targetSum, sum);
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == NULL) {
            return false;
        }
        return SUM(root, targetSum, 0);
    }
};