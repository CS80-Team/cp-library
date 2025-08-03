template<class T>
struct Rmq {
	vector<vector<T>> jmp;
    
    // vector is 0-based indexed
	Rmq(const vector<T>& V) : jmp(1, V) {
		for (int pw = 1, k = 1; pw * 2 <= V.size(); pw *= 2, ++k) {
			jmp.emplace_back(V.size() - pw * 2 + 1);
			for(int j = 0; j < jmp[k].size(); j++)
				jmp[k][j] = (jmp[k - 1][j] | jmp[k - 1][j + pw]);
		}
	}
    // query (a, b] inclusive execlusive
	T query(int a, int b) {
		// assert(a < b);
		int dep = 31 - __builtin_clz(b - a);
		return (jmp[dep][a] | jmp[dep][b - (1 << dep)]);
	}
};
