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
#define mxn 200'007
#define clz(n) __builtin_clzll(n)
#define ctz(n) __builtin_ctzll(n)
#define one(n) __builtin_popcountll(n)
#define mask(n) (1ll << (n))
#define bit(n, i) ((n) >> (i) & 1)

int n, a[mxn], idx[mxn];

inline void LonggVuz(){
	cin >> n;
	fo(i, 1, n) cin >> a[i];
	fo(i, 1, n){
		if(a[i]) idx[i] = 63 - clz(a[i]);
		else idx[i] = -1;
	}
	while(1){
		int mi = 20;
		fo(i, 1, n) mini(mi, idx[i]);
		if(mi < 0) break;
		bool stop = 0;
		fo(i, 1, n) if(bit(a[i], idx[i]) != bit(a[1], idx[1])){
			stop = 1; break;
		}
		if(stop) break;
		fo(i, 1, n) --idx[i];
	}
	int res = 1e18;
	fd(len, 20, 0){
		int ans = 0;
		fo(i, 1, n){
			int cnt = 0;
			fd(j, idx[i], 0){
				if(bit(a[i], j) == 0) break;
				++cnt;
			}
			ans += idx[i] + 1 - cnt + abs(len - cnt);
		}
		mini(res, ans);
	}
	cout << res;
}

signed main(){
	ios::sync_with_stdio(false); cin.tie(nullptr);
	
	#define name "LonggVuz"
	if(fopen(name".inp", "r")){
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	
	signed o_o = 1; if(false) cin >> o_o;
	fo(c_c, 1, o_o) orz(c_c), LonggVuz();
	
	cerr << "[exec time = '" << clock() << "ms']";
}
