class Solution {
public:
    void traverse(TreeNode* root, vector<int>& result) {
        if (root == nullptr) return;
        
        traverse(root->left, result);  // Visit left subtree
        result.push_back(root->val);   // Visit root node
        traverse(root->right, result); // Visit right subtree
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        traverse(root, result);
        return result;
    }
};
