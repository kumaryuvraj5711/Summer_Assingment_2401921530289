class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        // Loop until the node is found or root becomes null
        while (root != nullptr && root->val != val) {
            if (val < root->val) {
                root = root->left;  // Search left subtree
            } else {
                root = root->right; // Search right subtree
            }
        }
        return root;
    }
};
