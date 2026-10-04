// Sol chua chuan, nhung van AC (1.55s) ._.
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
// #define int long long
#define mxn 200'007
#define ii pair<int, int>
#define vi vector<ii>

int n, m, q, a[mxn], lz[mxn * 4];
vi seg[mxn * 4];

vi merge(const vi &l, const vi &r){
	vi v;
	int i = 0, j = 0;
	while(i < len(l) and j < len(r)){
		if(l[i].first < r[j].first){
			v.push_back(l[i++]);
		}else if(l[i].first > r[j].first){
			v.push_back(r[j++]);
		}else{
			v.push_back({l[i].first, l[i].second + r[j].second});
			++i; ++j;
		}
	}
	while(i < len(l)) v.push_back(l[i++]);
	while(j < len(r)) v.push_back(r[j++]);
	return v;
}

void build(int id, int l, int r){
	if(l == r){
		seg[id].push_back({a[l], 1}); return;
	}
	int mid = l + r >> 1;
	build(id * 2, l, mid);
	build(id * 2 + 1, mid + 1, r);
	seg[id] = merge(seg[id * 2], seg[id * 2 + 1]);
}

void apply(int id, int c){
	vi v;
	for(auto &[x, y] : seg[id]){
		v.push_back({(x + c) % m, y});
	}
	sort(all(v));
	swap(seg[id], v);
	lz[id] = (lz[id] + c) % m;
}

void push(int id){
	if(lz[id]){
		apply(id * 2, lz[id]);
		apply(id * 2 + 1, lz[id]);
		lz[id] = 0;
	}
}

void update(int id, int l, int r, int u, int v, int c){
	if(r < u or v < l) return;
	if(u <= l and r <= v){
		apply(id, c); return;
	}
	push(id);
	int mid = l + r >> 1;
	update(id * 2, l, mid, u, v, c);
	update(id * 2 + 1, mid + 1, r, u, v, c);
	seg[id] = merge(seg[id * 2], seg[id * 2 + 1]);
}

vi query(int id, int l, int r, int u, int v){
	if(r < u or v < l) return {};
	if(u <= l and r <= v) return seg[id];
	push(id);
	int mid = l + r >> 1;
	vi le = query(id * 2, l, mid, u, v);
	if(len(le) >= 2) return le;
	vi ri = query(id * 2 + 1, mid + 1, r, u, v);
	return merge(le, ri);
}

void solve(){
	cin >> n >> m >> q;
	fo(i, 1, n) cin >> a[i];
	build(1, 1, n);
	while(q--){
		int t; cin >> t;
		if(t == 1){
			int l, r, c; cin >> l >> r >> c;
			update(1, 1, n, l, r, c);
		}else{
			int l, r; cin >> l >> r;
			vi res = query(1, 1, n, l, r);
			if(len(res) >= 2) cout << 1, el;
			else cout << 0, el;
		}
	}
}

signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0);

	int o = 1; ///cin >> o;
	while(o --> 0) solve();
}
