#include <string>
#include <unordered_map>
using namespace std;

int calculateFrequency(string s, char c) {
    int count = 0;
    for(char ch : s) {
        if(ch == c) count++;
    }
    return count;
}
