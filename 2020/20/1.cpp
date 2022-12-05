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
vector<vector<ll>> border;

vector<ll> get_border(tile temp)
{
    bitset<10> a,b,c,d,e,f,g,h;
    for (ll i=0;i<=9;i++)
    {
        a[i]=temp.val[0][9-i];
        b[i]=temp.val[9][9-i];
        c[i]=temp.val[9-i][0];
        d[i]=temp.val[9-i][9];
    }
    for (int i=0;i<=9;i++)
    {
        e[i]=a[9-i];
        f[i]=b[9-i];
        g[i]=c[9-i];
        h[i]=d[9-i];
    }

    vector<ll> buffer;
    buffer.push_back(a.to_ulong());
    buffer.push_back(b.to_ulong());
    buffer.push_back(c.to_ulong());
    buffer.push_back(d.to_ulong());
    buffer.push_back(e.to_ulong());
    buffer.push_back(f.to_ulong());
    buffer.push_back(g.to_ulong());
    buffer.push_back(h.to_ulong());
    return buffer;
}

bool get_count (vector<ll> first, vector<ll> second)
{
    sort(first.begin(),first.end());
    for (auto it=second.begin();it!=second.end();it++)
    {
        if (binary_search(first.begin(),first.end(),*it))
        {
            return true;
        }
    }

    return false;
}

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
        border.push_back(get_border(temp));
    }

    ll ans=1;
    for (auto it=arr.begin();it!=arr.end();it++)
    {
        tile present=*it;
        ll degree=-1;
        vector<ll> first=get_border(present);
        for (auto it2=border.begin();it2!=border.end();it2++)
        {
            vector<ll> second=*it2;
            vector<ll> temp;

            if (get_count(first,second))
            {
                degree++;
            }
        }
        
        if (degree==2)
        {
            ans*=present.id;
        }
    }
    cout << ans << endl;

    return 0;
}