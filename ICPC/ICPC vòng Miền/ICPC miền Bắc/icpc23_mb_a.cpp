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

int n, fibo[100];
map<int, int> dp[100];

void prepare(){
	fibo[0] = fibo[1] = 1;
	fo(i, 2, 90) fibo[i] = fibo[i - 1] + fibo[i - 2];
}

int memo(int i, int n){
	if(n == 1) return 1;
	if(i < 2) return 0;
	if(dp[i].count(n)) return dp[i][n];
	dp[i][n] += memo(i - 1, n);
	if(n % fibo[i] == 0) dp[i][n] += memo(i, n / fibo[i]);
	return dp[i][n];
}

void solve(){
	cin >> n;
	cout << memo(90, n), el;
}

signed main(){
	ios::sync_with_stdio(0); cin.tie(0);
	prepare();
	int o = 1; cin >> o;
	while(o --> 0) solve();
}
