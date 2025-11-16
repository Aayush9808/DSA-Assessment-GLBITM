#include <vector>
#include <unordered_set>
using namespace std;

vector<int> findUnion(vector<int>& arr1, vector<int>& arr2) {
    unordered_set<int> s;
    for(int num : arr1) s.insert(num);
    for(int num : arr2) s.insert(num);
    return vector<int>(s.begin(), s.end());
}

vector<int> findIntersection(vector<int>& arr1, vector<int>& arr2) {
    unordered_set<int> s(arr1.begin(), arr1.end());
    vector<int> result;
    for(int num : arr2) {
        if(s.count(num)) {
            result.push_back(num);
            s.erase(num);
        }
    }
    return result;
}
