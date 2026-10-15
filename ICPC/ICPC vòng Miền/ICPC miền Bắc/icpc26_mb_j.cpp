#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <debug.h>
#else
#define dbg(...) 1608
#define orz(...) 2005
#endif

template<class X, class Y> bool maxi(X &x, const Y &y){ return x < y ? x = y, 1 : 0; }
template<class X, class Y> bool mini(X &x, const Y &y){ return x > y ? x = y, 1 : 0; }

#define el cout << '\n'
#define ve vector
#define pb push_back
#define po pop_back
#define ii pair<int, int>
#define fi first
#define se second
#define rep(i, n) fo(i, 0, n - 1)
#define fo(i, a, b) for(int32_t i=a; i<=b; ++i)
#define fd(i, a, b) for(int32_t i=a; i>=b; --i)
#define ret(x) return void(cout << (x) << '\n')
#define fix(x) fixed << setprecision(x)
#define all(x) begin(x),end(x)
#define len(x) (int)(x).size()
#define int long long
#define mxn 200'007

struct node{
	int cnt, ans;
	node(int c = 0, int a = 0){
		cnt = c; ans = a;
	}
};

struct event{
	int x, l, r, o;
};

int n, a[mxn], l[mxn], r[mxn], s[mxn];
int rmq[20][mxn];
node seg[mxn * 4];
vector<event> events;

void update(int id, int l, int r, int u, int v, int o){
	if(r < u or v < l) return;
	if(u <= l and r <= v){
		seg[id].cnt += o;
		if(seg[id].cnt) seg[id].ans = r - l + 1;
		else{
			if(l < r) seg[id].ans = seg[id * 2].ans + seg[id * 2 + 1].ans;
			else seg[id].ans = 0;
		}
		return;
	}
	int m = l + r >> 1;
	update(id * 2, l, m, u, v, o);
	update(id * 2 + 1, m + 1, r, u, v, o);
	if(seg[id].cnt == 0) seg[id].ans = seg[id * 2].ans + seg[id * 2 + 1].ans;
}

void prepare(){
	{
		stack<int> st;
		fo(i, 1, n){
			while(len(st) and a[st.top()] <= a[i]) st.pop();
			l[i] = len(st) ? st.top() : 0;
			st.push(i);
		}
	}
	{
		stack<int> st;
		fd(i, n, 1){
			while(len(st) and a[st.top()] <= a[i]) st.pop();
			r[i] = len(st) ? st.top() : n + 1;
			st.push(i);
		}
	}
	fo(i, 1, n) rmq[0][i] = a[i];
	for(int k = 1; (1<<k) <= n; ++k){
		for(int i = 1; i + (1<<k) - 1 <= n; ++i){
			rmq[k][i] = min(rmq[k - 1][i], rmq[k - 1][i + (1<<(k-1))]);
		}
	}
	fo(i, 1, n){
		s[i] = r[i];
		fd(k, 19, 0) if(s[i] + (1<<k) - 1 <= n and rmq[k][s[i]] > a[i]) s[i] += (1<<k);
		--s[i];
	}
}

inline void LonggVuz(){
	cin >> n;
	fo(i, 1, n) cin >> a[i];
	prepare();
	fo(i, 1, n){
		events.push_back({l[i] + 1, r[i], s[i], +1});
		events.push_back({r[i]    , r[i], s[i], -1});
	}
	sort(all(events), [](const event &e1, const event &e2){
		return e1.x < e2.x;
	});
	int res = 0, i = 0;
	while(i < len(events)){
		if(i > 0){
			res += seg[1].ans * (events[i].x - events[i - 1].x);
		}
		int j = i;
		while(j < len(events) and events[j].x == events[i].x){
			update(1, 1, n, events[j].l, events[j].r, events[j].o);
			++j;
		}
		i = j;
	}
	cout << n * (n + 1) / 2 - res;
}

signed main(){
	ios::sync_with_stdio(false); cin.tie(nullptr);
	
	#define name "LonggVuz"
	if(fopen(name".inp", "r")){
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	
	signed o_o = 1; if(false) cin >> o_o;
	fo(c_c, 1, o_o) orz(c_c), LonggVuz();
	
	cerr << "[exec time = '" << clock() << "ms']";
}
