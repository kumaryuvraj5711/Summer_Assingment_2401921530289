
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return {};
        
        vector<vector<int>> result;
        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true;
        
        while (!q.empty()) {
            int size = q.size();
            vector<int> currentLevel(size);
            
            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();
                
                // Determine position based on current direction flag
                int index = leftToRight ? i : (size - 1 - i);
                currentLevel[index] = node->val;
                
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            
            // Switch direction for the next level
            leftToRight = !leftToRight;
            result.push_back(currentLevel);
        }
        
        return result;
    }
};
