/* 
For example, if the coins are \{2,3,5\} and the desired sum is 9, there are 3 ways:

2+2+5
3+3+3
2+2+2+3
*/
int n, x;
cin >> n >> x;
vector<int> coins(n);
read(coins);

vector dp(x + 1, 0);

dp[0] = 1;
for (int i = 0; i < n; ++i) {
	for (int j = coins[i]; j <= x; ++j) {
		dp[j] = add(dp[j], dp[j - coins[i]]);
	}
}
 
cout << dp[x] << el;
