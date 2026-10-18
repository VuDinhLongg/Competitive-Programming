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
#define mxn 1'000'007

int n, m, x, y, vx, vy, q;

void solve(){
	cin >> n >> m >> x >> y >> vx >> vy >> q;
	while(q--){
		int t; cin >> t;
		int tx = (t * abs(vx)) % ((n - 1) * 2);
		int ty = (t * abs(vy)) % ((m - 1) * 2);
		int nx = x + tx * (vx > 0 ? 1 : -1);
		int ny = y + ty * (vy > 0 ? 1 : -1);
		if(nx < 1){
			if(1 - nx <= n - 1){
				nx = 1 + (1 - nx);
			}else{
				int r = (1 - nx) - (n - 1);
				nx = n - r;
			}
		}
		if(nx > n){
			if(nx - n <= n - 1){
				nx = n - (nx - n);
			}else{
				int r = nx - n - (n - 1);
				nx = 1 + r;
			}
		}
		if(ny < 1){
			if(1 - ny <= m - 1){
				ny = 1 + (1 - ny);
			}else{
				int r = (1 - ny) - (m - 1);
				ny = m - r;
			}
		}
		if(ny > m){
			if(ny - m <= m - 1){
				ny = m - (ny - m);
			}else{
				int r = ny - m - (m - 1);
				ny = 1 + r;
			}
		}
		cout << nx << ' ' << ny, el;
	}
}

signed main(){
	ios::sync_with_stdio(0); cin.tie(0);
	
	int o = 1; ///cin >> o;
	while(o --> 0) solve();
}
