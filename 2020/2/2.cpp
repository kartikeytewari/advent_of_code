#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define endl "\n"
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string range[1000];
    string counter[1000];
    string password[1000];

    int ans=0;
    for (int i=0;i<=999;i++)
    {
        cin >> range[i] >> counter[i] >> password[i];

        int lower_limit=stoi(range[i].substr(0,range[i].find('-')));
        int upper_limit=stoi(range[i].substr(range[i].find('-')+1, (int)range[i].length()-1));
        
        string val=counter[i].substr(0,1);

        int count=0;
        if (password[i][lower_limit-1]==val[0])
        {
            count++;
        }
        if (password[i][upper_limit-1]==val[0])
        {
            count++;
        }

        if (count==1)
        {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}