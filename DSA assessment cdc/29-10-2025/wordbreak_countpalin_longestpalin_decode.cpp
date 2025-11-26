#include <vector>
#include <string>
using namespace std;

bool wordBreak(string s, vector<string>& wordDict) {
    int n = s.length();
    vector<bool> dp(n + 1, false);
    dp[0] = true;
    
    for(int i = 1; i <= n; i++) {
        for(string& word : wordDict) {
            int len = word.length();
            if(i >= len && dp[i - len] && s.substr(i - len, len) == word) {
                dp[i] = true;
                break;
            }
        }
    }
    return dp[n];
}

int countPalindromicSubstrings(string s) {
    int n = s.length();
    vector<vector<bool>> dp(n, vector<bool>(n, false));
    int count = 0;
    
    for(int i = 0; i < n; i++) {
        dp[i][i] = true;
        count++;
    }
    
    for(int i = 0; i < n - 1; i++) {
        if(s[i] == s[i+1]) {
            dp[i][i+1] = true;
            count++;
        }
    }
    
    for(int len = 3; len <= n; len++) {
        for(int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            if(s[i] == s[j] && dp[i+1][j-1]) {
                dp[i][j] = true;
                count++;
            }
        }
    }
    return count;
}

string longestPalindromicSubstring(string s) {
    int n = s.length();
    if(n == 0) return "";
    
    vector<vector<bool>> dp(n, vector<bool>(n, false));
    int maxLen = 1, start = 0;
    
    for(int i = 0; i < n; i++) dp[i][i] = true;
    
    for(int i = 0; i < n - 1; i++) {
        if(s[i] == s[i+1]) {
            dp[i][i+1] = true;
            start = i;
            maxLen = 2;
        }
    }
    
    for(int len = 3; len <= n; len++) {
        for(int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            if(s[i] == s[j] && dp[i+1][j-1]) {
                dp[i][j] = true;
                start = i;
                maxLen = len;
            }
        }
    }
    return s.substr(start, maxLen);
}

int numDecodings(string s) {
    int n = s.length();
    if(n == 0 || s[0] == '0') return 0;
    
    vector<int> dp(n + 1);
    dp[0] = 1;
    dp[1] = 1;
    
    for(int i = 2; i <= n; i++) {
        int oneDigit = stoi(s.substr(i-1, 1));
        int twoDigits = stoi(s.substr(i-2, 2));
        
        if(oneDigit >= 1) dp[i] += dp[i-1];
        if(twoDigits >= 10 && twoDigits <= 26) dp[i] += dp[i-2];
    }
    return dp[n];
}
