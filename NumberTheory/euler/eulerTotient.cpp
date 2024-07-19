
int eulerTotient(int n){
    int result = n;

    for(int i = 2; SQ(i) <= n; i++){
        if(n%i == 0){
            while(n%i == 0){
                n/=i;
            }
            result -= result/i;
        }
    }

    if(n > 1) result -= result/n;
    return result;
}

//Phi(n) = n * (1 - 1/P1) * (1 - 1/P2) * ...

//NOTE: summation of Euler function over divisors of n is equal to n


// using seive
void phi_generator() {
    const int MAX = 1000000;
    char primes[MAX];
    int phi[MAX];

    memset(primes, 1, sizeof(primes));

    for (int k = 0; k < MAX; ++k)
        phi[k] = 1;

    for (int i = 2; i <= MAX; ++i) {
        if (primes[i]) {
            phi[i] = i - 1; // phi(prime) = p-1

            for (int j = i * 2; j <= MAX; j += i) {
                primes[j] = 0;
                int n = j, pow = 1;
                while (n % i == 0) {
                    pow *= i;
                    n /= i;
                }
                phi[j] *= (pow / i) * (i - 1);
            }
        }
    }
}

// phi(N!) = (N is prime ? N-1 : N) * phi((N-1)!)
ll phi_factn(int n) {
    ll ret = 1;
    for (int i = 2; i <= n; ++i)
        ret = ret * (isprime(i) ? i - 1 : i);
    return ret;
}
