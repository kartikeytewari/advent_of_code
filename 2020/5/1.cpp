#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define endl "\n"
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int ans=0;
    for (int j=0;j<=858;j++)
    {
        string s;
        cin >> s;
        bitset<7> row;
        for (int i=0;i<=6;i++)
        {
            if (s[i]=='F')
            {
                row[6-i]=0;
            }
            else
            {
                row[6-i]=1;
            }
        }

        bitset<3> column;
        for (int i=7;i<=9;i++)
        {
            if (s[i]=='R')
            {
                column[9-i]=1;
            }
            else
            {
                column[9-i]=0;
            }
        }

        int row_val=(int)row.to_ulong();
        int col_val=(int)column.to_ulong();
        int local=(row_val*8)+col_val;
        ans=max(ans, local);
    }
    cout << ans << endl;

    return 0;
}