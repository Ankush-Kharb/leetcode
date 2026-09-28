/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void dfs(Node* root) {
        if (root == NULL) {
            return;
        }
        
        Node* temp1 = root->left;
        Node* temp2 = root->right;
        if(temp1 && temp2){
            temp1->next = temp2;
            temp2 -> next = root->next ? root->next->left : NULL;
        }
        dfs(root->left);
        dfs(root->right);
    }
    Node* connect(Node* root) {
        dfs(root);
        return root;
    }
};