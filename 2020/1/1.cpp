#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define endl "\n"
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    map<int,int> count;
    int ans=0;
    for (int i=0;i<=199;i++)
    {
        int a;
        cin >> a;
        count[a]++;

        if ((a!=1010)&&(count[2020-a]!=0))
        {
            ans=(a*(2020-a));
        }
        else if ((a==1010)&&(count[1010]>=2))
        {
            ans=1010*1010;
        }
    }

    cout << ans << endl;
    return 0;
}