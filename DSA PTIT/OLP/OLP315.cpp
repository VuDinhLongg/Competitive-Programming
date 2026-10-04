#include <bits/stdc++.h>
using namespace std;

template<class X, class Y> bool maxi(X &x, const Y &y){ return x < y ? x = y, 1 : 0; }
template<class X, class Y> bool mini(X &x, const Y &y){ return x > y ? x = y, 1 : 0; }

#define el cout << '\n'
#define fo(i, a, b) for(int32_t i=a; i<=b; ++i)
#define fd(i, a, b) for(int32_t i=a; i>=b; --i)
#define ret(x) return void(cout << (x) << '\n')
#define all(x) begin(x),end(x)
#define len(x) (int)(x).size()
#define int long long
#define mxn 100'007

int n, m, dp[1005][1005];
vector<int> g[26][1005];

void solve(){
	cin >> n >> m;
	fo(u, 1, n) fo(v, 1, n){
		if(u != v) dp[u][v] = 1e9;
	}
	fo(i, 1, m){
		int u, v; char c;
		cin >> u >> v >> c;
		g[c - 'a'][u].push_back(v);
		g[c - 'a'][v].push_back(u);
		mini(dp[u][v], 1);
		mini(dp[v][u], 1);
	}
	queue<pair<int, int>> q;
	fo(u, 1, n) q.push({u, u});
	fo(u, 1, n) fo(v, 1, n) if(dp[u][v] == 1){
		q.push({u, v});
	}
	while(len(q)){
		auto [u, v] = q.front(); q.pop();
		fo(o, 0, 25){
			for(int &uu : g[o][u]) for(int &vv : g[o][v]){
				if(mini(dp[uu][vv], dp[u][v] + 2)){
					q.push({uu, vv});
				}
			}
		}
	}
	cout << (dp[1][n] < 1e9 ? dp[1][n] : -1), el;
	fo(o, 0, 25){
		fo(u, 1, n) g[o][u].clear();
	}
}

signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0);

	int o = 1; cin >> o;
	while(o --> 0) solve();
}
