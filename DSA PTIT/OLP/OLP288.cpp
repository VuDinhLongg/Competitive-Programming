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

inline int GCD(int a, int b){ return b ? GCD(b, a % b) : a; }
inline int LCM(int a, int b){ return a / GCD(a, b) * b; }

bool check(int g){
	for(int i : {2, 3, 5}){
		while(g % i == 0) g /= i;
	}
	return g == 1;
}

int calc(int x){
	int res = 0;
	for(int i : {2, 3, 5}){
		while(x % i == 0){
			++res;
			x /= i;
		}
	}
	return res;
}

inline void LonggVuz(){
	int a, b; cin >> a >> b;
	int g = GCD(a, b);
	dbg(a, b, g);
	if(!check(a / g) or !check(b / g)) ret(-1);
	cout << calc(a / g) + calc(b / g), el;
}

signed main(){
	ios::sync_with_stdio(false); cin.tie(nullptr);
	
	#define name "LonggVuz"
	if(fopen(name".inp", "r")){
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	
	signed o_o = 1; if(1) cin >> o_o;
	fo(c_c, 1, o_o) orz(c_c), LonggVuz();
	
	cerr << "[exec time = '" << clock() << "ms']";
}
