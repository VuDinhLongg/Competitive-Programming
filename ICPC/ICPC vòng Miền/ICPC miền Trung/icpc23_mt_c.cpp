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

const int mod = 1e9 + 7;

int n, a[101], dp[101][71], cnt[101][71];

int gcd(int a, int b){
	return b == 0 ? a : gcd(b, a % b);
}

void solve(){
	cin >> n;
	fo(i, 1, n) cin >> a[i];
	fo(i, 1, n){
		fo(j, 1, 70){
			dp[i][j] = dp[i - 1][j];
			cnt[i][j] = cnt[i - 1][j];
		}
		fo(j, 1, 70) if(cnt[i - 1][j]){
			int nj = gcd(j, a[i]);
			dp[i][nj] += cnt[i - 1][j] * nj % mod;
			dp[i][nj] %= mod;
			cnt[i][nj] += cnt[i - 1][j];
			cnt[i][nj] %= mod;
		}
		dp[i][a[i]] = (dp[i][a[i]] + a[i]) % mod;
		cnt[i][a[i]] = (cnt[i][a[i]] + 1) % mod;
	}
	int res = 0;
	fo(j, 1, 70) res = (res + dp[n][j]) % mod;
	cout << res, el;
	fo(i, 1, n) fo(j, 1, 70) dp[i][j] = cnt[i][j] = 0;
}

signed main(){
	ios::sync_with_stdio(0); cin.tie(0);
	
	int o = 1; cin >> o;
	while(o --> 0) solve();
}
