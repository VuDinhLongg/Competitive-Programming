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
#define mxn 500'007

int n, dp[mxn], last[mxn];
string s;

vector<int> kmp(string s){
    vector<int> f(n + 5, 0);
    for(int i = 2, j = 0; i <= n; ++i){
        while(j and s[i] != s[j + 1]) j = f[j];
        if(s[i] == s[j + 1]) f[i] = ++j;
    }
    return f;
}

void solve(){
    cin >> s;
    n = len(s);
    s = " " + s;
    vector<int> f = kmp(s);
    //fo(i, 1, n) cout << s[i] << ' ' << f[i], el;
    fo(i, 1, n){
        dp[i] = i;
        if(f[i] and last[dp[f[i]]] >= i - f[i]){
            dp[i] = dp[f[i]];
        }
        last[dp[i]] = i;
    }
    cout << dp[n];
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    if(fopen("olp.inp", "r")){
        freopen("olp.inp", "r", stdin);
        freopen("olp.out", "w", stdout);
    }
    
    int o = 1; ///cin >> o;
    while(o --> 0) solve();
}