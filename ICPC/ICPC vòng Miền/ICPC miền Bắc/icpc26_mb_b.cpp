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
#define mxn 1'000'007

int n, m, q1, q2, a[1005][1005], s[1005][1005];

int get(int x, int y, int u, int v){
	return s[u][v] - s[x - 1][v] - s[u][y - 1] + s[x - 1][y - 1];
}

inline void LonggVuz(){
	cin >> n >> m >> q1 >> q2;
	fo(i, 1, n) fo(j, 1, m){
		cin >> a[i][j];
		s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
	}
	while(q1--){
		int L, i, maxVal; cin >> L >> i >> maxVal;
		int res = 0, sum = 0, l = L;
		fo(r, L, m){
			sum += get(i - L + 1, r - L + 1, i, r) * a[i][r];
			while(sum > maxVal){
				sum -= get(i - L + 1, l - L + 1, i, l) * a[i][l];
				++l;
			}
			maxi(res, r - l + 1);
		}
		cout << res, el;
	}
	while(q2--){
		int L, i, minVal, maxVal; cin >> L >> i >> minVal >> maxVal;
		int res = 0, sum1 = 0, sum2 = 0, l1 = L, l2 = L;
		fo(r, L, m){
			sum1 += get(i - L + 1, r - L + 1, i, r) * a[i][r];
			sum2 += get(i - L + 1, r - L + 1, i, r) * a[i][r];
			while(sum1 > maxVal){
				sum1 -= get(i - L + 1, l1 - L + 1, i, l1) * a[i][l1];
				++l1;
			}
			while(l2 < r and sum2 - get(i - L + 1, l2 - L + 1, i, l2) * a[i][l2] >= minVal){
				sum2 -= get(i - L + 1, l2 - L + 1, i, l2) * a[i][l2];
				++l2;
			}
			if(minVal <= min(sum1, sum2) and max(sum1, sum2) <= maxVal) res += l2 - l1 + 1;
		}
		cout << res, el;
	}
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
