#include <stack>

class MyQueue {
private:
    std::stack<int> s1; // For pushing elements
    std::stack<int> s2; // For popping/peeking elements

    // Helper function to transfer elements from s1 to s2 when s2 is empty
    void transferIfNeeded() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
    }

public:
    MyQueue() {}
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        transferIfNeeded();
        int frontElement = s2.top();
        s2.pop();
        return frontElement;
    }
    
    int peek() {
        transferIfNeeded();
        return s2.top();
    }
    
    bool empty() {
        return s1.empty() && s2.empty();
    }
};
