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
#define mxn 10'000'007

const int mod = 1e9 + 7;

int f[mxn];

void prepare(){
	const int n = 1e7;
	f[0] = 1;
	fo(i, 1, n) f[i] = f[i - 1] * i % mod;
}

int Pow(int a, int n){
	int r = 1;
	while(n){
		if(n & 1) r = r * a % mod;
		a = a * a % mod; n /= 2;
	}
	return r;
}

void solve(){
	int n, m; cin >> n >> m;
	cout << Pow(f[m], n) * Pow(f[n], m) % mod, el;
}

signed main(){
	ios::sync_with_stdio(0); cin.tie(0);
	prepare();
	int o = 1; cin >> o;
	while(o --> 0) solve();
}
