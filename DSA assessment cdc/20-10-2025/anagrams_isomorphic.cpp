#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> findAnagrams(string s, vector<string>& dict) {
    vector<string> result;
    for(string word : dict) {
        string sortedS = s, sortedWord = word;
        sort(sortedS.begin(), sortedS.end());
        sort(sortedWord.begin(), sortedWord.end());
        if(sortedS == sortedWord) result.push_back(word);
    }
    return result;
}

bool isIsomorphic(string s, string t) {
    if(s.length() != t.length()) return false;
    unordered_map<char, char> mapS, mapT;
    
    for(int i = 0; i < s.length(); i++) {
        if(mapS.count(s[i]) && mapS[s[i]] != t[i]) return false;
        if(mapT.count(t[i]) && mapT[t[i]] != s[i]) return false;
        mapS[s[i]] = t[i];
        mapT[t[i]] = s[i];
    }
    return true;
}
