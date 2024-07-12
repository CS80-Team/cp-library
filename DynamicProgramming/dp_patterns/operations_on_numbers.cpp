// put +, -, between sequence of numbers such that the sum is divisible by k, and maximum as possible
const int MAX = 21;
long long mem[MAX][MAX];
const int n = 20;
int k = 4; // example
int v[20];
int fix(int a){
  return (a % k + k) % k;
}
long long tryAll(int pos, int mod){
    long long &ret = mem[pos][mod];
    if(ret != -1){
        return ret;
    }
    if(pos == n){
        return ret = mod == 0;
    }
    if(tryAll(pos+1,fix(mod + v[pos])) || tryAll(pos+1,fix(mod-v[pos]))){
        return ret = 1;
    }
    return ret = 0;
}
