#include <string>
using namespace std;

void countVowelConsonant(string s, int& vowels, int& consonants) {
    vowels = 0;
    consonants = 0;
    for(char c : s) {
        char lower = tolower(c);
        if(lower >= 'a' && lower <= 'z') {
            if(lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u') {
                vowels++;
            } else {
                consonants++;
            }
        }
    }
}
