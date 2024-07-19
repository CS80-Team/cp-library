// storing the index also
struct SNode {
    int val;
    int index;
};

class SparseTable {
private:
    vector<vector<SNode>> table;

    function<SNode(const SNode&, const SNode&)> merge;

    static SNode StaticMerge(const SNode& a, const SNode& b) {
        return a.val < b.val ? a : b;
    }

public:
    explicit SparseTable(const vector<int>& arr, const function<SNode(const SNode&, const SNode&)>& mergeFunc = StaticMerge) {
        int n = static_cast<int>(arr.size());
        int log_n = static_cast<int>(log2(n)) + 1;
        this->merge = mergeFunc;

        table.resize(n, vector<SNode>(log_n));

        for (int i = 0; i < n; i++) {
            table[i][0] = {arr[i], i};
        }

        for (int j = 1; (1 << j) <= n; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                table[i][j] = mergeFunc(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    SNode query(int left, int right) {
        int j = static_cast<int>(log2(right - left + 1));
        return merge(table[left][j], table[right - (1 << j) + 1][j]);
    }

    // query in O(log(n)) if its could't apply to Sparse Table directly
    T query_log(int l, int r){
      int len = r - l + 1;
      T ans;
      for(int i = 0; l <= r; i++){
          if (len & (1 << i)){
              ans = merge(ans, table[i][l]);
              l+= (1 << i);
          }
      }
   }
};


int main(void) {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto& element : arr) cin >> element;

    SparseTable minSt(arr, [](const SNode& a, const SNode& b) -> SNode {
        return a.val < b.val ? a : b;
    });

    SparseTable maxSt(arr, [](const SNode& a, const SNode& b) -> SNode {
        return a.val > b.val ? a : b;
    });
}
