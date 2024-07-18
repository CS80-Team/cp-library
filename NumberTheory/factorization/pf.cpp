void factorize(int x, unordered_map<int, int>& factors) {
    while (x % 2 == 0) {
        factors[2]++;
        x /= 2;
    }
    for (int i = 3; i * i <= x; i += 2) {
        while (x % i == 0) {
            factors[i]++;
            x /= i;
        }
    }
    if (x > 2) factors[x]++;
}
