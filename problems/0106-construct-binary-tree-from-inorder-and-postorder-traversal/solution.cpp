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
    TreeNode* create(vector<int>& inorder, vector<int>& postorder){
        if(inorder.size()==0 || postorder.size()==0){
            return nullptr;
        }
        TreeNode* root = new TreeNode (postorder[postorder.size()-1]);
        int i = 0;
        while(i<inorder.size()){
            if(inorder[i]==postorder[postorder.size()-1]){
                break;
            }
            i++;
        }
        vector<int> leftIn (inorder.begin(),inorder.begin()+i);
        vector<int> leftPo (postorder.begin(),postorder.begin()+i );

        vector<int> rightIn(inorder.begin()+i+1, inorder.end());
        vector<int> rightPo (postorder.begin()+i , postorder.end()-1);

        root->left = create(leftIn,leftPo);
        root->right= create(rightIn, rightPo);

        return root;

    }
     TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return create(inorder, postorder);
     }
};