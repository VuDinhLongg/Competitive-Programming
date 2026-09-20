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

const int mod = 1e9 + 7;

int n, q, a[mxn], seg[6][mxn * 4], s[6];

void update(int id, int l, int r, int i, int x){
	if(l == r){
		seg[1][id] = x;
		fo(j, 2, 5) seg[j][id] = seg[j - 1][id] * x % mod;
		return;
	}
	int m = l + r >> 1;
	if(i <= m) update(id * 2, l, m, i, x);
	else update(id * 2 + 1, m + 1, r, i, x);
	fo(j, 1, 5) seg[j][id] = (seg[j][id * 2] + seg[j][id * 2 + 1]) % mod;
}

int query(int id, int l, int r, int u, int v, int k){
	if(r < u or v < l) return 0;
	if(u <= l and r <= v) return seg[k][id];
	int m = l + r >> 1;
	return (query(id * 2, l, m, u, v, k) + query(id * 2 + 1, m + 1, r, u, v, k)) % mod;
}

inline void LonggVuz(){
	cin >> n >> q;
	fo(i, 1, n){
		cin >> a[i];
		update(1, 1, n, i, a[i]);
	}
	while(q--){
		int t; cin >> t;
		if(t == 1){
			int i, x; cin >> i >> x;
			update(1, 1, n, i, x);
			a[i] = x;
		}else{
			int l, r, k; cin >> l >> r >> k;
			fo(j, 1, k) s[j] = query(1, 1, n, l, r, j);
			if(k == 1){
				int res = s[1] * (r - l + 1) % mod * 2 % mod;
				cout << res, el;
			}else if(k == 2){
				int r1 = s[1] * s[1] % mod * 2 % mod;
				int r2 = s[2] * (r - l + 1) % mod * 2 % mod;
				int res = r1 + r2;
				cout << res % mod, el;
			}else if(k == 3){
				int r1 = s[1] * s[2] % mod * 6 % mod;
				int r2 = s[3] * (r - l + 1) % mod * 2 % mod;
				int res = r1 + r2;
				cout << res % mod, el;
			}else if(k == 4){
				int r1 = s[1] * s[3] % mod * 8 % mod;
				int r2 = s[2] * s[2] % mod * 6 % mod;
				int r3 = s[4] * (r - l + 1) % mod * 2 % mod;
				int res = r1 + r2 + r3;
				cout << res % mod, el;
			}else{
				int r1 = s[1] * s[4] % mod * 10 % mod;
				int r2 = s[2] * s[3] % mod * 20 % mod;
				int r3 = s[5] * (r - l + 1) % mod * 2 % mod;
				int res = r1 + r2 + r3;
				cout << res % mod, el;
			}
		}
	}
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
