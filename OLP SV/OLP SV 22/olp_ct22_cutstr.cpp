/*======================
   Author : @LonggVuz - RTE (70/100)
======================*/
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <debug.h>
#else
#define dbg(...) 1608
#define orz(...) 2005
#endif

#define el cout << '\n'
#define all(x) begin(x), end(x)
#define len(x) (int)(x).size()
#define out(x) return void(cout << (x) << '\n')
#define rep(i, n) for(int32_t i=0; i<n; ++i)
#define fo(i, a, b) for(int32_t i=a; i<=b; ++i)
#define fd(i, a, b) for(int32_t i=a; i>=b; --i)
#define maxi(a, b) ((a) < (b) ? (a = b, 1) : 0)
#define mini(a, b) ((a) > (b) ? (a = b, 1) : 0)
#define int long long
#define mxn 1'000'007

const int mod = 998244853;

string s;
int n, q, k, l[16], p1[mxn], p2[mxn], base1 = 67, base2 = 367;

pair<vector<int>, vector<int>> hashing(string &s){
	s = " " + s;
	vector<int> h1(n + 5), h2(n + 5);
	fo(i, 1, n){
		h1[i] = (h1[i - 1] * base1 + s[i]) % mod;
		h2[i] = (h2[i - 1] * base2 + s[i]) % mod;
	}
	return {h1, h2};
}

pair<int, int> get(int l, int r, pair<vector<int>, vector<int>> &p){
	auto &[h1, h2] = p;
	int x = (h1[r] - h1[l - 1] * p1[r - l + 1] % mod + mod) % mod;
	int y = (h2[r] - h2[l - 1] * p2[r - l + 1] % mod + mod) % mod;
	return {x, y};
}

pair<int, int> calc(){
	auto ps = hashing(s);
	string t = s;
	reverse(all(t));
	auto pt = hashing(t);
	
	vector<int> odd, even;
	fo(i, 1, n){
		if(i & 1) odd.push_back(i);
		else even.push_back(i);
	}
	
	auto check = [&](int mid){
		fo(i, 1, n - mid + 1) if(get(i, i + mid - 1, ps) == get(n - i - mid + 1 + 1, n - i + 1, pt)) return 1;
		return 0;
	};
	
	int o = 1, e = 0;
	
	{
		int l = -1, r = len(odd);
		while(r - l > 1){
			int mid = l + r >> 1;
			if(check(odd[mid])) l = mid;
			else r = mid;
		}
		o = odd[l];
	}
	{
		int l = -1, r = len(even);
		while(r - l > 1){
			int mid = l + r >> 1;
			if(check(even[mid])) l = mid;
			else r = mid;
		}
		if(l > -1) e = even[l];
	}
	return {o, e};
}

inline void LonggVuz(){
	cin >> s >> q;
	n = len(s);
	p1[0] = p2[0] = 1;
	fo(i, 1, n){
		p1[i] = p1[i - 1] * base1 % mod;
		p2[i] = p2[i - 1] * base2 % mod;
	}
	auto [odd, even] = calc();
	while(q--){
		cin >> k;
		assert(k <= 1);
		cin >> l[1];
		if(l[1] & 1){
			cout << (odd >= l[1] ? "YES" : "NO"), el;
		}else cout << (even >= l[1] ? "YES" : "NO"), el;
	}
}

signed main(){
	ios::sync_with_stdio(false); cin.tie(nullptr);
	
	signed o = 1; if(false) cin >> o;
	rep(x, o) orz(x), LonggVuz();
	
	cerr << "[exec time = `" << clock() << "ms`]";
}
