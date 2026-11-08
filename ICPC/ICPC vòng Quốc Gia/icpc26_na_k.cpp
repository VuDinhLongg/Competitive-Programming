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



void solve(){
	string s; cin >> s;
	int n = len(s);
	int i = 0;
	vector<int> val;
	while(i < n){
		int j = i;
		while(j < n and s[j] == s[i]) ++j;
		val.push_back(j - i);
		i = j;
	}
	int m = len(val);
	sort(all(val));
	vector<int> dp = val;
	fo(i, 1, m - 1) dp[i] += dp[i - 1];
	fo(k, 1, n){
		int pos = lower_bound(all(val), k) - begin(val);
		if(pos == m){
			cout << 0 << ' ';
			continue;
		}
		int res = dp[m - 1];
		if(pos) res -= dp[pos - 1];
		int cnt = m - 1 - pos + 1;
		int sub = cnt * (k - 1);
		res -= sub;
		if(k > 1) res -= min(k, val[m - 1] - k + 1);
		cout << res << ' ';
	}
	el;
}

signed main(){
	ios::sync_with_stdio(0); cin.tie(0);
	
	int o = 1; cin >> o;
	while(o --> 0) solve();
}
