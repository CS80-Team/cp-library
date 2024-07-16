void subsetSumCheck(vector<int>& arr, int n, int k) {
    // Check if a subset of elements in array arr sums up to k
    for (int subset = 0; subset < (1 << n); ++subset) {
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            if (subset & (1 << i)) {
                sum += arr[i];
            }
        }
        if (sum == k) {
            // Found subset with sum k
            cout << "Subset with sum " << k << ": " << subset << endl;
        }
    }
}
