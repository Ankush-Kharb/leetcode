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
    int maxSUM(TreeNode* root , int & maxi){
        if(root == NULL)return 0;

        int leftSUM = max(0,maxSUM(root->left , maxi));
        int rightSUM = max(0, maxSUM(root->right, maxi));


        maxi = max(maxi , leftSUM + rightSUM +root->val);
        return (root->val) + max(leftSUM , rightSUM);
    }
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        maxSUM(root , maxi);
        return maxi;
    }
};