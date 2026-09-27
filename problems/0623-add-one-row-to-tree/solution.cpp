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
    void create(TreeNode* root, int val, int depth, int& count) {
        if (root == NULL) {
            return;
        }

        if (count == depth - 1) {
            if (root->left != NULL) {
                TreeNode* temp1 = root->left;
                root->left = new TreeNode(val);
                root->left->left = temp1;
            }
            if (root->right != NULL) {
                TreeNode* temp2 = root->right;
                root->right = new TreeNode(val);
                root->right->right = temp2;
            }
            if(root->left == NULL){
                TreeNode* temp1 = root->left;
                root->left = new TreeNode(val);
            }
            if(root->right == NULL){
                TreeNode* temp2 = root->right;
                root->right = new TreeNode(val);
            }
            return;
        }
        count++;
        create(root->left, val, depth, count);
        create(root->right, val, depth, count);
        count--;
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            TreeNode* temp = new TreeNode(val);
            temp->left = root;
            return temp;
        }
        int count = 1;
        create(root, val, depth, count);
        return root;
    }
};