#include <bits/stdc++.h>
using namespace std;

template<class X, class Y> bool maxi(X &x, const Y &y){ return x < y ? x = y, 1 : 0; }
template<class X, class Y> bool mini(X &x, const Y &y){ return x > y ? x = y, 1 : 0; }

#define el cout << '\n'
#define fo(i, a, b) for(int32_t i=a; i<=b; ++i)
#define fd(i, a, b) for(int32_t i=a; i>=b; --i)
#define ret(x) return void(cout << (x) << '\n')
#define all(x) begin(x),end(x)
#define len(x) (int)(x).size()
#define int long long
#define mxn 200'007
#define ii pair<int, int>
#define fi first
#define se second

int n, a[mxn];
ii b[mxn];

void solve(){
	cin >> n;
	fo(i, 1, n) cin >> a[i];
	int len = 0;
	{
		int i = 1;
		while(i <= n){
			int j = i;
			while(j <= n and a[j] == a[i]) ++j;
			b[++len] = {a[i], j - i};
			i = j;
		}
	}
	int res = 0;
	int i = 1;
	while(i <= len){
		int o = 0;
		int cur = b[i].se;
		int j = i + 1;
		while(j <= len){
			if(o <= 0 and b[j].fi > b[j - 1].fi){
				res += cur * b[j].se;
				cur += b[j].se;
				o = 1;
			}else if(o >= 0 and b[j].fi < b[j - 1].fi){
				res += cur * b[j].se;
				cur += b[j].se;
				o = -1;
			}else break;
			++j;
		}
		i = max(i + 1, j - 1);
	}
	fo(i, 1, len) res += b[i].se * (b[i].se - 1) / 2;
	cout << res;
}

signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int o = 1; ///cin >> o;
	while(o --> 0) solve();
}
