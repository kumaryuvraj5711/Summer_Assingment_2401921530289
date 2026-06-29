class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> answer(n, 0);
        stack<int> st; // Stores indices
        
        for (int i = 0; i < n; ++i) {
            // Check if current temp is warmer than the stack top
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                int prevIndex = st.top();
                st.pop();
                answer[prevIndex] = i - prevIndex; // Calculate days to wait
            }
            st.push(i); // Push current day's index
        }
        
        return answer;
    }
};
