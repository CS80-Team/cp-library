int d(int n){
    unordered_map<int, int> factors = pf(n);
    int c = 1;
    for(const auto& factor: factors){
        c *= (factor.second+1);
    }
    return c;
}


// range Count Divisors backward thinking MAXN = 2e6
  for(int i=1; i <= n; ++i) {
    for(int j = i; j <= n; j += i) {
      numFactors[j]++;
    }
  }

int countDivisors(int n) {
  int count = 0;
  for (int i = 1; i * i <= n; ++i) {
    if (n % i == 0) {
        if (i == n / i) {
              count++; // Perfect square
        } else {
              count += 2; // Pair of divisors
        }
    }
  }
    return count;
}
