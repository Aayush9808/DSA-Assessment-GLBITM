#include <vector>
using namespace std;

long long factorial(int n) {
    long long result = 1;
    for(int i = 2; i <= n; i++) result *= i;
    return result;
}

long long nPr(int n, int r) {
    long long result = 1;
    for(int i = 0; i < r; i++) {
        result *= (n - i);
    }
    return result;
}

long long nCr(int n, int r) {
    return nPr(n, r) / factorial(r);
}

vector<int> catalanNumbers(int n) {
    vector<int> catalan(n + 1);
    catalan[0] = catalan[1] = 1;
    
    for(int i = 2; i <= n; i++) {
        for(int j = 0; j < i; j++) {
            catalan[i] += catalan[j] * catalan[i - j - 1];
        }
    }
    return catalan;
}
