struct MedianFinder {
    multiset<ll> low, up;
    ll sumLow = 0, sumUp = 0;
 
    void insert(ll val) {
        if (low.empty() || val <= *low.rbegin()) {
            low.insert(val);
            sumLow += val;
        } else {
            up.insert(val);
            sumUp += val;
        }
        rebalance();
    }
 
    void erase(ll val) {
        if (low.find(val) != low.end()) {
            low.erase(low.find(val));
            sumLow -= val;
        } else if (up.find(val) != up.end()) {
            up.erase(up.find(val));
            sumUp -= val;
        }
        rebalance();
    }
 
    void rebalance() {
        // Ensure low has (n+1)/2 elements
        while (low.size() > up.size() + 1) {
            ll val = *low.rbegin();
            low.erase(prev(low.end()));
            sumLow -= val;
            up.insert(val);
            sumUp += val;
        }
        while (low.size() < up.size()) {
            ll val = *up.begin();
            up.erase(up.begin());
            sumUp -= val;
            low.insert(val);
            sumLow += val;
        }
    }
 
    double median() const {
        if (low.size() == up.size()) {
            return (*low.rbegin() + *up.begin()) / 2.0;
        }
        return *low.rbegin();
    }
 
    ll balanceCost() {
        return sumUp - sumLow +
               ((low.size() + up.size()) % 2 == 0 ? 0 : this->median());
    }
};