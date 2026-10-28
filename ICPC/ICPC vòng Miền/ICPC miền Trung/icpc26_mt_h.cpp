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
#define mxn 500'007

#define i128 __int128_t

void print(i128 n){
	string s;
	while(n){
		s.pub(n % 10 + '0'); n /= 10;
	}
	reverse(all(s));
	cout << s;
}

void solve(){
	int n; cin >> n;
	map<string, int> mp;
	fo(i, 1, n){
		string s; int p; cin >> s >> p;
		if(mp.count(s)) mini(mp[s], p);
		else mp[s] = p;
	}
	cout << len(mp) << ' ';
	i128 res = 0;
	for(auto &[s, p] : mp) res += p;
	print(res);
}

signed main(){
	ios::sync_with_stdio(0); cin.tie(0);
	
	int o = 1; ///cin >> o;
	while(o --> 0) solve();
}
