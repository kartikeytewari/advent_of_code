#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define endl "\n"
using namespace std;

struct tile
{
    ll id;
    bool val[10][10];
};

vector<tile> arr;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll tile_count;
    cin >> tile_count;

    for (ll count=0;count<=tile_count-1;count++)
    {
        tile temp;
        string a,b;
        cin >> a >> b;
        temp.id=stoi(b.substr(0,4));

        for (ll line=0;line<=9;line++)
        {
            string k;
            cin >> k;
            for (ll j=0;j<=9;j++)
            {
                if (k[j]=='.')
                {
                    temp.val[line][j]=0;
                }
                else
                {
                    temp.val[line][j]=1;
                }
            }
        }

        arr.push_back(temp);
    }

    

    return 0;
}