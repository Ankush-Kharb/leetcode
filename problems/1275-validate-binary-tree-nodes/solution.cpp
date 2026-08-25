class Solution {
public:
    vector<int> parent;

    int find(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }
    bool UNION(int x, int y) {
        // x is the node y is from left or right child
        int xP = find(x);
        int yP = find(y);
        if (xP == yP)
            return false;
        else {
            parent[yP] = xP;
        }
        return true;
    }
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild,
                                 vector<int>& rightChild) {
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        vector<int> parentOf(n, -1);

        for (int i = 0; i < n; i++) {
            int left = leftChild[i];
            int right = rightChild[i];
            int leftP, rightP;
            if (left != -1) {
                if (parentOf[left] != -1)
                    return false;
                parentOf[left] = i;
                if (!UNION(i, left)) {
                    return false;
                }
            }
            if (right != -1) {
                if (parentOf[right] != -1)
                    return false;
                parentOf[right] = i;
                if (!UNION(i, right)) {
                    return false;
                }
            }
        }

        int roots = 0;
        for (int i = 0; i < n; i++) {
            if (parent[i] == i) {
                roots++;
            }
        }
        return (roots == 1);
    }
};