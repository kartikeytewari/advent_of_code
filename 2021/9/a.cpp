#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<vector<int>> arr(n);
    for (int i=0;i<=n-1;i++)
    {
        string s;
        cin >> s;
        for (int j=0;j<=(int)s.length()-1;j++)
        {
            arr[i].push_back(int(s[j])-int('0'));
        }
    }

    int m=arr[0].size();
    int ans=0;
    for (int i=0;i<=n-1;i++)
    {
        for (int j=0;j<=m-1;j++)
        {
            int val=INT_MAX;
            if (i-1>=0)
            {
                val=min(val, arr[i-1][j]);
            }
            if (i+1<=n-1)
            {
                val=min(val, arr[i+1][j]);
            }
            if (j-1>=0)
            {
                val=min(val, arr[i][j-1]);
            }
            if (j+1<=m-1)
            {
                val=min(val, arr[i][j+1]);
            }

            if (val>arr[i][j])
            {
                ans+=arr[i][j]+1;
            }
        }
    }

    cout << ans << endl;
    return 0;
}
