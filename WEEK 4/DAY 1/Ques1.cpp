

class Solution {
public:
    int maxDepth(TreeNode* root) {

        // Base case
        if (root == NULL)
            return 0;

        // Find depth of left subtree
        int left = maxDepth(root->left);

        // Find depth of right subtree
        int right = maxDepth(root->right);

        // Return maximum depth
        return max(left, right) + 1;
    }
};
