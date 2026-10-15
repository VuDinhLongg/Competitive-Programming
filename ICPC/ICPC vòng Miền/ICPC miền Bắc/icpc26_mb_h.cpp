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
#define rep(i, n) fo(i, 0, n - 1)
#define fo(i, a, b) for(int32_t i=a; i<=b; ++i)
#define fd(i, a, b) for(int32_t i=a; i>=b; --i)
#define ret(x) return void(cout << (x) << '\n')
#define fix(x) fixed << setprecision(x)
#define all(x) begin(x),end(x)
#define len(x) (int)(x).size()
#define vec vector
#define pub push_back
#define pob pop_back
#define pii pair<int, int>
#define fi first
#define se second
#define int long long
#define mxn 100'007
#define ldb long double
#define pll pair<ldb, ldb>

const ldb pi = acos(-1.0L);

int n, m, xc, yc, r, a[mxn], b[mxn], c[mxn], d[mxn];
vec<pll> v1, v2;
vec<pii> o1, o2;

ldb dist(int x[], int y[], int i){
	return sqrtl(x[i] * x[i] + y[i] * y[i]);
}

inline void LonggVuz(){
	cin >> n >> m >> xc >> yc >> r;
	fo(i, 1, n){
		cin >> a[i] >> b[i];
		a[i] -= xc;
		b[i] -= yc;
	}
	fo(i, 1, m){
		cin >> c[i] >> d[i];
		c[i] -= xc;
		d[i] -= yc;
	}
	fo(i, 1, n){
		ldb dis = dist(a, b, i);
		ldb alpha = acosl(r / dis);
		ldb delta = atan2l((ldb)b[i], (ldb)a[i]);
		ldb lo = delta - alpha;
		ldb hi = delta + alpha;
		v1.pub({lo, hi});
	}
	fo(i, 1, m){
		ldb dis = dist(c, d, i);
		ldb alpha = acosl(r / dis);
		ldb delta = atan2l((ldb)d[i], (ldb)c[i]);
		ldb lo = delta - alpha;
		ldb hi = delta + alpha;
		v2.pub({lo, hi});
	}
	dbg(v1);
	dbg(v2);
	int res = 0;
	// fo(i, 1, n){
	// 	fo(j, 1, m){
	// 		fo(k, -1, 1){
	// 			if(!(v1[i - 1].se < v2[j - 1].fi + pi * k * 2 or v1[i - 1].fi > v2[j - 1].se + pi * k * 2)){
	// 				++res;
	// 				break;
	// 			}
	// 		}
	// 	}
	// }
	vec<ldb> x, y;
	fo(i, 1, n){
		x.pub(v1[i - 1].fi);
		y.pub(v1[i - 1].se);
	}
	sort(all(x));
	sort(all(y));
	fo(j, 1, m){
		fo(k, -1, 1){
			ldb xx = v2[j - 1].fi + pi * k * 2;
			ldb yy = v2[j - 1].se + pi * k * 2;
			int lo = lower_bound(all(y), xx) - begin(y) - 1;
			int hi = upper_bound(all(x), yy) - begin(x);
			res += n - (lo + 1) - (len(x) - hi);
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
