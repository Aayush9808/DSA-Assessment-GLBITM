int gcd(int a, int b) {
    while(b) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

bool isPrime(int n) {
    if(n <= 1) return false;
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) return false;
    }
    return true;
}

int modularExponentiation(int base, int exp, int mod) {
    int result = 1;
    base %= mod;
    while(exp > 0) {
        if(exp & 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return result;
}

int chineseRemainder(int num[], int rem[], int k) {
    int prod = 1;
    for(int i = 0; i < k; i++) prod *= num[i];
    
    int result = 0;
    for(int i = 0; i < k; i++) {
        int pp = prod / num[i];
        result += rem[i] * pp * modInverse(pp, num[i]);
    }
    return result % prod;
}

int modInverse(int a, int m) {
    return modularExponentiation(a, m - 2, m);
}
