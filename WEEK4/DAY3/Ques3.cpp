#include <vector>
#include <unordered_map>
#include <stack>

class Solution {
public:
    std::vector<int> nextGreaterElement(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::unordered_map<int, int> next_greater;
        std::stack<int> st;

        // Traverse nums2 to find the next greater element for every number
        for (int num : nums2) {
            // While stack is not empty and current number is greater than the stack's top
            while (!st.empty() && st.top() < num) {
                next_greater[st.top()] = num;
                st.pop();
            }
            st.push(num);
        }

        // Build the result array for nums1
        std::vector<int> ans;
        for (int num : nums1) {
            if (next_greater.count(num)) {
                ans.push_back(next_greater[num]);
            } else {
                ans.push_back(-1); // No greater element found to the right
            }
        }

        return ans;
    }
};
