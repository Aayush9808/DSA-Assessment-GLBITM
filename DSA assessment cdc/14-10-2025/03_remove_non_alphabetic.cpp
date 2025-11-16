#include <string>
using namespace std;

string removeNonAlphabetic(string s) {
    string result = "";
    for(char c : s) {
        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            result += c;
        }
    }
    return result;
}
