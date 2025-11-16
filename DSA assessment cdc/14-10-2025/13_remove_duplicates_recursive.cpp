#include <string>
using namespace std;

string removeDuplicatesRecursive(string s, int i = 0) {
    if(i >= s.length()) return "";
    
    char current = s[i];
    string rest = removeDuplicatesRecursive(s, i + 1);
    
    if(rest.empty() || rest[0] != current) {
        return current + rest;
    }
    return rest;
}
