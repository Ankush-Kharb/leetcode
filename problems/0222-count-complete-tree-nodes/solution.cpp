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
    int leftHeight(TreeNode* root ) {
        TreeNode* temp = root;
        int count = 0;
        while(temp != NULL){
            count++;
            temp = temp->left;
        }
        return count;
    }
    int rightHeight(TreeNode* root){
        TreeNode* temp = root;
        int count = 0;
        while(temp != NULL){
            count++;
            temp = temp -> right;
        }
        return count;
    }
    int countNodes(TreeNode* root) {
        int lh = leftHeight(root);
        int rh = rightHeight(root);
        if(lh == rh){
            return pow(2,lh)-1;
        }
        return 1 + countNodes(root->left) + countNodes(root->right);
        
    }
};