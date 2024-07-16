int minimumSubsetXOR(vector<int>& arr, int n) {
    // Find the minimum XOR of any pair of elements in array arr
    int minSubsetXor = INT_MAX;
    for (int mask = 0; mask < (1 << n); ++mask) {
        int xorSum = 0;
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                xorSum ^= arr[i];
            }
        }
        minSubsetXor = min(minSubsetXor, xorSum);
    }
    return minSubsetXor;
}
