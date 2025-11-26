#include <string>
using namespace std;

string removeNonAlphabet(string s) {
    string result = "";
    for(char c : s) {
        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            result += c;
        }
    }
    return result;
}
