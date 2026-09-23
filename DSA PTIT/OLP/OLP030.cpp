#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <debug.h>
#else
#define dbg(...) 1608
#define orz(...) 2005
#endif

template<class X, class Y> bool maxi(X &x, const Y &y){ return x < y ? x = y, 1 : 0; }
template<class X, class Y> bool mini(X &x, const Y &y){ return x > y ? x = y, 1 : 0; }

#define el cout << '\n'
#define fo(i, a, b) for(int32_t i=a; i<=b; ++i)
#define fd(i, a, b) for(int32_t i=a; i>=b; --i)
#define ret(x) return void(cout << (x) << '\n')
#define all(x) begin(x),end(x)
#define len(x) (int)(x).size()
#define int long long
#define mxn 1'000'007
#define clz(n) __builtin_clzll(n)
#define ctz(n) __builtin_ctzll(n)
#define one(n) __builtin_popcountll(n)
#define mask(n) (1ll << (n))
#define bit(n, i) ((n) >> (i) & 1)

#define size 256
#define rep(i) fo(i, 0, size - 1)

const int mod = 1e9 + 7;

int id[16][16], now;

void prepare(){
	fo(i, 0, 15) fo(j, 0, 15) id[i][j] = now++;
}

struct matrix{
	int x[size][size];
	matrix(){
		memset(x, 0, sizeof x);
	}
	void reset(){
		memset(x, 0, sizeof x);
	}
};

matrix Mul(const matrix &a, const matrix &b){
	matrix m;
    rep(i) rep(k){
        if(a.x[i][k] == 0) continue;
        rep(j){
            m.x[i][j] = (m.x[i][j] + a.x[i][k] * b.x[k][j]) % mod;
        }
    }
	return m;
}

matrix Pow(matrix a, int k){
	matrix m;
	rep(i) m.x[i][i] = 1;
	while(k){
		if(k & 1) m = Mul(m, a);
		a = Mul(a, a); k /= 2;
	}
	return m;
}

bool check1(int m1, int m2){
	if(bit(m1, 0) and bit(m2, 2)) return 0;
	if(bit(m1, 1) and bit(m2, 3)) return 0;
	if(bit(m1, 2) and bit(m2, 0)) return 0;
	if(bit(m1, 3) and bit(m2, 1)) return 0;
	return 1;
}

bool check2(int m1, int m2){
	if(bit(m1, 0) and bit(m2, 1)) return 0;
	if(bit(m1, 1) and bit(m2, 0)) return 0;
	if(bit(m1, 1) and bit(m2, 2)) return 0;
	if(bit(m1, 2) and bit(m2, 1)) return 0;
	if(bit(m1, 2) and bit(m2, 3)) return 0;
	if(bit(m1, 3) and bit(m2, 2)) return 0;
	return 1;
}

matrix r, t;

inline void LonggVuz(){
	int m, n; cin >> m >> n;
	if(n == 1) ret(mask(m));
	int full = mask(m) - 1;
	r.reset();
	fo(mask1, 0, full) fo(mask2, 0, full) if(check1(mask1, mask2)){
		r.x[0][id[mask1][mask2]] = 1;
	}
	t.reset();
	fo(mask1, 0, full) fo(mask2, 0, full) fo(mask3, 0, full){
		if(check1(mask1, mask2) and check1(mask2, mask3) and check2(mask1, mask3)){
			t.x[id[mask1][mask2]][id[mask2][mask3]] = 1;
		}
	}
	r = Mul(r, Pow(t, n - 2));
	int res = 0;
	fo(mask1, 0, full) fo(mask2, 0, full) if(check1(mask1, mask2)){
		res = (res + r.x[0][id[mask1][mask2]]) % mod;
	}
	cout << res, el;
}

signed main(){
	ios::sync_with_stdio(false); cin.tie(nullptr);
	
	#define name "LonggVuz"
	if(fopen(name".inp", "r")){
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	prepare();
	signed o_o = 1; if(1) cin >> o_o;
	fo(c_c, 1, o_o) orz(c_c), LonggVuz();
	
	cerr << "[exec time = '" << clock() << "ms']";
}
