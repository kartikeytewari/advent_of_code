#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define endl "\n"
#define line_length 2063
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s;
    bitset<26> counter=0;
    int ans=0;
    for (int j=0;j<=line_length-1;j++)
    {
        getline(cin, s);
        if (s.length()==0)
        {
            for (int i=0;i<=25;i++)
            {
                if (counter[i]==1)
                {
                    ans++;
                }
            }
            counter=0;
        }
        else
        {
            for (auto it=s.begin();it!=s.end();it++)
            {
                counter[int(*it)-int('a')]=1;
            }
        }
    }

    cout << ans << endl;
    return 0;
}