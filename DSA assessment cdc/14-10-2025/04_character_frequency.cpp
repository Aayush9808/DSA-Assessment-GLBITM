#include <string>
#include <unordered_map>
using namespace std;

int characterFrequency(string s, char ch) {
    int count = 0;
    for(char c : s) {
        if(c == ch) count++;
    }
    return count;
}
