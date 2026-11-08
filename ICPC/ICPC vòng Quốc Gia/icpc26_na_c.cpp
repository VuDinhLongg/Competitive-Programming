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
#define mxn 1'000'007

const int mod = 1e9 + 7;

void solve(){
	int n; cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	int res = 0, sum = 0;
	rep(i, n){
		res = (res + a[i] * sum) % mod;
		sum = (sum + a[i]) % mod;
	}
	cout << res, el;
}

signed main(){
	ios::sync_with_stdio(0); cin.tie(0);
	
	int o = 1; cin >> o;
	while(o --> 0) solve();
}
