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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        if(root == NULL)return ans;
        q.push(root);
        bool L_to_R = true;   //If left to right itration is true
        while(!q.empty()){
            int size = q.size();
            vector<int>level(size); // Here we have to tell the size if the level vector
           
            for(int i = 0 ; i<size ; i++){ 
                TreeNode * node = q.front();
                q.pop();
                int index = (L_to_R) ? i : (size -1 - i);
                if(node->left != NULL) q.push(node->left);
                if(node->right != NULL) q.push(node ->right);

                level[index] = node->val;

            }
            L_to_R = !L_to_R;
            ans.push_back(level);
        }
        return ans;
    }
};