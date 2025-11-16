#include <string>
using namespace std;

int countWords(string s) {
    int count = 0;
    bool inWord = false;
    
    for(char c : s) {
        if(c == ' ') {
            inWord = false;
        } else if(!inWord) {
            inWord = true;
            count++;
        }
    }
    return count;
}
