unordered_map<int,int> pf(int n){
    unordered_map<int, int> factors;
    while(n%2 == 0){
        factors[2]++;
        n/=2;
    }

    for(int i = 3; SQ(i) <= n; i+=2){
        while(n%i == 0){
            factors[i]++;
            n/=i;
        }
    }
    if(n > 2) factors[n]++;
    return factors;
}
