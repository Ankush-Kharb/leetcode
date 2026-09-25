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
    int widthOfBinaryTree(TreeNode* root) {
        if (root == NULL) return 0;

        queue<pair<TreeNode*, long long>> q;
        q.push(make_pair(root, 0));

        long long ans = 0;

        while (!q.empty()) {
            int size = q.size();
            long long first = q.front().second;
            long long last = q.back().second;

            ans = max(ans, last - first + 1);

            for (int i = 0; i < size; i++) {
                pair<TreeNode*, long long> temp = q.front();
                q.pop();

                TreeNode* node = temp.first;
                long long idx = temp.second - first; 

                if (node->left != NULL)
                    q.push(make_pair(node->left, 2 * idx + 1));

                if (node->right != NULL)
                    q.push(make_pair(node->right, 2 * idx + 2));
            }
        }
        return (int)ans;
    }
};