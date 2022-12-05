#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define endl "\n"
#define n 323
#define m 31
using namespace std;
char arr[n][m];

ll get_ans (ll alpha, ll beta)
{
    ll x=0;
    ll y=0;
    ll ans=0;
    while (x<=n-1)
    {
        if (arr[x][y]=='#')
        {
            ans++;
        }
        y=(y+beta)%m;
        x=x+alpha;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    for (ll i=0;i<=n-1;i++)
    {
        for (ll j=0;j<=m-1;j++)
        {
            cin >> arr[i][j];
        }
    }

    ll ans=get_ans(1,1)*get_ans(1,3)*get_ans(1,5)*get_ans(1,7)*get_ans(2,1);
    cout << ans << endl;

    return 0;
}
