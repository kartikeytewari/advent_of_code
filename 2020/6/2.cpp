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
    int counter[26]={};
    int ans=0;
    int grp_mem=0;
    for (int j=0;j<=line_length-1;j++)
    {
        getline(cin, s);
        if (s.length()==0)
        {
            for (int i=0;i<=25;i++)
            {
                if (counter[i]==grp_mem)
                {
                    ans++;
                }
            }
            
            grp_mem=0;
            for (int i=0;i<=25;i++)
            {
                counter[i]=0;
            }
        }
        else
        {
            grp_mem++;
            for (auto it=s.begin();it!=s.end();it++)
            {
                counter[int(*it)-int('a')]++;
            }
        }
    }

    cout << ans << endl;
    return 0;
}