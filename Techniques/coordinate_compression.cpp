void coordinate_compress(vector<int> &x, int start=0, int step=1) {
	set unique(x.begin(), x.end());
	map<int, int> valPos;
	
	int idx=0;
	for (auto i: unique) {
		valPos[i] = start + idx * step;
		++idx;
	}
	for(auto &i: x) i = valPos[i];
	
}
