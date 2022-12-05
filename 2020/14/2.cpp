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

    string mask="";
    map<ll,ll> buffer;
    for (ll line_id=0;line_id<=n-1;line_id++)
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

            bitset<36> k=mem_pos;
            vector<ll> float_pos;
            for (ll i=0;i<=35;i++)
            {
                if (mask[35-i]=='1')
                {
                    k[i]=1;
                }
                else if (mask[35-i]=='X')
                {
                    float_pos.push_back(i);
                }
            }

            ll len=float_pos.size();
            for (ll i=0;i<=pow(2,len)-1;i++)
            {
                bitset<36> toggle_val=i;
                for (ll j=0;j<=len-1;j++)
                {
                    // pos of bit float_pos[j]
                    // val of bit toggle_val[j]

                    k[float_pos[j]]=toggle_val[j];
                }
                ll discrete_mem_val=k.to_ulong();
                buffer[discrete_mem_val]=mem_val;
            }
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