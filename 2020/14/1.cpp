#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define endl "\n"
#define n 536
using namespace std;

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);

    string mask="";
    map<ll,ll> buffer;
    for (ll i=0;i<=n-1;i++)
    {
        string s;
        getline(cin,s);

        string temp=s.substr(0,3);
        if (temp=="mas")
        {
            // this is a mask
            mask=s.substr(7,36);
        }
        else
        {
            // this is a mem allocation
            auto first_pos=s.find("[");
            auto second_pos=s.find("]");
            ll mem_pos=stoi(s.substr(first_pos+1, second_pos-first_pos-1));
            ll mem_val=stoi(s.substr(second_pos+4, s.length()-second_pos-4));

            bitset<32> k=mem_val;
            for (ll j=0;j<=35;j++)
            {
                if (mask[35-j]=='1')
                {
                    k[j]=1;
                }
                else if (mask[35-j]=='0')
                {
                    k[j]=0;
                }
            }

            buffer[mem_pos]=k.to_ulong();
        }
    }

    ll ans=0;
    for (auto it=buffer.begin();it!=buffer.end();it++)
    {
        ans+=it->second;
    }
    cout << ans << endl;

    return 0;
}