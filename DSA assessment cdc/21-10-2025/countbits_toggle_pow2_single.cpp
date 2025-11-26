int countSetBits(int n) {
    int count = 0;
    while(n) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

int toggleBit(int n, int k) {
    return n ^ (1 << k);
}

bool checkPowerOfTwo(int n) {
    return n > 0 && (n & (n - 1)) == 0;
}

int singleNumber(int arr[], int n) {
    int result = 0;
    for(int i = 0; i < n; i++) {
        result ^= arr[i];
    }
    return result;
}
