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
    int SUM(TreeNode* root, int val) {  
        if (root == NULL) {
            return 0;
        }

        val = val * 10 + root->val;     

        if (root->left == NULL && root->right == NULL) {
            return val;
        }

        int lSum = SUM(root->left, val);   
        int rSum = SUM(root->right, val);

        return lSum + rSum;
    }

    int sumNumbers(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        return SUM(root, 0);             
    }
};