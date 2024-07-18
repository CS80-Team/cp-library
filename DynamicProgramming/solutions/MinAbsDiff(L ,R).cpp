const int N = 1e4 + 1;
 
int dp[N][N];

int n;
cin >> n;
vector<int> a(n);
read(a);

for (int i = 0; i < n; ++i) dp[i][i] = 1e6; // INF, you can't take the element with it self
for (int i = 1; i < n; ++i) dp[i - 1][i] = abs(a[i] - a[i - 1]);

for (int len = 3; len <= n; ++len) {
	for (int l = 0, r = len - 1; r < n; ++l, ++r) {
		dp[l][r] = min(dp[l][r - 1], dp[l + 1][r]);
		dp[l][r] = min(dp[l][r], abs(a[l] - a[r]));
	}
}

int q;
cin >> q;
while (q--) {
	int l, r;
	cin >> l >> r;
	--l, --r;

	cout << dp[l][r] << el;
}