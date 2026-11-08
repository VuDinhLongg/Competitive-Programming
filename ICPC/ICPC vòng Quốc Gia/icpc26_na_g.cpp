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
#define mxn 100'007

int n, b[mxn], a[mxn];

void solve(){
	cin >> n;
	fo(i, 1, n - 1) cin >> b[i];
	a[1] = b[1];
	a[n] = b[n - 1];
	fo(i, 2, n - 1){
		a[i] = b[i - 1] / __gcd(b[i - 1], b[i]) * b[i];
	}
	fo(i, 1, n - 1){
		if(__gcd(a[i], a[i + 1]) != b[i]) ret(-1);
	}
	fo(i, 1, n) cout << a[i] << ' '; el;
}

signed main(){
	ios::sync_with_stdio(0); cin.tie(0);
	
	int o = 1; cin >> o;
	while(o --> 0) solve();
}
