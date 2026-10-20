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

int n, m, k;
vector<vector<char>> a;

bool check(int mid){
	int need = 0;
	fo(i, 1, n){
		int last = -1e9;
		fo(j, 1, m){
			if(a[i][j] == 'x'){
				if(last + mid < j){
					++need;
					if(need > k) return 0;
					last = j + mid;
				}
			}else if(a[i][j] == '#'){
				last = -1e9;
			}
		}
	}
	return 1;
}

void solve(){
	cin >> n >> m >> k;
	a.assign(n + 5, vector<char>(m + 5, ' '));
	fo(i, 1, n) fo(j, 1, m){
		cin >> a[i][j];
	}
	int l = -1, r = m;
	while(r - l > 1){
		int mid = l + r >> 1;
		if(check(mid)) r = mid;
		else l = mid;
	}
	cout << (r < m ? r : -1);
}

signed main(){
	ios::sync_with_stdio(0); cin.tie(0);
	
	int o = 1; ///cin >> o;
	while(o --> 0) solve();
}
