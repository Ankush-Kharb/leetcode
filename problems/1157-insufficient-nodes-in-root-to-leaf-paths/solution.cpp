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
    TreeNode* f(TreeNode* node, int limit, int sum) {
        if (node == NULL)
            return NULL;
        if (node->left == NULL && node->right == NULL) {
            if (sum < limit) {
                return NULL;
            }
            return node;
        }
        node->left =
            f(node->left, limit, sum + (node->left ? node->left->val : 0));
        node->right =
            f(node->right, limit, sum + (node->right ? node->right->val : 0));
        if (node->left == NULL && node->right == NULL)
            return NULL;
        return node;
    }
    TreeNode* sufficientSubset(TreeNode* root, int limit) {

        return f(root, limit, root->val);
    }
};