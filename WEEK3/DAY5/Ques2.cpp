#include <queue>

class RecentCounter {
private:
    std::queue<int> requests;

public:
    RecentCounter() {
        // Initializes the counter with zero recent requests.
    }
    
    int ping(int t) {
        // Add the current request time to the queue
        requests.push(t);
        
        // Remove requests that fall outside the [t - 3000, t] window
        while (!requests.empty() && requests.front() < t - 3000) {
            requests.pop();
        }
        
        // The size of the queue represents the number of recent calls
        return requests.size();
    }
};
