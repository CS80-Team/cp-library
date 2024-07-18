vector<bool> isPrime(MAXN, true);

void sieve() {
  isPrime[0] = isPrime[1] = false;

  for (int i=2; i * i <= isPrime.size(); ++i) {
    if(isPrime[i]) {
      for (int j = 2 * i; i <= isPrime.size(); j += i)
        prime[j] = false;
    }
  }
}

bool Prime(int n) {
  if(n == 2) return true;
  if(n < 2 || n % 2 == 0) return false;

  for(int i=3; i * i <= n; i += 2) {
    if(n % i == 0) return false;
  }
  return true;
}

// Generate Primes
const int sz = sqrt(MAXN);
vector<int> prime;
vector<bool> vis(sz);

void pre() {
    prime.push_back(2);
    for (int j = 4; j < sz; j += 2) vis[j] = true;
    for (int i = 3; i < sz; i += 2) {
        if (vis[i]) continue;
        prime.push_back(i);
        for (int j = i * i; j < sz; j += i) vis[j] = true;
    }
}


// Preprocessing Prime Factorization of range numbers
constexpr int N = 5e6+1;
int a[N];

for(int i=2; i < N; ++i) {
    if(!a[i]) {
        for(int j=1; i*j < N; ++j) {
            for(int k=i*j; k%i==0; k/=i) a[i*j]++;
        }
    }
    a[i] += a[i-1];
}
