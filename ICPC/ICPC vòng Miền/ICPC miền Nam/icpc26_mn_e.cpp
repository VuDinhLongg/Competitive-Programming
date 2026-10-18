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

struct node{
	int l, r, ans0, ans1, lazy;
	node(){
		l = r = ans0 = ans1 = lazy = 0;
	}
	node(int a0, int a1){
		l = r = lazy = 0;
		ans0 = a0;
		ans1 = a1;
	}
};

int k, q, w[31], cnt;
vector<node> seg;

void merge(node &ans, node l, node r, int len){
	ans.ans0 = min(l.ans0 + r.ans0, l.ans1 + r.ans1 + w[__lg(len)]);
	ans.ans1 = min(l.ans1 + r.ans1, l.ans0 + r.ans0 + w[__lg(len)]);
}

void apply(int id, int l, int r){
	swap(seg[id].ans0, seg[id].ans1);
	seg[id].lazy ^= 1;
}

void push(int id, int l, int m, int r){
	if(seg[id].lazy){
		apply(seg[id].l, l, m);
		apply(seg[id].r, m + 1, r);
		seg[id].lazy = 0;
	}
}

void update(int id, int l, int r, int u, int v){
	if(r < u or v < l) return;
	// cout << id << ' ' << l << ' ' << r, el;
	if(u <= l and r <= v){
		apply(id, l, r);
		return;
	}
	int m = l + r >> 1;
	if(seg[id].l == 0){
		seg[id].l = ++cnt;
		seg.pub(node(0, w[__lg(m - l + 1)]));
	}
	if(seg[id].r == 0){
		seg[id].r = ++cnt;
		seg.pub(node(0, w[__lg(r - m)]));
	}
	push(id, l, m, r);
	if(seg[id].l) update(seg[id].l, l, m, u, v);
	if(seg[id].r) update(seg[id].r, m + 1, r, u, v);
	merge(seg[id], seg[seg[id].l], seg[seg[id].r], r - l + 1);
}

void solve(){
	cin >> k >> q;
	fo(i, 0, k){
		cin >> w[i];
		if(i > 0 and w[i] > w[i - 1] * 2) w[i] = w[i - 1] * 2;
	}
	seg.pub(node(0, w[k]));
	while(q--){
		int l, r; cin >> l >> r;
		update(0, 0, (1<<k) - 1, l, r);
		cout << seg[0].ans0, el;
	}
}

signed main(){
	ios::sync_with_stdio(0); cin.tie(0);
	
	int o = 1; ///cin >> o;
	while(o --> 0) solve();
}
