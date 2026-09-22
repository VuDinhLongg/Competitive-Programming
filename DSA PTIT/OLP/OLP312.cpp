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

int n, mid;
vector<int> v;
deque<int> dq;

int rev(int n){
	int r = 0;
	while(n){
		if(n % 10 == 0) return 0;
		r = r * 10 + n % 10;
		n /= 10;
	}
	return r;
}

bool backtrack(int pos, int cur, bool o = 0){
	if(cur == 1) return 1;
	fd(i, pos, 0){
		int x = v[i];
		int y = rev(x);
		if(o == 0 and cur % x == 0 and x == y){
			mid = x;
			if(backtrack(i, cur / x, 1)) return 1;
			mid = 1;
		}
		if(cur % x == 0 and (cur / x) % y == 0){
			dq.push_front(x);
			dq.push_back(y);
			if(backtrack(i, cur / x / y, o)) return 1;
			dq.pop_front();
			dq.pop_back();
		}
	}
	return 0;
}

inline void LonggVuz(){
	cin >> n;
	if(n == rev(n)) ret(n);
	vector<int> d;
	for(int i = 1; i * i <= n; ++i) if(n % i == 0){
		d.push_back(i);
		if(i * i != n) d.push_back(n / i);
	}
	sort(all(d));
	v.clear();
	for(int &i : d) if(i > 1){
		int j = rev(i);
		if(j and n % j == 0) v.push_back(i);
	}
	dq.clear();
	mid = 1;
	if(backtrack(len(v) - 1, n)){
		fo(i, 0, len(dq) - 1){
			if(i == len(dq) / 2) cout << mid << '*';
			cout << dq[i];
			if(i < len(dq) - 1) cout << '*';
		}
		el;
	}else ret(-1);
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
