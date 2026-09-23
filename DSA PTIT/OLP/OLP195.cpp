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

const int mod = 1e9 + 7;

struct matrix{
	int x[5][5];
	matrix(){
		memset(x, 0, sizeof x);
	}
};

matrix Mul(const matrix &a, const matrix &b){
	matrix m;
	fo(i, 0, 4) fo(j, 0, 4) fo(k, 0, 4){
		m.x[i][j] += a.x[i][k] * b.x[k][j];
		m.x[i][j] %= mod;
	}
	return m;
}

matrix Pow(matrix a, int n){
	matrix m;
	fo(i, 0, 4) m.x[i][i] = 1;
	while(n){
		if(n & 1) m = Mul(m, a);
		a = Mul(a, a); n /= 2;
	}
	return m;
}

inline void LonggVuz(){
	int n; cin >> n;
	if(n <= 3) ret(n);
	n -= 3;
	matrix m;
	m.x[0][0] = 3;
	m.x[0][1] = 2;
	m.x[0][2] = 9;
	m.x[0][3] = 3;
	m.x[0][4] = 1;
	matrix t;
	t.x[0][0] = 3; t.x[0][1] = 1;
	t.x[1][0] = 2;
	t.x[2][0] = 1; t.x[2][2] = 1;
	t.x[3][0] = 2; t.x[3][2] = 2; t.x[3][3] = 1;
	t.x[4][0] = 2; t.x[4][2] = 1; t.x[4][3] = 1; t.x[4][4] = 1;
	m = Mul(m, Pow(t, n));
	cout << m.x[0][0], el;
}

signed main(){
	ios::sync_with_stdio(false); cin.tie(nullptr);
	
	#define name "LonggVuz"
	if(fopen(name".inp", "r")){
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	
	signed o_o = 1; if(1) cin >> o_o;
	fo(c_c, 1, o_o) orz(c_c), LonggVuz();
	
	cerr << "[exec time = '" << clock() << "ms']";
}
