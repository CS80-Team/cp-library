int maxK;

ll mem[21][101]; // k, and s

// You are given an integer s and an integer k. Find k positive integers a1, a2, ..., ak
// such that their sum is equal to s and their product is the maximal possible. Return their product.

ll maxProd(int k, int rem)
{
	if(k == maxK){
		// base case
		if(rem == 0)
			return 1;
		return 0;
	}
	
	if(rem == 0)	// invalid case
		return 0;

	ll &ret = mem[k][rem];

	if(ret != -1)
		return ret;

	ret = 0;

	for (int i = 1; i <= rem; ++i) {
		ll sol = maxProd(k+1, rem - i) * i;
		ret = max(ret, sol);
	}

	return ret;
}

