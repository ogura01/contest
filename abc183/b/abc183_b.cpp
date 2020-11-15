#include <bits/stdc++.h>
using namespace std;

#define REP(i,p,n) for(ll i=p;i<ll(n);++i)
#define rep(i,n) REP(i,0,n)

using ll = long long int;
using pll = pair<ll, ll>;

int main()
{
    double x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    const auto ans = x1 + ((x2 - x1) * y1) / (y1 + y2);

    printf("%.10f\n", ans);
    return 0;
}