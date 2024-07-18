// REF: USACO guide

/** @return nCk mod p using dynamic programming */
int binomial(int n, int k, int p) {
	// dp[i][j] stores iCj
	vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

	// base cases described above
	for (int i = 0; i <= n; i++) {
		/*
		 * i choose 0 is always 1 since there is exactly one way
		 * to choose 0 elements from a set of i elements
		 * (don't choose anything)
		 */
		dp[i][0] = 1;
		/*
		 * i choose i is always 1 since there is exactly one way
		 * to choose i elements from a set of i elements
		 * (choose every element in the set)
		 */
		if (i <= k) { dp[i][i] = 1; }
	}

	for (int i = 0; i <= n; i++) {
		for (int j = 1; j <= min(i, k); j++) {
			if (i != j) {  // skips over the base cases
				// uses the recurrence relation above
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % p;
			}
		}
	}

	return dp[n][k];  // returns nCk modulo p
}