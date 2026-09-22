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
#define mxn 200'007

int n, a[mxn], cnt[mxn], dp[mxn];

inline void LonggVuz(){
	cin >> n;
	fo(i, 1, n) cin >> a[i];
	fo(i, 1, n) if(a[i] <= n) ++cnt[a[i]];
	fo(i, 1, n){
		for(int j=i; j<=n; j+=i) dp[j] += cnt[i];
	}
	int res = 0;
	fo(i, 1, n) maxi(res, dp[i]);
	cout << res, el;
	fo(i, 1, n) cnt[i] = dp[i] = 0;
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
