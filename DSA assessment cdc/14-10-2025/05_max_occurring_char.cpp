#include <string>
#include <unordered_map>
using namespace std;

char maxOccurringChar(string s) {
    unordered_map<char, int> freq;
    int maxFreq = 0;
    char result = s[0];
    
    for(char c : s) {
        freq[c]++;
        if(freq[c] > maxFreq) {
            maxFreq = freq[c];
            result = c;
        }
    }
    return result;
}
