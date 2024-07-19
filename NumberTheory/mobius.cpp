int mobius(int n) {
    int p = 0;
    // Handling 2 separately
    if (n%2 == 0){
        n = n/2;
        p++;

        // If 2^2 also divides N
        if (n % 2 == 0)
           return 0;
    }

    // Check for all other prime factors
    for (int i = 3; i <= sqrt(n); i = i+2) {
        if (n%i == 0){
            n = n/i;
            p++;

            if (n % i == 0) return 0;
        }
    }

    return (p % 2 == 0)? -1 : 1;
}


void mobius_generator() const {
  const int MAX = 1000000;
  int moebius[MAX + 1];
  char prime[MAX + 1];

  for (ll i = 2; i <= MAX; i++)
    moebius[i] = -1, prime[i] = 1;

  for (ll i = 2; i <= MAX; ++i)
    if (prime[i]) {
      moebius[i] = 1;

      for (ll j = 2 * i; j <= MAX; j += i)
        prime[j] = 0, moebius[j] = j % (i * i) == 0 ? -moebius[j] : 1;
    }
}

// Mobius Inclusion Exclusion
// Count triples gcd(a, b, c) = 1
int n = 4;
ll sum = n * n * n;
for (ll i = 2; i <= n; ++i)
    sum -= moebius[i] * (n / i) * (n / i) * (n / i);
