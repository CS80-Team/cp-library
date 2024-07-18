// Ref: USACO guide
// will make GCC auto-vectorize for loops and optimizes floating points better (assumes associativity and turns off denormals).
#pragma GCC optimize ("Ofast")
// can double performance of vectorized code, but causes crashes on old machines.
#pragma GCC target ("avx,avx2,fma")

// slows down run time but throws a Runtime Error if an overflow occured
#pragma GCC optimize("trapv")