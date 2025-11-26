#include <string>
#include <vector>
using namespace std;

class TrieNode {
public:
    TrieNode* children[26];
    bool isEnd;
    
    TrieNode() {
        isEnd = false;
        for(int i = 0; i < 26; i++) children[i] = nullptr;
    }
};

class WordDictionary {
    TrieNode* root;
    
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* curr = root;
        for(char c : word) {
            int idx = c - 'a';
            if(!curr->children[idx]) {
                curr->children[idx] = new TrieNode();
            }
            curr = curr->children[idx];
        }
        curr->isEnd = true;
    }
    
    bool searchPattern(string word) {
        return searchHelper(word, 0, root);
    }
    
    bool searchHelper(string& word, int index, TrieNode* node) {
        if(index == word.length()) return node->isEnd;
        
        char c = word[index];
        if(c == '.') {
            for(int i = 0; i < 26; i++) {
                if(node->children[i] && searchHelper(word, index + 1, node->children[i])) {
                    return true;
                }
            }
            return false;
        } else {
            int idx = c - 'a';
            if(!node->children[idx]) return false;
            return searchHelper(word, index + 1, node->children[idx]);
        }
    }
};

string longestCommonPrefix(vector<string>& strs) {
    if(strs.empty()) return "";
    
    TrieNode* root = new TrieNode();
    for(string& s : strs) {
        TrieNode* curr = root;
        for(char c : s) {
            int idx = c - 'a';
            if(!curr->children[idx]) {
                curr->children[idx] = new TrieNode();
            }
            curr = curr->children[idx];
        }
        curr->isEnd = true;
    }
    
    string prefix = "";
    TrieNode* curr = root;
    
    while(true) {
        int count = 0, nextIdx = -1;
        for(int i = 0; i < 26; i++) {
            if(curr->children[i]) {
                count++;
                nextIdx = i;
            }
        }
        
        if(count != 1 || curr->isEnd) break;
        prefix += char('a' + nextIdx);
        curr = curr->children[nextIdx];
    }
    
    return prefix;
}
