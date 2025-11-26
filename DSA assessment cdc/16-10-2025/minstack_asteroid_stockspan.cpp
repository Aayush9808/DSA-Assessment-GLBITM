#include <stack>
#include <vector>
using namespace std;

class MinStack {
    stack<int> st;
    stack<int> minSt;
public:
    void push(int x) {
        st.push(x);
        if(minSt.empty() || x <= minSt.top()) {
            minSt.push(x);
        }
    }
    
    void pop() {
        if(st.top() == minSt.top()) {
            minSt.pop();
        }
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minSt.top();
    }
};

vector<int> asteroidCollision(vector<int>& asteroids) {
    stack<int> st;
    for(int ast : asteroids) {
        bool alive = true;
        while(alive && ast < 0 && !st.empty() && st.top() > 0) {
            if(st.top() < -ast) {
                st.pop();
                continue;
            } else if(st.top() == -ast) {
                st.pop();
            }
            alive = false;
        }
        if(alive) st.push(ast);
    }
    
    vector<int> result(st.size());
    for(int i = st.size()-1; i >= 0; i--) {
        result[i] = st.top();
        st.pop();
    }
    return result;
}

vector<int> stockSpan(vector<int>& prices) {
    vector<int> span(prices.size());
    stack<int> st;
    
    for(int i = 0; i < prices.size(); i++) {
        while(!st.empty() && prices[st.top()] <= prices[i]) {
            st.pop();
        }
        span[i] = st.empty() ? i + 1 : i - st.top();
        st.push(i);
    }
    return span;
}
