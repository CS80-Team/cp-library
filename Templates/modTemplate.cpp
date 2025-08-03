constexpr int MOD = 1e9+7; // must be a prime number

int add(int a, int b) {
    int res = a+b;
    if(res >= MOD) return res -= MOD;
}

int sub(int a, int b) {
    int res = a-b;
    if(res < 0) return res += MOD;
}

int power(int a, int e) {
    int res = 1;
    while(e) {if(e & 1) res = res * a % MOD; a = a * a % MOD; e >>= 1;}
    return res;
}


---------------------------------------------------------
                                                         |
// note -> from Fermat little theorem, we can deduce that| 
// a^(BIG) % prime = (a ^ (BIG%(prime - 1)))%prime       |
// because every a^(prime - 1) is equal to 1             |
// from the identity says a^(prime - 1) % prime = 1      |
                                                         |
---------------------------------------------------------

int inverse(int a) {
    return power(a, MOD-2);
}

int div(int a, int b) {
    return a * inverse(b) % MOD;
}
