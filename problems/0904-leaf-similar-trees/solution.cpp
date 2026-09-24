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
    void leafArr(TreeNode* root , vector<int> &ans) {
       
        if(root == NULL){
            return ;
        }
        else if(root->left == NULL && root->right == NULL){
            ans.push_back(root->val);
            return;
        }
        else {
            leafArr(root->left , ans);
            leafArr(root ->right , ans);
        }


    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> ans1 ;
        leafArr(root1 , ans1);
        vector<int> ans2 ;
        leafArr(root2 , ans2);

        if(ans1.size() != ans2.size()){
            return false;
        }
        for(int i = 0; i<ans1.size();i++){
            if(ans1[i] != ans2[i]){
                return false;
            }
        }
        return true;
    }
};