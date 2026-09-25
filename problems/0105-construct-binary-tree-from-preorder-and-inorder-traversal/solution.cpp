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
TreeNode* create(vector<int>& preorder, vector<int>& inorder) {
    if (preorder.size() == 0 || inorder.size() == 0)
        return NULL;

    TreeNode* root = new TreeNode(preorder[0]);

    int i = 0;
    for (; i < inorder.size(); i++) {
        if (inorder[i] == preorder[0])
            break;
    }


    vector<int> leftIn(inorder.begin(), inorder.begin() + i);
    vector<int> leftPre(preorder.begin() + 1, preorder.begin() + 1 + i);


    vector<int> rightIn(inorder.begin() + i + 1, inorder.end());
    vector<int> rightPre(preorder.begin() + 1 + i, preorder.end());

    root->left = create(leftPre, leftIn);
    root->right = create(rightPre, rightIn);

    return root;
}
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return create( preorder, inorder);
    }
};