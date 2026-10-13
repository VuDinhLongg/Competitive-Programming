#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <debug.h>
#else
#define dbg(...) 1608
#define orz(...) 2005
#endif

template<class X, class Y> bool maxi(X &x, const Y &y){ return x < y ? x = y, 1 : 0; }
template<class X, class Y> bool mini(X &x, const Y &y){ return x > y ? x = y, 1 : 0; }

#define el cout << '\n'
#define ve vector
#define pb push_back
#define po pop_back
#define ii pair<int, int>
#define fi first
#define se second
#define rep(i, n) fo(i, 0, n - 1)
#define fo(i, a, b) for(int32_t i=a; i<=b; ++i)
#define fd(i, a, b) for(int32_t i=a; i>=b; --i)
#define ret(x) return void(cout << (x) << '\n')
#define fix(x) fixed << setprecision(x)
#define all(x) begin(x),end(x)
#define len(x) (int)(x).size()
#define int long long
#define mxn 100'007
#define mask(n) (1ll << (n))

int n, a[mxn], s[mxn];

int sum(int l, int r){
	return l <= r ? s[r] - s[l - 1] : 0;
}

int calc(int x){
	int res = 0;
	{
		int i = x;
		fo(k, 0, 39) if(mask(k) >= sum(i, x)){
			int l = 0, r = i;
			while(r - l > 1){
				int mid = l + r >> 1;
				if(sum(mid, x) <= mask(k)) r = mid;
				else l = mid;
			}
			res += (i - r + 1) * (k + 1);
			i = r - 1;
			if(i < 1) break;
		}
	}
	{
		int i = x + 1;
		fo(k, 0, 39) if(mask(k) >= sum(x + 1, i)){
			int l = i, r = n + 1;
			while(r - l > 1){
				int mid = l + r >> 1;
				if(sum(x + 1, mid) <= mask(k)) l = mid;
				else r = mid;
			}
			res += (l - i + 1) * (k + 1);
			i = l + 1;
			if(i > n) break;
		}
	}
	return res;
}

void solve1(){
	int x; cin >> x;
	cout << calc(x);
}

void solve2(){
	int x = 1;
	fo(i, 2, n - 1) if(calc(i) < calc(x)) x = i;
	cout << x;
}

inline void LonggVuz(){
	int c; cin >> c;
	cin >> n;
	fo(i, 1, n) cin >> a[i], s[i] = s[i - 1] + a[i];
	if(c == 1) solve1();
	else solve2();
}

signed main(){
	ios::sync_with_stdio(false); cin.tie(nullptr);
	
	#define name "LonggVuz"
	if(fopen(name".inp", "r")){
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	
	signed o_o = 1; if(false) cin >> o_o;
	fo(c_c, 1, o_o) orz(c_c), LonggVuz();
	
	cerr << "[exec time = '" << clock() << "ms']";
}
