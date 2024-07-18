    int n, k;
    cin >> n >> k;
 
    vector<int> a(n + 1);
    vector<pair<int, int>> rng;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
 
    map<int, set<int>> prev;
    int currSum = 0;
 
    for (int i = 1; i <= n; ++i) {
        currSum += a[i];
        if (currSum == k) {
            rng.push_back({1, i});
        }
        if (prev.find(currSum - k) != prev.end()) {
            for (auto &j : prev[currSum - k]) {
                rng.push_back({j + 1, i});
            }
        }
        prev[currSum].insert(i);
    }