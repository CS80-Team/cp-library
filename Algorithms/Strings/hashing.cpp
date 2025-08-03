// #define int long long

struct PreHash {
    vector<int> pow, invPow;
    const int MOD, BASE;

    int modExp(int base, int exp) const {
        int res = 1;
        while (exp > 0) {
            if (exp % 2 == 1)
                res = 1LL * res * base % MOD;
            base = 1LL * base * base % MOD;
            exp /= 2;
        }
        return res;
    }

    explicit PreHash(const int n, const int MOD, const int BASE) : MOD(MOD), BASE(BASE) {
        pow.resize(n);
        invPow.resize(n);

        pow[0] = 1;
        invPow[0] = 1;
        const int invBase = modExp(BASE, MOD - 2);

        for (int i = 1; i < n; ++i) {
            pow[i] = 1LL * pow[i - 1] * BASE % MOD;
            invPow[i] = 1LL * invPow[i - 1] * invBase % MOD;
        }
    }
};

struct Hash {
    vector<int> pref;
    const PreHash* pre;
    int n;

    explicit Hash(const string& s, const PreHash& p) : pre(&p) {
        n = s.size();
        if (s.empty()) return;

        pref.resize(n);
        pref[0] = s[0] % pre->MOD;

        for (int i = 1; i < n; ++i) {
            pref[i] = (pref[i - 1] + 1LL * s[i] * pre->pow[i]) % pre->MOD;
        }
    }

    int getHashRange(int l, int r) const {
        int ret = pref[r];
        if (l > 0) ret = (ret - pref[l - 1] + pre->MOD) % pre->MOD;
        // if (ret < 0) ret += pre->MOD;
        return 1LL * ret * pre->invPow[l] % pre->MOD;
    }
};

struct HashWhole {
    int pref, suff;
    const PreHash* pre;
    int n;


    explicit HashWhole(const string& s, const PreHash& p) : pre(&p) {
        n = s.size();
        if (s.empty()) return;

        pref = s[0] % pre->MOD;
        for (int i = 1; i < n; ++i) {
            pref = (pref + 1LL * s[i] * pre->pow[i]) % pre->MOD;
        }

        suff = s[n - 1] % pre->MOD;
        for (int i = n - 2; i >= 0; --i) {
            suff = (suff + 1LL * s[i] * pre->pow[n - 1 - i]) % pre->MOD;
        }
    }

    void mergeHash(const HashWhole& other) {
        pref = (1LL * pref) + (other.pref * 1LL * (pre->pow[n] % pre->MOD) % pre->MOD);
        pref %= pre->MOD;

        suff = ((other.suff * 1LL) + 1LL * suff * (pre->pow[other.n] % pre->MOD)) % pre->MOD;
        suff %= pre->MOD;

        n += other.n;
    }

    bool isPalindrome() const {
        return suff == pref;
    }
};

struct Hasher {
    const PreHash* pre;
    explicit Hasher(const PreHash& p) : pre(&p) {}

    int hash(const string& s, int st, const int end) const {
        if (s.empty() || st > end) return 0;

        int pref = s[st] % pre->MOD, i = 1;
        for (st = st + 1; st < end; ++st) {
            pref = (pref + 1LL * s[st] * pre->pow[i++]) % pre->MOD;
        }

        return pref;
    }
};

constexpr int N = 3e5 + 10;
const PreHash pre2(N, 1e9 + 9, 107);
const PreHash pre1(N, 1e9 + 7, 37);


// #undef int long long