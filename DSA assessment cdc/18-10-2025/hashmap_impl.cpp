#include <unordered_map>
#include <vector>
using namespace std;

class HashMapArray {
    vector<pair<int, int>> table[100];
public:
    void put(int key, int value) {
        int idx = key % 100;
        for(auto& p : table[idx]) {
            if(p.first == key) {
                p.second = value;
                return;
            }
        }
        table[idx].push_back({key, value});
    }
    
    int get(int key) {
        int idx = key % 100;
        for(auto& p : table[idx]) {
            if(p.first == key) return p.second;
        }
        return -1;
    }
    
    bool containsKey(int key) {
        int idx = key % 100;
        for(auto& p : table[idx]) {
            if(p.first == key) return true;
        }
        return false;
    }
};
