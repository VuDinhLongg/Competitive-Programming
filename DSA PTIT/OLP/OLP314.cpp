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

int a, b, x, y, m, g;
string res;

void backtrack1(int a, int b){
	if(a == 0) return;
	if(a >= b){
		int cnt = a / b;
		res += "S";
		if(cnt > 1) res += to_string(cnt);
		backtrack1(a % b, b);
	}else{
		res.push_back('W');
		backtrack1(b, a);
	}
}

void backtrack2(int x, int y){
	if(x == 0) return;
	if(x >= y){
		int cnt = x / y;
		backtrack2(x % y, y);
		res += "P";
		if(cnt > 1) res += to_string(cnt);
	}else{
		backtrack2(y, x);
		res.push_back('W');
	}
}

inline void LonggVuz(){
	cin >> a >> b >> x >> y >> m;
	backtrack1(a, b);
	backtrack2(x, y);
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
