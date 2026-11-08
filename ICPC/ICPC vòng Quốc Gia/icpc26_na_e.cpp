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
	int k; cin >> k;
	int res = 1e9;
	fo(x, 100, 999) fo(y, 100, 999) if((y / 100) == (x % 10) * k){
		set<int> s;
		int xx = x;
		while(xx) s.insert(xx % 10), xx /= 10;
		int yy = y;
		while(yy) s.insert(yy % 10), yy /= 10;
		if(len(s) == 6) mini(res, x + y);
	}
	cout << res;
}

signed main(){
	ios::sync_with_stdio(0); cin.tie(0);
	
	int o = 1; ///cin >> o;
	while(o --> 0) solve();
}
