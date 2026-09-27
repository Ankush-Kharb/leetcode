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
    bool check(TreeNode* root, vector<int>& ans, int index) {
        if (root == NULL) {
            return true;
        }

        if (index >= ans.size()) {
            return false;
        }

        return check(root->left, ans, 2 * index + 1) &&
               check(root->right, ans, 2 * index + 2);
    }
    vector<int> level(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> ans;
        if (root == NULL) {
            return ans;
        }
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left != NULL) {
                    q.push(node->left);
                }
                if (node->right != NULL) {
                    q.push(node->right);
                }
                ans.push_back(node->val);
            }
        }
        return ans;
    }
    bool isCompleteTree(TreeNode* root) {
        vector<int> ans;
        ans = level(root);
        int index = 0;
        return check(root, ans, index);
    }
};