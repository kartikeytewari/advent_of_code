#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define endl "\n"
#define n 323
#define m 31
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    char arr[n][m];
    for (int i=0;i<=n-1;i++)
    {
        for (int j=0;j<=m-1;j++)
        {
            cin >> arr[i][j];
        }
    }

    int x=0;
    int y=0;
    int ans=0;
    while (x<=n-1)
    {
        if (arr[x][y]=='#')
        {
            ans++;
        }
        y=(y+3)%m;
        x++;
    }
    cout << ans << endl;

    return 0;
}
