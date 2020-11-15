#include <bits/stdc++.h>
using namespace std;

#define REP(i,p,n) for(ll i=p;i<ll(n);++i)
#define rep(i,n) REP(i,0,n)

using ll = long long int;
using pll = pair<ll, ll>;

const ll MAXN = 8;
ll T[MAXN][MAXN];

int main()
{
    ll N, K;
    cin >> N >> K;
    rep (i, N) rep (j, N) cin >> T[i][j];

    vector<ll> P(N);
    rep (i, N) { P[i] = i; }

    ll ans = 0;
    do
    {
        ll sum = 0;
        rep (i, N) { sum += T[P[i]][P[(i + 1) % N]]; }

        if (sum == K) { ++ans; }
    }
    while (next_permutation(P.begin() + 1, P.end()));

    cout << ans << endl;

    return 0;
}