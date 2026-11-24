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
// #define int long long -> TLE (9/10)
#define mxn 1'000'007
#define ll long long

struct node{
	int min, lazy;
	ll sum;
	node(int m = 1e9, ll s = 0, int l = 0){
		min = m; sum = s; lazy = l;
	}
};

int n, m, q, red, a[1005][1005];
node seg[1005][1005 * 4];

node merge(const node &l, const node &r){
	return node(min<ll>(l.min, r.min), l.sum + r.sum, 0);
}

void build(int id, int l, int r, int o){
	if(l == r){
		seg[o][id] = node(a[o][l], a[o][l], 0); return;
	}
	int mid = l + r >> 1;
	build(id * 2, l, mid, o);
	build(id * 2 + 1, mid + 1, r, o);
	seg[o][id] = merge(seg[o][id * 2], seg[o][id * 2 + 1]);
}

inline void apply(int id, int l, int r, int x, int o){
	seg[o][id] = node(x, 1ll * x * (r - l + 1), x);
}

inline void push(int id, int l, int mid, int r, int o){
	apply(id * 2, l, mid, seg[o][id].lazy, o);
	apply(id * 2 + 1, mid + 1, r, seg[o][id].lazy, o);
	seg[o][id].lazy = 0;
}

inline void upd(int id, int l, int r, int u, int v, int x, int o){
	if(r < u or v < l or u > v) return;
	if(u <= l and r <= v){
		apply(id, l, r, x, o); return;
	}
	int mid = l + r >> 1;
	if(seg[o][id].lazy) push(id, l, mid, r, o);
	upd(id * 2, l, mid, u, v, x, o);
	upd(id * 2 + 1, mid + 1, r, u, v, x, o);
	seg[o][id] = merge(seg[o][id * 2], seg[o][id * 2 + 1]);
}

inline node get(int id, int l, int r, int u, int v, int o){
	if(r < u or v < l or u > v) return node(1e9, 0, 0);
	if(u <= l and r <= v) return seg[o][id];
	int mid = l + r >> 1;
	if(seg[o][id].lazy) push(id, l, mid, r, o);
	return merge(get(id * 2, l, mid, u, v, o), get(id * 2 + 1, mid + 1, r, u, v, o));
}

namespace sub1{
	bool check(){
		return n <= 400 and m <= 400;
	}
	void solve(){
		while(q--){
			int t; cin >> t;
			if(t == 1){
				ll s;
				int c1, r1, c2, r2; cin >> s >> c1 >> r1 >> c2 >> r2;
				bool ok = 1;
				fo(i, r1, r2){
					fo(j, c1, c2) if(a[i][j] < red){
						ok = 0; break;
					}
					if(ok == 0) break;
				}
				if(ok){
					ll res = 0;
					fo(i, r1, r2){
						if((i - r1 + 1) & 1){
							fo(j, c1, c2){
								int add = min<ll>(a[i][j] - red, s - res);
								res += add;
								a[i][j] -= add;
							}
						}else{
							fd(j, c2, c1){
								int add = min<ll>(a[i][j] - red, s - res);
								res += add;
								a[i][j] -= add;
							}
						}
					}
					cout << res, el;
				}else cout << 0, el;
			}else{
				cin >> red;
			}
		}
	}
}

namespace sub2{
	bool check(){
		return 1;
	}
	ll pre[1005];
	void solve(){
		fo(i, 1, n) build(1, 1, m, i);
		while(q--){
			int t; cin >> t;
			if(t == 1){
				int s, c1, r1, c2, r2; cin >> s >> c1 >> r1 >> c2 >> r2;
				node cur = node(1e9, 0, 0);
				fo(i, r1, r2){
					node o = get(1, 1, m, c1, c2, i);
					cur = merge(cur, o);
					pre[i - r1 + 1] = pre[i - r1] + o.sum;
				}
				if(cur.min >= red){
					auto find_pos = [&](int mid){
						int col = c2 - c1 + 1;
						int i = mid / col;
						int rem = mid % col;
						if(rem) ++i;
						int j = 0;
						if(i & 1) j = c1 + (rem ? rem : col) - 1;
						else j = c2 - (rem ? rem : col) + 1;
						return make_pair(i, j);
					};
					auto calc = [&](int mid){
						int col = c2 - c1 + 1;
						int i = mid / col;
						ll res = pre[i] - red * mid;
						int rem = mid % col;
						if(rem) ++i;
						int j = 0;
						if(i & 1){
							j = c1 + (rem ? rem : col) - 1;
							if(rem) res += get(1, 1, m, c1, j, r1 + i - 1).sum;
						}else{
							j = c2 - (rem ? rem : col) + 1;
							if(rem) res += get(1, 1, m, j, c2, r1 + i - 1).sum;
						}
						if(res > s){
							ll need = res - s + red;
							if(get(1, 1, m, j, j, r1 + i - 1).sum >= need) res = s;
						}
						return res;
					};
					int lim = (c2 - c1 + 1) * (r2 - r1 + 1);
					int l = 0, r = lim + 1;
					while(r - l > 1){
						int mid = l + r >> 1;
						if(calc(mid) <= s) l = mid;
						else r = mid;
					}
					cout << calc(l), el;
					// update
					auto [x, y] = find_pos(l);
					// cout << "*" << l << ' ' << x << ' ' << y, el;
					ll sum = pre[x - 1] - red * l;
					if(x & 1) sum += get(1, 1, m, c1, y, r1 + x - 1).sum;
					else sum += get(1, 1, m, y, c2, r1 + x - 1).sum;
					fo(i, r1, r1 + x - 2) upd(1, 1, m, c1, c2, red, i);
					if(x & 1) upd(1, 1, m, c1, y - 1, red, r1 + x - 1);
					else upd(1, 1, m, y + 1, c2, red, r1 + x - 1);
					if(sum > s) upd(1, 1, m, y, y, red + sum - s, r1 + x - 1);
					else upd(1, 1, m, y, y, red, r1 + x - 1);
				}else cout << 0, el;
			}else{
				cin >> red;
			}
			// fo(i, 1, n){
			// 	fo(j, 1, m){
			// 		cout << get(1, 1, m, j, j, i).sum << ' ';
			// 	}el;
			// }el;
		}
	}
}

void solve(){
	cin >> n >> m;
	fo(i, 1, n) fo(j, 1, m){
		cin >> a[i][j];
	}
	cin >> q >> red;
	if(sub1::check()) sub1::solve();
	else sub2::solve();
}

signed main(){
	ios::sync_with_stdio(0); cin.tie(0);
	
	int o = 1; ///cin >> o;
	while(o --> 0) solve();
}
