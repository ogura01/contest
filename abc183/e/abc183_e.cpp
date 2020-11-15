#include <bits/stdc++.h>
using namespace std;

#define REP(i,p,n) for(ll i=p;i<ll(n);++i)
#define rep(i,n) REP(i,0,n)

using ll = long long int;
using pll = pair<ll, ll>;

const ll MOD = 1000000007;

const ll MAXN = 2001;
ll dp[MAXN][MAXN];
ll dx[MAXN][MAXN];
ll dy[MAXN][MAXN];
ll dz[MAXN][MAXN];

int main()
{
    ll H, W;
    cin >> H >> W;

    vector<string> S(H);
    for (auto& s : S) { cin >> s; }

    dp[0][0] = 1;

    rep (y, H)
    rep (x, W)
    {
#if 0
        // ---------------------------------------------------------------------
        // 配る
        // ---------------------------------------------------------------------
        if (x < W - 1 && S[y][x + 1] != '#')
        {
            dx[y][x + 1] = (dp[y][x] + dx[y][x]) % MOD;
            dp[y][x + 1] = (dp[y][x + 1] + dx[y][x + 1]) % MOD;
        }

        if (y < H - 1 && S[y + 1][x] != '#')
        {
            dy[y + 1][x] = (dp[y][x] + dy[y][x]) % MOD;
            dp[y + 1][x] = (dp[y + 1][x] + dy[y + 1][x]) % MOD;
        }

        if (x < W - 1 && y < H - 1 && S[y + 1][x + 1] != '#')
        {
            dz[y + 1][x + 1] = (dp[y][x] + dz[y][x]) % MOD;
            dp[y + 1][x + 1] = (dp[y + 1][x + 1] + dz[y + 1][x + 1]) % MOD;
        }
#else
        // ---------------------------------------------------------------------
        // 貰う
        // ---------------------------------------------------------------------
        if (S[y][x] == '#') { continue; }

        if (x >= 1) { dx[y][x] = (dp[y][x - 1] + dx[y][x - 1]) % MOD; }
        if (y >= 1) { dy[y][x] = (dp[y - 1][x] + dy[y - 1][x]) % MOD; }
        if (x >= 1 && y >= 1) { dz[y][x] = (dp[y - 1][x - 1] + dz[y - 1][x - 1]) % MOD; }

        dp[y][x] += (dx[y][x] + dy[y][x] + dz[y][x]) % MOD;
#endif
    }

    const auto ans = dp[H - 1][W - 1] % MOD;
    cout << ans << endl;

    return 0;
}