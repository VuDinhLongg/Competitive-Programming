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

struct edge{
	int u, v, w;
};

struct query{
	int i, v, k;
};

int n, q, a[mxn], l[mxn], r[mxn];
vector<edge> edges;
vector<query> queries;
vector<int> cand[mxn];
int dsu[mxn], sum[mxn];

int find(int u){
	return u == dsu[u] ? u : dsu[u] = find(dsu[u]);
}

bool merge(int u, int v){
	u = find(u); v = find(v);
	if(u == v) return 0;
	sum[u] += sum[v];
	dsu[v] = u;
	return 1;
}

void solve(){
	cin >> n >> q;
	fo(i, 1, n) cin >> a[i];
	fo(i, 2, n){
		int u, v, w; cin >> u >> v >> w;
		edges.pub({u, v, w});
	}
	edges.pub({0, 0, 0});
	sort(all(edges), [](edge &e1, edge &e2){
		return e1.w < e2.w;
	});
	rep(i, q){
		int v, k; cin >> v >> k;
		queries.pub({i, v, k});
		l[i] = -1; r[i] = n;
	}
	while(1){
		bool stop = 1;
		fo(u, 1, n){
			dsu[u] = u;
			sum[u] = a[u];
		}
		rep(i, q) if(r[i] - l[i] > 1){
			stop = 0;
			cand[l[i] + r[i] >> 1].pub(i);
		}
		if(stop) break;
		rep(i, n){
			merge(edges[i].u, edges[i].v);
			for(int &idx : cand[i]){
				auto &[o, v, k] = queries[idx];
				if(sum[find(v)] >= k) r[o] = i;
				else l[o] = i;
			}
			cand[i].clear();
		}
	}
	rep(i, q) cout << (r[i] < n ? edges[r[i]].w : -1), el;
}

signed main(){
	ios::sync_with_stdio(0); cin.tie(0);
	
	int o = 1; ///cin >> o;
	while(o --> 0) solve();
}
