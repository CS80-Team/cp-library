constexpr int MAX_N = 201, MOD = 1e9+7;
struct Matrix { int mat[MAX_N][MAX_N]; }; // we return a 2D array
ll mod(ll a, ll m) { return ((a%m)+m) % m; } // ensure positive answer
Matrix matMul(Matrix a, Matrix b) { // normally O(n^3)
    Matrix ans{}; // but O(1) as n = 2
    for (auto & i : ans.mat)
        for (int & j : i)
            j = 0;

    for (int i = 0; i < MAX_N; ++i)
        for (int k = 0; k < MAX_N; ++k) {
            if (a.mat[i][k] == 0) continue; // optimization
            for (int j = 0; j < MAX_N; ++j) {
                ans.mat[i][j] += mod(a.mat[i][k], MOD) * mod(b.mat[k][j], MOD);
                ans.mat[i][j] = mod(ans.mat[i][j], MOD);
            }
        }
    return ans;
}
Matrix matPow(Matrix base, int p) { // normally O(n^3 log p)
    Matrix ans{}; // but O(log p) as n = 2
    for (int i = 0; i < MAX_N; ++i)
        for (int j = 0; j < MAX_N; ++j)
            ans.mat[i][j] = (i == j); // prepare identity matrix
    while (p) { // iterative D&C version
        if (p&1) // check if p is odd
            ans = matMul(ans, base); // update ans
        base = matMul(base, base); // square the base
        p >>= 1; // divide p by 2
    }
    return ans;
}
Matrix matMul(Matrix a, Matrix b, int p, int q, int r) { // O(pqr)
    Matrix c{};
    for (int i = 0; i < p; ++i)
        for (int j = 0; j < r; ++j) {
            c.mat[i][j] = 0;
            for (int k = 0; k < q; ++k)
                c.mat[i][j] += a.mat[i][k] + b.mat[k][j];
        }
    return c;
}
