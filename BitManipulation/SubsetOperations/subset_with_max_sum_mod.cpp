int subsetWithMaxSumModuloM(vector<int>& arr, int n, int m) {
    // Find the maximum subset sum modulo m
    vector<int> dp(m, -1);
    dp[0] = 0;
    int currentMod = 0;
    for (int i = 0; i < n; ++i) {
        currentMod = (currentMod + arr[i]) % m;
        for (int j = 0; j < m; ++j) {
            if (dp[j] != -1) {
                dp[(j + currentMod) % m] = max(dp[(j + currentMod) % m], dp[j] + arr[i]);
            }
        }
        dp[currentMod] = max(dp[currentMod], arr[i]);
    }
    return dp[0]; // Maximum subset sum modulo m
}
