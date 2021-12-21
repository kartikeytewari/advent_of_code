#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define endl "\n"
#define n 98
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    pair<bool,ll> dp[1001]={{false,0}};
    ll max_val=LLONG_MIN;
    for (ll i=0;i<=n-1;i++)
    {
        ll a;
        cin >> a;
        max_val=max(max_val, a);
        dp[a].first=true;
    }

    dp[0].first=true;
    dp[0].second=1;
    for (ll i=1;i<=1000;i++)
    {
        if (dp[i].first)
        {
            if ((i-1>=0)&&(dp[i-1].first))
            {
                dp[i].second+=dp[i-1].second;
            }
            if ((i-2>=0)&&(dp[i-2].first))
            {
                dp[i].second+=dp[i-2].second;
            }
            if ((i-3>=0)&&(dp[i-3].first))
            {
                dp[i].second+=dp[i-3].second;
            }
        }
    }
    cout << dp[max_val].second << endl;

    return 0;
}