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
#define ret(x) return void(cout << (x) << '\n')
#define one(n) __builtin_popcountll(n)
#define mask(i) (1ll << (i))
#define bit(n, i) ((n) >> (i) & 1)
#define pub push_back
#define pob pop_back
#define int long long
#define mxn 500'007

const int mod = 998244353;

int n, q, sum[mxn], dp[mxn];
string s;
int f[mxn], ivf[mxn];

int Pow(int a, int n){
	int r = 1;
	while(n){
		if(n & 1) r = r * a % mod;
		a = a * a % mod; n /= 2;
	}
	return r;
}

void prepare(){
	const int n = 5e5;
	f[0] = 1;
	fo(i, 1, n) f[i] = f[i - 1] * i % mod;
	ivf[n] = Pow(f[n], mod - 2);
	fd(i, n, 1) ivf[i - 1] = ivf[i] * i % mod;
}

int C(int n, int k){
	return f[n] * ivf[k] % mod * ivf[n - k] % mod;
}

void solve(){
	prepare();
	cin >> n >> q >> s; s = " " + s;
	vector<int> pos;
	fo(i, 1, n){
		sum[i] = sum[i - 1];
		dp[i] = dp[i - 1];
		if(s[i] == '1'){
			++sum[i];
			if(len(pos) and (i & 1) != (pos.back() & 1)) ++dp[i];
			pos.pub(i);
		}
	}
	while(q--){
		int l, r; cin >> l >> r;
		int len = r - l + 1;
		int one = sum[r] - sum[l - 1];
		int cnt = len - one * 2;
		int first = lower_bound(all(pos), l) - begin(pos);
		if(first < len(pos)){
			cnt += dp[r] - dp[pos[first]];
			if((pos[first] & 1) == (l & 1)) ++cnt;
		}
		cnt /= 2; ++one;
		// cout << one << ' ' << cnt, el;
		// cnt : keo
		// one : nguoi
		cout << C(cnt + one - 1, cnt), el;
	}
}

signed main(){
	ios::sync_with_stdio(0); cin.tie(0);
	
	int o = 1; ///cin >> o;
	while(o --> 0) solve();
}
