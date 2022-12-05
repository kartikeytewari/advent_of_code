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
        map<char,int> index;
        for (int j=0;j<=(int)password[i].length()-1;j++)
        {
            index[password[i][j]]++;
        }

        if ((index[val[0]]>=lower_limit)&&(index[val[0]]<=upper_limit))
        {
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}