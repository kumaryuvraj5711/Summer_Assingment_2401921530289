#include <queue>

class RecentCounter {
private:
    std::queue<int> requests;

public:
    RecentCounter() {
        // Initializes the counter with zero recent requests
    }
    
    int ping(int t) {
        // Add the current timestamp to the queue
        requests.push(t);
        
        // Remove timestamps that are outside the [t - 3000, t] range
        while (!requests.empty() && requests.front() < t - 3000) {
            requests.pop();
        }
        
        // The remaining elements are the valid requests in the time frame
        return requests.size();
    }
};
