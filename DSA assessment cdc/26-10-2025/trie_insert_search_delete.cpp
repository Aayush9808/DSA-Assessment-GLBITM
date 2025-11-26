#include <string>
#include <unordered_map>
using namespace std;

struct TrieNode {
    unordered_map<char, TrieNode*> children;
    bool isEndOfWord;
    
    TrieNode() {
        isEndOfWord = false;
    }
};

class Trie {
    TrieNode* root;
    
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr = root;
        for(char c : word) {
            if(!curr->children.count(c)) {
                curr->children[c] = new TrieNode();
            }
            curr = curr->children[c];
        }
        curr->isEndOfWord = true;
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        for(char c : word) {
            if(!curr->children.count(c)) return false;
            curr = curr->children[c];
        }
        return curr->isEndOfWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for(char c : prefix) {
            if(!curr->children.count(c)) return false;
            curr = curr->children[c];
        }
        return true;
    }
    
    void deleteWord(string word) {
        deleteHelper(root, word, 0);
    }
    
    bool deleteHelper(TrieNode* node, string& word, int index) {
        if(index == word.length()) {
            if(!node->isEndOfWord) return false;
            node->isEndOfWord = false;
            return node->children.empty();
        }
        
        char c = word[index];
        if(!node->children.count(c)) return false;
        
        TrieNode* child = node->children[c];
        bool shouldDeleteChild = deleteHelper(child, word, index + 1);
        
        if(shouldDeleteChild) {
            node->children.erase(c);
            return node->children.empty() && !node->isEndOfWord;
        }
        return false;
    }
};
