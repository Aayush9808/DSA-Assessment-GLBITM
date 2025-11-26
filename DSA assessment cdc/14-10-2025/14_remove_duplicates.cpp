#include <string>
using namespace std;

string removeDuplicates(string s, int i = 0) {
    if(i >= s.length() - 1) return s;
    if(s[i] == s[i+1]) {
        s.erase(i, 1);
        return removeDuplicates(s, i);
    }
    return removeDuplicates(s, i + 1);
}
