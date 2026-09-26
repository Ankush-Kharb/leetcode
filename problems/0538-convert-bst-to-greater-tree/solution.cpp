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
TreeNode* dfs(TreeNode* root ,int &sum ){
    if(root == NULL){
        return NULL;
    }

    root->right = dfs(root->right ,sum);
    sum = sum + root->val;
    root->val = sum;
    root->left = dfs(root->left,sum);
    cout<<sum<<endl;
    return root;
     
}
    TreeNode* convertBST(TreeNode* root) {
        int sum  = 0;
        

        return dfs(root,sum);
    }
};