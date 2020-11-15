#include <bits/stdc++.h>
using namespace std;

#define REP(i,p,n) for(ll i=p;i<ll(n);++i)
#define rep(i,n) REP(i,0,n)

using ll = long long int;
using pll = pair<ll, ll>;

struct UnionFind
{
    vector<ll> data;
    vector< map<ll, ll> > klass;

    void init(ll n)
    {
        data.assign(n, -1);
        klass.assign(n, map<ll, ll>());
    }

    ll find(ll x)
    {
        return data[x] == -1 ? x : data[x] = find(data[x]);
    }

    bool connect(ll x, ll y)
    {
        auto a = find(x);
        auto b = find(y);
        if (a == b) { return false; }

        if (klass[a].size() < klass[b].size()) { swap(a, b); }

        data[b] = a;

        auto& src = klass[b];
        auto& dst = klass[a];
        for (const auto& kv : src) { dst[kv.first] += kv.second; }

        return true;
    }
};

int main()
{
    ll N, Q;
    cin >> N >> Q;

    UnionFind uf;
    uf.init(N);

    rep (i, N)
    {
        ll c;
        cin >> c;
        --c;

        uf.klass[i][c] = 1;
    }

    rep (i, Q)
    {
        ll q, a, b;
        cin >> q >> a >> b;
        --a;
        --b;

        if (q == 1)
        {
            uf.connect(a, b);
        }
        else
        {
            const auto r = uf.find(a);
            cout << uf.klass[r][b] << endl;
        }
    }

    return 0;
}