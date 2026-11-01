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
#define ii pair<int, int>
#define fi first
#define se second

struct edge{
    int u, v, w;
};

int n, m, q, st, en, d[2][mxn], p[2][mxn], f[2][mxn];
vector<ii> g[mxn], t[mxn];
map<int, int> mark[mxn];

void dijkstra(int s, int o){
    fo(u, 1, n) d[o][u] = 1e18;
    d[o][s] = 0;
    min_heap<ii> pq;
    pq.push({d[o][s], s});
    while(len(pq)){
        auto [cur, u] = pq.top(); pq.pop();
        if(cur > d[o][u]) continue;
        for(auto &[v, w] : g[u]){
            if(mini(d[o][v], d[o][u] + w)){
                p[o][v] = u;
                f[o][v] = w; 
                pq.push({d[o][v], v});
            }
        }
    }
}

int h[mxn], dad[20][mxn], sz[mxn];
int pos[mxn], head[mxn], now;
int seg[mxn * 4], lz[mxn * 4];

void dfs(int u){
    sz[u] = 1;
    int idx = -1;
    fo(i, 0, len(t[u]) - 1){
        auto &[v, w] = t[u][i];
        if(v == dad[0][u]) continue;
        h[v] = h[u] + 1;
        dad[0][v] = u;
        fo(k, 1, 19) dad[k][v] = dad[k - 1][dad[k - 1][v]];
        dfs(v);
        sz[u] += sz[v];
        if(idx == -1 or sz[t[u][idx].fi] < sz[v]) idx = i;
    }
    if(idx > -1) swap(t[u][idx], t[u][0]);
}

void dfs_hld(int u){
    pos[u] = ++now;
    for(auto &[v, w] : t[u]) if(v != dad[0][u]){
        if(v == t[u][0].fi) head[v] = head[u];
        else head[v] = v;
        dfs_hld(v);
    }
}

void build(int id, int l, int r){
    if(l == r){
        seg[id] = lz[id] = 1e18;
        return;
    }
    int m = l + r >> 1;
    build(id * 2, l, m);
    build(id * 2 + 1, m + 1, r);
    seg[id] = lz[id] = 1e18;
}

void apply(int id, int x){
    mini(seg[id], x);
    mini(lz[id], x);
}

void push(int id){
    if(lz[id] < 1e18){
        apply(id * 2, lz[id]);
        apply(id * 2 + 1, lz[id]);
        lz[id] = 1e18;
    }
}

void upd(int id, int l, int r, int u, int v, int x){
    if(r < u or v < l) return;
    if(u <= l and r <= v){
        apply(id, x); return;
    }
    push(id);
    int m = l + r >> 1;
    upd(id * 2, l, m, u, v, x);
    upd(id * 2 + 1, m + 1, r, u, v, x);
    seg[id] = min(seg[id * 2], seg[id * 2 + 1]);
}

int get(int id, int l, int r, int i){
    if(l == r) return seg[id];
    push(id);
    int m = l + r >> 1;
    if(i <= m) return get(id * 2, l, m, i);
    return get(id * 2 + 1, m + 1, r, i);
}

void update(int u, int v, int val){
    while(head[u] != head[v]){
        if(pos[u] < pos[v]) swap(u, v);
        // cout << head[u] << ' ' << u, el;
        upd(1, 1, n, pos[head[u]], pos[u], val);
        u = dad[0][head[u]];
    }
    if(u == v) return;
    if(pos[u] > pos[v]) swap(u, v);
    // cout << u << ' ' << v, el;
    int uu = v, d = h[v] - h[u] - 1;
    fd(k, 19, 0) if(d >> k & 1){
        uu = dad[k][uu];
    }
    // cout << u << ' ' << uu << ' ' << v, el;
    upd(1, 1, n, pos[uu], pos[v], val);
}

void solve(){
	cin >> n >> m;
    vector<edge> edges;
    fo(i, 1, m){
        int u, v, w; cin >> u >> v >> w;
        ++u; ++v;
        g[u].pub({v, w});
        g[v].pub({u, w});
        edges.pub({u, v, w});
    }
    cin >> st >> en >> q; ++st; ++en;
    dijkstra(st, 0);
    if(d[0][en] == 1e18){
        while(q--){
            int u, v; cin >> u >> v;
            ++u; ++v;
            cout << "Infinity", el;
        }
        return;
    }
    {
        int cur = en;
        while(cur != st){
            int nxt = p[0][cur];
            mark[cur][nxt] = mark[nxt][cur] = 1;
            cur = nxt;
        }
        fo(u, 1, n) if(p[0][u]){
            // cout << u << ' ' << p[0][u], el;
            int v = p[0][u], w = f[0][u];
            t[u].pub({v, w});
            t[v].pub({u, w});
        }
    }
    dijkstra(en, 1);
    dfs(st);
    head[st] = st;
    dfs_hld(st);
    // fo(u, 1, n) cout << u << ' ' << head[u], el;
    build(1, 1, n);
    for(auto &[u, v, w] : edges) if(!mark[u].count(v)){
        int w1 = d[0][u] + w + d[1][v];
        int w2 = d[0][v] + w + d[1][u];
        // cout << u << ' ' << v << ' ' << min(w1, w2), el;
        update(u, v, min(w1, w2));
    }
    while(q--){
        int u, v; cin >> u >> v;
        ++u; ++v;
        if(mark[u].count(v)){
            if(v == dad[0][u]) swap(u, v);
            int res = get(1, 1, n, pos[v]);
            if(res < 1e18) cout << res, el;
            else cout << "Infinity", el;
        }else{
            int res = d[0][en];
            if(res < 1e18) cout << res, el;
            else cout << "Infinity", el;
        }
    }
}

signed main(){
	ios::sync_with_stdio(0); cin.tie(0);
	
	int o = 1; ///cin >> o;
	while(o --> 0) solve();
}
