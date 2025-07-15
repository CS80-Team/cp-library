#define getBit(n, k) (n >> k) // & 1
#define ON(n, idx) (n | (1ll << idx))
#define OFF(n, idx) (n & ~(1ll << idx))
#define toggle(n, idx) ((n) ^ (1ll<<(idx)))
#define gray(n) (n ^ (n >> 1))
#define bitCount(x) (__builtin_popcountll(x))
#define clz(x) (__builtin_clzll(x))
#define ctz(x) (__builtin_ctzll(x))
#define uniq(x) x.resize(unique(x.begin(), x.end())-x.begin());

#define angle(a) (atan2((a).imag(), (a).real()))
//#define vec(a, b) ((b)-(a))
#define same(v1, v2) (dp(vec(v1,v2),vec(v1,v2)) < EPS)
#define dotProduct(a, b) ((conj(a)*(b)).real())    // a*b cos(T), if zero -> prep
#define crossProduct(a, b) ((conj(a)*(b)).imag())    // a*b sin(T), if zero -> parallel
//#define length(a) (hypot((a).imag(), (a).real()))
#define normalize(a) ((a)/length(a))
#define rotateO(v, ang) ((v)*exp(point(0,ang)))
#define rotateA(p, ang, about) (rotateO(vec(about,p),ang)+about)
#define reflectO(v, m) (conj((v)/(m))*(m))
#define ceil_i(a, b) (((ll)(a)+(ll)(b-1))/(ll)(b))
#define floor_i(a, b) (a/b)
#define round_i(a, b) ((a+(b/2))/b) // if a>0
#define round_m(a, b) ((a-(b/2))/b) // if a<0
#define round_multiple(n, m) round_i(n,m)*m // round to multiple if specified element

const double PI = acos(-1.0);

