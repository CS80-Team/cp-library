int s(int n){
    unordered_map<int,int> factors = pf(n);
    int sum = 1;
    for(const auto& factor: factors){
        int p = factor.first;
        int exp = factor.second;
        sum *= (pow(p,exp+1)-1)/p-1;
    }
    return sum;
}
