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
#define mxn 200'007

int n, R[mxn], p[mxn], bit[mxn];

void update(int i, int x){
	while(i <= n){
		bit[i] += x;
		i += i & -i;
	}
}

int query(int i){
	int r = 0;
	while(i >= 1){
		r += bit[i];
		i -= i & -i;
	}
	return r;
}

int walk(int k){
	int pos = 0, cur = 0;
	fd(i, 20, 0){
		int nxt = pos + (1 << i);
		if(nxt <= n and cur + bit[nxt] < k){
			cur += bit[nxt];
			pos = nxt;
		}
	}
	return pos + 1;
}

void solve(){
	cin >> n;
	fo(i, 1, n) cin >> R[i];
	fo(i, 1, n) update(i, +1);
	fd(i, n, 1){
		int pivot_index = 1 + (R[n - i + 1] % i);
		// cout << pivot_index, el;
		int idx = walk(pivot_index);
		p[idx] = i;
		update(idx, -1);
	}
	fo(i, 1, n) cout << p[i] << ' ';
}

signed main(){
	ios::sync_with_stdio(0); cin.tie(0);
	
	int o = 1; ///cin >> o;
	while(o --> 0) solve();
}
