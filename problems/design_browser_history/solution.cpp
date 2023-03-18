class BrowserHistory {
public:
    stack<string> history;
    stack<string> future;
	
    BrowserHistory(string homepage) {
        history.push(homepage);
        future = stack<string>(); // Reset as can't go forward now
    }
    
    void visit(string url) {
        history.push(url);
        future = stack<string>(); // Reset as can't go forward now
    }
    
    string back(int steps) {
        while(steps > 0 && history.size() > 1) { // As we can only move x steps & stesp>x then we return only x steps
            future.push(history.top());
            history.pop();
            steps--;
        }
        return history.top();
    }
    
    string forward(int steps) {
        while(steps > 0 && future.size() > 0) {
            history.push(future.top());
            future.pop();
            steps--;
        }
        return history.top();
    }
};