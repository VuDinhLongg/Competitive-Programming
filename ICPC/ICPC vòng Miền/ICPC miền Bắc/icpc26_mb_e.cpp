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
#define ve vector
#define pb push_back
#define po pop_back
#define ii pair<int, int>
#define fi first
#define se second
#define rep(i, n) fo(i, 0, n - 1)
#define fo(i, a, b) for(int32_t i=a; i<=b; ++i)
#define fd(i, a, b) for(int32_t i=a; i>=b; --i)
#define ret(x) return void(cout << (x) << '\n')
#define fix(x) fixed << setprecision(x)
#define all(x) begin(x),end(x)
#define len(x) (int)(x).size()
#define int long long
#define mxn 1'000'007
#define clz(n) __builtin_clzll(n)
#define ctz(n) __builtin_ctzll(n)
#define one(n) __builtin_popcountll(n)
#define mask(n) (1ll << (n))
#define bit(n, i) ((n) >> (i) & 1)



inline void LonggVuz(){
	int n, k; cin >> n >> k;
	int sz = 1;
	while(sz * sz < k) sz = sz * 2 + 1;
	int d = mask(n) / (sz + 1);
	int l = 0, r = sz + 1;
	while(r - l > 1){
		int mid = l + r >> 1;
		int cnt = mid * sz;
		int sub = (mid / 2) * (sz / 2);
		if(cnt - sub + (sz / 2) * (sz / 2) >= k) r = mid;
		else l = mid;
	}
	dbg(d, r);
	int row = d * r;
	cout << row << ' ';
	int rem = r * sz - (r / 2) * (sz / 2) + (sz / 2) * (sz / 2) - k;
	if(r & 1){
		int idx = sz - rem;
		int col = d * idx;
		cout << col, el;
	}else{
		int idx = sz - ((sz - 1) / 2) - rem;
		int col = d + (idx - 1) * (d * 2);
		cout << col, el;
	}
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
