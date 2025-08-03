vector<int> kmp(const string& pat) {
    int n = pat.size();
    vector<int> pi(n);
    pi[0] = -1;

    for (int i = 1; i < n; i++){
        int j = pi[i - 1];
        while (j >= 0 && pat[j] != pat[i - 1]) j = pi[j];
            pi[i] = j + 1;
    }
    
    return pi;
}

vector<int> find_matches(const string& text, const string& pat) {
    int n = pat.size(), m = text.size();
    string s = pat + "$" + text + "$";

    vector<int> pi = kmp(s), ans;
    for (int i = 0; i <= m; i++)
        if (pi[i + n + 1] == n)
            ans.push_back(i - n);

    return ans;
}