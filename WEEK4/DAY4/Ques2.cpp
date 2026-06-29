#include <vector>
#include <string>
#include <stack>

class Solution {
public:
    int evalRPN(std::vector<std::string>& tokens) {
        std::stack<int> st;
        
        for (const std::string& token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                // Pop the top two operands
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();
                
                // Perform the operation and push result
                if (token == "+") st.push(a + b);
                else if (token == "-") st.push(a - b);
                else if (token == "*") st.push(a * b);
                else if (token == "/") st.push(a / b); // C++ integer division naturally truncates toward zero
            } else {
                // Token is a number, convert and push to stack
                st.push(std::stoi(token));
            }
        }
        
        return st.top();
    }
};
