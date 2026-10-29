#include <bits/stdc++.h>
using namespace std;

template<class X> using max_heap = priority_queue<X, vector<X>, less<X>>;
template<class X> using min_heap = priority_queue<X, vector<X>, greater<X>>;
template<class X, class Y> bool maxi(X &x, const Y &y){ return x < y ? x = y, 1 : 0; }
template<class X, class Y> bool mini(X &x, const Y &y){ return x > y ? x = y, 1 : 0; }

#define el cout << '\n'
#define rep(i, n) fo(i, 0, (n) - 1)
#define fo(i, a, b) for(int i=a; i<=b; ++i)
#define fd(i, a, b) for(int i=a; i>=b; --i)
#define all(x) begin(x),end(x)
#define len(x) (int)(x).size()
#define fix(x) fixed << setprecision(x)
#define ret(x) cout << (x), el; return
#define one(n) __builtin_popcountll(n)
#define mask(i) (1ll << (i))
#define bit(n, i) ((n) >> (i) & 1)
#define pub push_back
#define pob pop_back
#define int long long
#define mxn 200'007

int n, a, b, h[mxn], g[mxn];

void solve(){
	cin >> n >> a >> b;
	fo(i, 1, n) cin >> h[i], g[i] = h[i];
	sort(g+1, g+n+1);
	int med = g[n / 2];
	int res1 = 0, res2 = 0, cnt1 = 0, cnt2 = 0;
	fo(i, 1, n){
		if(h[i] <= med){
			res1 += cnt1 * a;
		}else ++cnt1;
		if(h[i] > med){
			res2 += cnt2 * a;
		}else ++cnt2;
	}
	cout << min({res1 + b, res2 + b, b * 2});
}

signed main(){
	ios::sync_with_stdio(0); cin.tie(0);
	
	int o = 1; ///cin >> o;
	while(o --> 0) solve();
}
