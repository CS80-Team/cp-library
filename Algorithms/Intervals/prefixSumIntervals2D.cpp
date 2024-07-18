
// NOTE: works fine with small n or with large memory

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n + 1);
    vector<vector<int>> rangesPrefix(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    int l = 1, r = 1, sum = 0;
    // validate your intervals
    // here the intervals are the ones that have a sum of k
    while (r <= n) {
        sum += a[r];

        while (sum > k) {
            sum -= a[l];
            ++l;
        }

        while (l <= r && a[l] == 0) {
            if (sum != k)
                break;

            rangesPrefix[r][l]++;

            ++l;
        }

        if (sum == k) {
            rangesPrefix[r][l]++;
        }

        ++r;
    }


    // prefix sum the columns
    for (int i = 1; i <= n; ++i) {
        for (int j = n - 1; j >= 0; --j) {
            rangesPrefix[i][j] += rangesPrefix[i][j + 1];
        }
    }

    // prefix sum the rows
    for (int i = 0; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            rangesPrefix[j][i] += rangesPrefix[j - 1][i];
        }
    }

    int q; cin >> q;

    while (q--) {
        cin >> l >> r;
        // answer the number of intervals (X, Y) X <= Y that are included between L, R
        cout << rangesPrefix[r][l] - rangesPrefix[l - 1][l] << el;
    }
}