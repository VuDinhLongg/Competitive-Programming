#include <bits/stdc++.h>
using namespace std;

template<class X> using max_heap = priority_queue<X, vector<X>, less<X>>;
template<class X> using min_heap = priority_queue<X, vector<X>, greater<X>>;
template<class X, class Y> bool maxi(X &x, const Y &y){ return x < y ? x = y, 1 : 0; }
template<class X, class Y> bool mini(X &x, const Y &y){ return x > y ? x = y, 1 : 0; }

#define el cout << '\n'
#define rep(i, n) fo(i, 0, (n) - 1)
#define fo(i, a, b) for(int i=(a); i<=(b); ++i)
#define fd(i, a, b) for(int i=(a); i>=(b); --i)
#define ret(x) return void(cout << (x) << '\n')
#define all(x) begin(x),end(x)
#define len(x) (int)(x).size()
#define int long long
#define mxn 10'007
#define mask(n) (1ll << (n))
#define bit(n, i) ((n) >> (i) & 1)

string s;
bool dx[mxn][mxn];
vector<int> f[mxn];

void solve(){
	cin >> s;
	int n = len(s);
	s = " " + s;
	fo(i, 1, n) dx[i][i] = 1;
	fo(len, 2, n) fo(i, 1, n - len + 1){
		int j = i + len - 1;
		if(s[i] == s[j]) dx[i][j] = (len == 2 or dx[i + 1][j - 1]);
	}
	fo(i, 1, n) fo(j, i, n) if(dx[i][j]){
		f[j - i + 1].push_back(i);
	}
	fo(i, 1, n) sort(all(f[i]));
	int q; cin >> q;
	while(q--){
		int k; cin >> k;
		vector<int> a(k);
		rep(i, k) cin >> a[i];
		int full = mask(k);
		vector<int> dp(full, 1e9);
		rep(i, k) if(len(f[a[i]])){
			// cout << i << ' ' << a[i] << ' ' << f[a[i]][0] + a[i] - 1, el;
			mini(dp[mask(i)], f[a[i]][0] + a[i] - 1);
		}
		fo(mask, 1, full - 1) if(__builtin_popcount(mask) > 1){
			rep(i, k) if(bit(mask, i)){
				int pre_mask = mask ^ mask(i);
				if(dp[pre_mask] < 1e9){
					// cout << bitset<4>(mask) << ' ' << bitset<4>(pre_mask), el;
					int idx = upper_bound(all(f[a[i]]), dp[pre_mask]) - begin(f[a[i]]);
					if(idx < len(f[a[i]])){
						mini(dp[mask], f[a[i]][idx] + a[i] - 1);
					}
				}
			}
			// cout << bitset<4>(mask) << ' ' << dp[mask], el;
		}
		if(dp[full - 1] <= n) cout << "YES";
		else cout << "NO";
		el;
	}
}

signed main(){
	ios::sync_with_stdio(0); cin.tie(0);
	
	int o = 1; ///cin >> o;
	while(o --> 0) solve();
}
