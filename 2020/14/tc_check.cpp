#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define endl "\n"
#define n 536
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int ans=INT_MIN;
    for (int i=0;i<=n-1;i++)
    {
        string s;
        getline(cin,s);

        int count=0;
        for (auto it=s.begin();it!=s.end();it++)
        {
            if (*it=='X')
            {
                count++;
            }
        }
        ans=max(ans, count);
    }

    cout << ans << endl;
    return 0;
}