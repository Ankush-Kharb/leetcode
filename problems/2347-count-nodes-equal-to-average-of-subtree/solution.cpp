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
    
    int ans = 0;
    pair<int,int> f(TreeNode* node){
        if(node == NULL){
            return {0,0};
        }
        auto left = f(node->left);
        auto right = f(node->right);
        
        int sum = node->val + left.first + right.first;
        int elements = 1+ left.second + right.second;
        if(sum /elements == node->val)ans++;
        return {sum , elements};
    }
    int averageOfSubtree(TreeNode* root) {
        

        f(root);
        return ans;
    }
};