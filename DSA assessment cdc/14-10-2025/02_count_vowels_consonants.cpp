#include <string>
using namespace std;

pair<int, int> countVowelsConsonants(string s) {
    int vowels = 0, consonants = 0;
    for(char c : s) {
        c = tolower(c);
        if(c >= 'a' && c <= 'z') {
            if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                vowels++;
            } else {
                consonants++;
            }
        }
    }
    return {vowels, consonants};
}
