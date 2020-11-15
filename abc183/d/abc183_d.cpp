#include <bits/stdc++.h>
using namespace std;

#define REP(i,p,n) for(ll i=p;i<ll(n);++i)
#define rep(i,n) REP(i,0,n)

using ll = long long int;
using pll = pair<ll, ll>;

#if 1
// -----------------------------------------------------------------------------
// 累積和
// -----------------------------------------------------------------------------
const ll MAXN = 200001;
ll dp[MAXN];

int main()
{
    ll N, W;
    cin >> N >> W;

    rep (i, N)
    {
        ll s, t, p;
        cin >> s >> t >> p;

        dp[s] += p;
        dp[t] -= p;
    }

    ll sum = 0, ans = 0;
    rep (i, MAXN)
    {
        sum += dp[i];
        ans = max(ans, sum);
    }

    cout << (ans <= W ? "Yes" : "No") << endl;

    return 0;
}
#else
// -----------------------------------------------------------------------------
// ソート
// -----------------------------------------------------------------------------
using STP = pair<ll, pll>;

#define SS second.first
#define TT first
#define PP second.second

int main()
{
    ll N, W;
    cin >> N >> W;

    vector<STP> xs(N);
    for (auto& x : xs) { cin >> x.SS >> x.TT >> x.PP; }
    sort(xs.begin(), xs.end());

    ll k = 0, w = 0;
    for (const auto& x1 : xs)
    {
        while (k < N)
        {
            const auto& x2 = xs[k];
            // printf("k=%d, w=%d, x1=(%d, %d, %d), x2=(%d, %d, %d)\n", k, w, x1.SS, x1.TT, x1.PP, x2.SS, x2.TT, x2.PP);
            if (x1.TT <= x2.SS) { break; }

            w += x2.PP;
            ++k;
        }

        // printf("w=%d\n", w);
        if (W < w) { cout << "No" << endl; return 0; }
        w -= x1.PP;
    }

    cout << "Yes" << endl;
    return 0;
}
#endif