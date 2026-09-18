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
    void order (TreeNode * root , vector<int> &ans){
        TreeNode * temp = root;

        if (temp == NULL){
            return ;
        }
        ans.push_back(temp-> val);
        order(temp -> left,ans);
        order(temp -> right,ans);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector <int> ans;
        order(root , ans);
        return ans;
    }
};