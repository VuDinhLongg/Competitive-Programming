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
#define mxn 200'007
#define ai2 array<int, 2>

int n;
ai2 a[mxn];

void solve(){
	cin >> n;
	fo(i, 1, n) cin >> a[i][0] >> a[i][1];
	int res = 0;
	{
		sort(a+1, a+n+1);
		int i = 1;
		while(i <= n){
			int j = i;
			while(j <= n and a[i][0] == a[j][0]) ++j;
			int len = j - i;
			res += len * (len - 1) / 2;
			i = j;
		}
	}
	{
		sort(a+1, a+n+1, [](const ai2 &x, const ai2 &y){
			return x[1] < y[1];
		});
		int i = 1;
		while(i <= n){
			int j = i;
			while(j <= n and a[i][1] == a[j][1]) ++j;
			int len = j - i;
			res += len * (len - 1) / 2;
			i = j;
		}
	}
	{
		sort(a+1, a+n+1);
		int i = 1;
		while(i <= n){
			int j = i;
			while(j <= n and a[i] == a[j]) ++j;
			int len = j - i;
			res -= len * (len - 1) / 2;
			i = j;
		}
	}
	cout << res;
}

signed main(){
	ios::sync_with_stdio(0); cin.tie(0);
	
	int o = 1; ///cin >> o;
	while(o --> 0) solve();
}
