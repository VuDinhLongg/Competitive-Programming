#include <bits/stdc++.h>
using namespace std;

template<class X> using max_heap = priority_queue<X, vector<X>, less<X>>;
template<class X> using min_heap = priority_queue<X, vector<X>, greater<X>>;
template<class X, class Y> bool maxi(X &x, const Y &y){ return x < y ? x = y, 1 : 0; }
template<class X, class Y> bool mini(X &x, const Y &y){ return x > y ? x = y, 1 : 0; }

#define el cout << '\n'
#define rep(i, n) fo(i, 0, (n) - 1)
#define fo(i, a, b) for(int i=(a); i<=(b); ++i)
#define fd(i, a, b) for(int i=(a); i>=(b); --i)
#define ret(x) return void(cout << (x) << '\n')
#define all(x) begin(x),end(x)
#define len(x) (int)(x).size()
#define int long long
#define mxn 200'007

int n, res, bit[mxn];
int in[mxn], out[mxn], now;
vector<int> g[mxn], cnt[mxn];

void add(int i, int x){
	while(i <= n){
		bit[i] += x;
		i += i & -i;
	}
}

int get(int i){
	int r = 0;
	while(i >= 1){
		r += bit[i];
		i -= i & -i;
	}
	return r;
}

void dfs(int u, int p){
	in[u] = ++now;
	for(int &v : g[u]) if(v != p){
		dfs(v, u);
	}
	out[u] = now;
}

void dfs2(int u, int p){
	int tmp = get(u - 1);
	sort(all(cnt[in[u] - 1]));
	int tmp2 = lower_bound(all(cnt[in[u] - 1]), u) - begin(cnt[in[u] - 1]);
	if(tmp2 > 0) tmp += tmp2;
	res += tmp;
	// cout << u << ' ' << in[u] << ' ' << out[u] << ' ' << tmp, el;
	int mx = 0;
	for(int &v : g[u]) if(v != p){
		maxi(mx, v);
		if(mx) add(mx, +1);
		dfs2(v, u);
		if(mx) add(mx, -1);
	}
	cnt[out[u]].push_back(mx);
}

void solve(){
	cin >> n;
	fo(i, 2, n){
		int u, v; cin >> u >> v;
		++u; ++v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	fo(u, 1, n) sort(all(g[u]));
	now = 0;
	dfs(1, 0);
	res = 0;
	dfs2(1, 0);
	cout << res, el;
	fo(u, 1, n){
		bit[u] = 0;
		cnt[u].clear();
		g[u].clear();
	}
}

signed main(){
	ios::sync_with_stdio(0); cin.tie(0);
	
	int o = 1; cin >> o;
	while(o --> 0) solve();
}
