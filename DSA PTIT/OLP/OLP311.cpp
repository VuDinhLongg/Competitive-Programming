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
#define fo(i, a, b) for(int32_t i=a; i<=b; ++i)
#define fd(i, a, b) for(int32_t i=a; i>=b; --i)
#define ret(x) return void(cout << (x) << '\n')
#define all(x) begin(x),end(x)
#define len(x) (int)(x).size()
#define int long long
#define mxn 1'000'007
#define ai3 array<int, 3>
#define ai4 array<int, 4>
#define ii pair<int, int>
#define fi first
#define se second

const int mod1 = 1e9 + 7;
const int mod2 = 1e9 + 9;
const int mod3 = 998244353;
const int mod4 = 998244853;

int n;
string a[1005];
ai4 f[1005];
map<ai4, int> cnt;

ai4 hashing(const string &s){
	int r1 = 0, r2 = 0, r3 = 0, r4 = 0;
	for(char c : s){
		r1 = (r1 * 10 + c - '0') % mod1;
		r2 = (r2 * 10 + c - '0') % mod2;
		r3 = (r3 * 10 + c - '0') % mod3;
		r4 = (r4 * 10 + c - '0') % mod4;
	}
	return {r1, r2, r3, r4};
}

ai4 calc(const ai4 &x, const ai4 &y){
	return {x[0] * y[0] % mod1, x[1] * y[1] % mod2,
			x[2] * y[2] % mod3, x[3] * y[3] % mod4};
}

inline void LonggVuz(){
	cin >> n;
	fo(i, 1, n){
		cin >> a[i];
		f[i] = hashing(a[i]);
		dbg(a[i], f[i]);
		++cnt[f[i]];
	}
	int res = 0;
	fo(i, 1, n) fo(j, i, n){
		if(len(a[i]) + len(a[j]) > 1005) continue;
		ai4 tmp = calc(f[i], f[j]);
		if(cnt.count(tmp)){
			res += cnt[tmp];
			if(i != j) res += cnt[tmp];
		}
	}
	cout << res;
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
