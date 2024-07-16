int maximalSubsetXOR(vector<int>& arr, int n) {
    // Find the maximum XOR of any subset of elements in array arr
    int maxXor = 0;
    for (int mask = 0; mask < (1 << n); ++mask) {
        int xorSum = 0;
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                xorSum ^= arr[i];
            }
        }
        maxXor = max(maxXor, xorSum);
    }
    return maxXor;
}
