#include <stack>
#include <string>
using namespace std;

int smallerOnLeft(int arr[], int n, int i) {
    for(int j = i - 1; j >= 0; j--) {
        if(arr[j] < arr[i]) return arr[j];
    }
    return -1;
}

bool isValid(string s) {
    stack<char> st;
    for(char c : s) {
        if(c == '(' || c == '{' || c == '[') {
            st.push(c);
        } else {
            if(st.empty()) return false;
            char top = st.top();
            if((c == ')' && top == '(') || 
               (c == '}' && top == '{') || 
               (c == ']' && top == '[')) {
                st.pop();
            } else {
                return false;
            }
        }
    }
    return st.empty();
}

int evaluatePostfix(string exp) {
    stack<int> st;
    for(char c : exp) {
        if(isdigit(c)) {
            st.push(c - '0');
        } else {
            int val2 = st.top(); st.pop();
            int val1 = st.top(); st.pop();
            switch(c) {
                case '+': st.push(val1 + val2); break;
                case '-': st.push(val1 - val2); break;
                case '*': st.push(val1 * val2); break;
                case '/': st.push(val1 / val2); break;
            }
        }
    }
    return st.top();
}
