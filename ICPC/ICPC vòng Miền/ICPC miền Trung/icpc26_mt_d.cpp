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
#define mxn 10007

int a1, a2, a3, a4, k, cnt[300];
int p[mxn], dp[mxn];
vector<int> v;

int calc(int n){
	for(int &i : v) dp[i] = 0;
	for(int &i : v){
		for(int cur = i; cur <= n; cur *= i){
			dp[i] += n / cur;
		}
		for(char c : {'L', 'R', 'U', 'D'}){
			for(int cur = i; cur <= cnt[c]; cur *= i){
				dp[i] -= cnt[c] / cur;
			}
		}
	}
	int res = 1;
	for(int &i : v) fo(j, 1, dp[i]){
		res *= i;
		if(res > 1e9) return res;
	}
	return res;
}

void solve(){
	fo(i, 2, 1e4) p[i] = i;
	fo(i, 2, 1e2) if(p[i] == i){
		for(int j=i*i; j<=1e4; j+=i){
			if(p[j] == j) p[j] = i;
		}
	}
	fo(i, 2, 1e4) if(i == p[i]) v.pub(i);
	while(cin >> a1 >> a2 >> a3 >> a4 >> k){
		cnt['L'] = a1;
		cnt['R'] = a2;
		cnt['U'] = a3;
		cnt['D'] = a4;
		int n = a1 + a2 + a3 + a4, nn = n;
		if(calc(n) < k){
			cout << "-1", el;
			continue;
		}
		string s = "";
		fo(i, 1, nn){
			char o = '?';
			int sum = 0;
			for(char c : {'L', 'R', 'U', 'D'}) if(cnt[c]){
				--cnt[c]; --n;
				int tmp = calc(n);
				++cnt[c]; ++n;
				o = c;
				if(sum + tmp >= k){
					k -= sum;
					break;
				}else sum += tmp;
			}
			s.pub(o);
			--cnt[o]; --n;
		}
		cout << s, el;
	}
}

signed main(){
	ios::sync_with_stdio(0); cin.tie(0);
	
	int o = 1; ///cin >> o;
	while(o --> 0) solve();
}
