int countDistinctSubsetsWithSum(vector<int>& arr, int n, int k) {
    // Count distinct subsets of array arr that sum up to k
    vector<int> dp(k + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = k; j >= arr[i]; --j) {
            dp[j] += dp[j - arr[i]];
        }
    }
    return dp[k]; // Number of distinct subsets with sum k
}
