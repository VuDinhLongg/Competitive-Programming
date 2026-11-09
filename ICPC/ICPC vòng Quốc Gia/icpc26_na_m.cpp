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
#define mxn 1'000'007

struct node{
	int sum, ans;
	node(int _sum = -1e18, int _ans = -1e18){
		sum = _sum; ans = _ans;
	}
};

int n, c[mxn], pos[mxn], a[mxn];
node seg[mxn * 4];

node merge(const node &l, const node &r){
	if(l.ans == -1e18) return r;
	if(r.ans == -1e18) return l;
	node o;
	o.sum = l.sum + r.sum;
	o.ans = max(r.ans, r.sum + l.ans);
	return o;
}

void update(int id, int l, int r, int i, int x){
	if(l == r){
		seg[id] = node(x, x); return;
	}
	int mid = l + r >> 1;
	if(i <= mid) update(id * 2, l, mid, i, x);
	else update(id * 2 + 1, mid + 1, r, i, x);
	seg[id] = merge(seg[id * 2], seg[id * 2 + 1]);
}

void solve(){
	cin >> n;
	fo(i, 1, n) cin >> c[i];
	fo(i, 1, n) cin >> a[i];
	int res = -1e18;
	fo(i, 1, n){
		if(pos[c[i]]) update(1, 1, n, pos[c[i]], 0);
		pos[c[i]] = i;
		update(1, 1, n, pos[c[i]], a[i]);
		maxi(res, seg[1].ans);
		// cout << i << ' ' << res, el;
	}
	cout << res, el;
	fo(i, 1, n) pos[c[i]] = 0;
	fo(i, 1, n * 4) seg[i] = node();
}

signed main(){
	ios::sync_with_stdio(0); cin.tie(0);
	
	int o = 1; cin >> o;
	while(o --> 0) solve();
}
