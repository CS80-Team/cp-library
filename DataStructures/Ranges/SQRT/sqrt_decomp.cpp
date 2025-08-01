#define OO 1e18


const int sz = 2e5 + 5;
const int sq = 500;

int arr[sz] = {};
int ans[sq] = {};

void pre() {
    fill(ans, ans + sq, OO);
    for(int i = 0; i < sz; i++) {
        ans[i / sq] = min(ans[i / sq], arr[i]);
    }
}

// can be O(1) with inversable operations, else it's sqrt
void update(int k, int x) {
   arr[k] = x;
   int start = k / sq;
   ans[start] = *min_element(arr + (start * sq), arr + (start + 1) * sq);
}

int query(int l, int r){
    int ret = OO;
    while(l <= r) {
        if(l % sq == 0 && l + sq <= r) {
            ret = min(ret, ans[l / sq]);
            l += sq;
        }else {
            ret = min(ret, arr[l]);
            l++;
        }
    }
    return ret;
}