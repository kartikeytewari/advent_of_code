#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define endl "\n"
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll arr[22][22][13]={};

    for (ll i=7;i<=14;i++)
    {
        string s;
        cin >> s;
        for (ll j=7;j<=14;j++)
        {
            // k=6
            if (s[j-7]=='.')
            {
                arr[i][j][6]=0;
            }
            else
            {
                arr[i][j][6]=1;
            }
        }
    }

    for (ll cycle=0;cycle<=5;cycle++)
    {
        ll temp[22][22][13]={};
        for (ll i=0;i<=21;i++)
        {
            for (ll j=0;j<=21;j++)
            {
                for (ll k=0;k<=12;k++)
                {

                    ll neighbour=0;
                    for (ll dx=-1;dx<=1;dx++)
                    {
                        for (ll dy=-1;dy<=1;dy++)
                        {
                            for (ll dz=-1;dz<=1;dz++)
                            {
                                if ((i+dx>=0)&&(i+dx<=19))
                                {
                                    if ((j+dy>=0)&&(j+dy<=19))
                                    {
                                        if ((k+dz>=0)&&(k+dz<=12))
                                        {
                                            neighbour+=arr[i+dx][j+dy][k+dz];
                                        }
                                    }
                                }
                            }
                        }
                    }
                    if (arr[i][j][k]==1)
                    {
                        neighbour--;
                    }

                    if (arr[i][j][k]==1)
                    {
                        if ((neighbour==2)||(neighbour==3))
                        {
                            temp[i][j][k]=1;
                        }
                        else
                        {
                            temp[i][j][k]=0;
                        }
                    }
                    else
                    {
                        if (neighbour==3)
                        {
                            temp[i][j][k]=1;
                        }
                        else
                        {
                            temp[i][j][k]=0;
                        }
                    }

                }
            }
        }

        for (ll i=0;i<=21;i++)
        {
            for (ll j=0;j<21;j++)
            {
                for (ll k=0;k<=12;k++)
                {
                    arr[i][j][k]=temp[i][j][k];
                }
            }
        }
    }

    ll ans=0;
    for (ll i=0;i<=21;i++)
    {
        for (ll j=0;j<=21;j++)
        {
            for (ll k=0;k<=12;k++)
            {
                ans+=arr[i][j][k];
            }
        }
    }
    cout << ans << endl;

    return 0;
}
