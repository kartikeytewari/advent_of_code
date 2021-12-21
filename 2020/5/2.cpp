#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define endl "\n"
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<int> seat;
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
        seat.push_back(local);
    }

    int ans=0;
    sort(seat.begin(), seat.end());
    for (int i=1;i<=1022;i++)
    {
        bool alpha=binary_search(seat.begin(), seat.end(), i);
        bool prev=binary_search(seat.begin(), seat.end(), i-1);
        bool post=binary_search(seat.begin(), seat.end(), i+1);

        if ((!alpha)&&(prev&&post))
        {
            ans=i;
            break;
        }
    }
    cout << ans << endl;

    return 0;
}