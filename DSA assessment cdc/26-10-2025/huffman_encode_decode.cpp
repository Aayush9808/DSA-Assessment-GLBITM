#include <queue>
#include <unordered_map>
#include <string>
using namespace std;

struct HuffmanNode {
    char data;
    int freq;
    HuffmanNode *left, *right;
    
    HuffmanNode(char data, int freq) {
        this->data = data;
        this->freq = freq;
        left = right = nullptr;
    }
};

struct Compare {
    bool operator()(HuffmanNode* a, HuffmanNode* b) {
        return a->freq > b->freq;
    }
};

void generateCodes(HuffmanNode* root, string code, unordered_map<char, string>& codes) {
    if(!root) return;
    
    if(!root->left && !root->right) {
        codes[root->data] = code;
    }
    
    generateCodes(root->left, code + "0", codes);
    generateCodes(root->right, code + "1", codes);
}

unordered_map<char, string> huffmanCoding(string text) {
    unordered_map<char, int> freq;
    for(char c : text) freq[c]++;
    
    priority_queue<HuffmanNode*, vector<HuffmanNode*>, Compare> pq;
    
    for(auto& p : freq) {
        pq.push(new HuffmanNode(p.first, p.second));
    }
    
    while(pq.size() > 1) {
        HuffmanNode* left = pq.top(); pq.pop();
        HuffmanNode* right = pq.top(); pq.pop();
        
        HuffmanNode* parent = new HuffmanNode('$', left->freq + right->freq);
        parent->left = left;
        parent->right = right;
        
        pq.push(parent);
    }
    
    unordered_map<char, string> codes;
    generateCodes(pq.top(), "", codes);
    return codes;
}

string huffmanEncode(string text, unordered_map<char, string>& codes) {
    string encoded = "";
    for(char c : text) {
        encoded += codes[c];
    }
    return encoded;
}

string huffmanDecode(string encoded, HuffmanNode* root) {
    string decoded = "";
    HuffmanNode* curr = root;
    
    for(char bit : encoded) {
        if(bit == '0') curr = curr->left;
        else curr = curr->right;
        
        if(!curr->left && !curr->right) {
            decoded += curr->data;
            curr = root;
        }
    }
    return decoded;
}
