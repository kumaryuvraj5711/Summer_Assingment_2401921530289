#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == nullptr) {
            return result;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            int levelSize = q.size();
            vector<int> currentLevel;
            
            // Process all nodes at the current level
            for (int i = 0; i < levelSize; i++) {
                TreeNode* currentNode = q.front();
                q.pop();
                
                currentLevel.push_back(currentNode->val);
                
                // Push left child if it exists
                if (currentNode->left != nullptr) {
                    q.push(currentNode->left);
                }
                // Push right child if it exists
                if (currentNode->right != nullptr) {
                    q.push(currentNode->right);
                }
            }
            
            // Add the current level's values to the final result
            result.push_back(currentLevel);
        }
        
        return result;
    }
};
