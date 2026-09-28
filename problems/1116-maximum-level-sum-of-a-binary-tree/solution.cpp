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
    int maxLevelSum(TreeNode* root) {
        if (root == NULL)return 0;
        queue<TreeNode*> q;
        int maxi = INT_MIN;
        int level = 0;
        int count = 0;
        q.push(root);
        while(!q.empty()){
            int n= q.size();
            int sum = 0;
            count++;
            for(int i = 0;i<n;i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
                sum+= node->val;
                
            }
            if(sum > maxi){
                level = count;
                maxi = sum;
            }

        }
        return level;
    }
};