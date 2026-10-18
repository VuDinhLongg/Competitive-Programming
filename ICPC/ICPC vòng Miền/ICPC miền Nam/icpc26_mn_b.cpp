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

int n, m, p, q1, q2, f[202][202][202], x[202][202][202], y[202][202][202], z[202][202][202];
int o1, o2, o3, o4, o5, o6, s, a, b, c;

void update(int s[202][202][202], int o){
	s[o1][o2][o3] += o;
	s[o4 + 1][o2][o3] -= o;
	s[o1][o5 + 1][o3] -= o;
	s[o1][o2][o6 + 1] -= o;
	s[o4 + 1][o5 + 1][o3] += o;
	s[o4 + 1][o2][o6 + 1] += o;
	s[o1][o5 + 1][o6 + 1] += o;
	s[o4 + 1][o5 + 1][o6 + 1] -= o;
}

void finish(int s[202][202][202]){
	fo(i, 1, n) fo(j, 1, m) fo(k, 1, p){
		s[i][j][k] += s[i - 1][j][k] + s[i][j - 1][k] + s[i][j][k - 1]
					- s[i - 1][j - 1][k] - s[i - 1][j][k - 1] - s[i][j - 1][k - 1]
					+ s[i - 1][j - 1][k - 1];
	}
}

void solve(){
	cin >> n >> m >> p >> q1 >> q2;
	while(q1--){
		cin >> o1 >> o2 >> o3 >> o4 >> o5 >> o6 >> s >> a >> b >> c;
		update(f, s - o1 * a - o2 * b - o3 * c);
		update(x, a);
		update(y, b);
		update(z, c);
	}
	finish(f);
	finish(x);
	finish(y);
	finish(z);
	while(q2--){
		cin >> o1 >> o2 >> o3;
		cout << f[o1][o2][o3] + x[o1][o2][o3] * o1 + y[o1][o2][o3] * o2 + z[o1][o2][o3] * o3, el;
	}
}

signed main(){
	ios::sync_with_stdio(0); cin.tie(0);
	
	int o = 1; ///cin >> o;
	while(o --> 0) solve();
}
