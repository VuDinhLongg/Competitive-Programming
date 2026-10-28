#include <bits/stdc++.h>
using namespace std;

template<class X> using min_heap = priority_queue<X, vector<X>, greater<X>>;
template<class X> using max_heap = priority_queue<X, vector<X>, less<X>>;
template<class X, class Y> bool maxi(X &x, const Y &y){ return x < y ? x = y, 1 : 0; }
template<class X, class Y> bool mini(X &x, const Y &y){ return x > y ? x = y, 1 : 0; }

#define el cout << '\n'
#define rep(i, n) fo(i, 0, (n) - 1)
#define fo(i, a, b) for(int32_t i=a; i<=b; ++i)
#define fd(i, a, b) for(int32_t i=a; i>=b; --i)
#define ret(x) return void(cout << (x) << '\n')
#define all(x) begin(x),end(x)
#define len(x) (int)(x).size()
#define fix(x) fixed << setprecision(x)
#define one(n) __builtin_popcountll(n)
#define mask(i) (1ll << (i))
#define bit(n, i) ((n) >> (i) & 1)
#define pub push_back
#define pob pop_back
#define int long long
#define mxn 1'000'007



void solve(){
	int n, m, q; cin >> n >> m >> q;
	int minx = 1e18, maxx = -1e18, miny = 1e18, maxy = -1e18;
	fo(i, 1, n){
		int x, y; cin >> x >> y;
		mini(minx, x);
		maxi(maxx, x);
		mini(miny, y);
		maxi(maxy, y);
	}
	fo(i, 1, m){
		int x, y, u, v; cin >> x >> y >> u >> v;
		mini(minx, x);
		maxi(maxx, u);
		mini(miny, y);
		maxi(maxy, v);
	}
	fo(i, 1, q){
		int x, y, r; cin >> x >> y >> r;
		mini(minx, x - r);
		maxi(maxx, x + r);
		mini(miny, y - r);
		maxi(maxy, y + r);
	}
	int res = max(maxx - minx, maxy - miny);
	cout << res * res, el;
}

signed main(){
	ios::sync_with_stdio(0); cin.tie(0);
	
	int o = 1; cin >> o;
	while(o --> 0) solve();
}
