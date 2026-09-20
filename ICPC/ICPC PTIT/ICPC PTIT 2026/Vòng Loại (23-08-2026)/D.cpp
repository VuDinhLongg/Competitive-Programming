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

int n;
vector<int> v;
string s;

int calc(){
	int res = 0;
	fo(i, 0, len(s) - 1){
		int r = 0;
		fo(j, i, len(s) - 1){
			r = (r * 10 + (s[j] - '0')) % 7;
			if(r == 0) ++res;
		}
	}
	return res;
}

void backtrack(int i){
	string pre = s;
	s += string(v[i], '7');
	if(i == len(v) - 1){
		if(calc() == n){
			cout << s;
			exit(0);
		}
	}else{
		fo(x, 1, 9){
			string pre = s;
			s += to_string(x);
			backtrack(i + 1);
			s = pre;
		}
	}
	s = pre;
}

inline void LonggVuz(){
	cin >> n;
	int tmp = n;
	fd(i, 2e3, 1) if(tmp >= (i * (i + 1) / 2)){
		v.push_back(i);
		tmp -= i * (i + 1) / 2;
		++i;
	}
	backtrack(0);
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