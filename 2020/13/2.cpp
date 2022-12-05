#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define endl "\n"
using namespace std;

ll inv(ll a, ll m) 
{ 
    ll m0 = m, t, q; 
    ll x0 = 0, x1 = 1; 
  
    if (m == 1) 
       return 0; 
       
    while (a > 1) 
    {
        q = a / m;
        t = m;
        m = a % m, a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t; 
    } 
  
    if (x1 < 0) 
       x1 += m0; 
 
    return x1; 
} 

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n=86;
    vector<pair<ll,ll>> arr;
    for (ll i=0;i<=n-1;i++)
    {
        string s;
        cin >> s;
        if (s!="x")
        {
            arr.push_back(make_pair(stoi(s),stoi(s)-i));
        }
    }

    ll all_product=1;
    for (auto it=arr.begin();it!=arr.end();it++)
    {
        all_product*=it->first;
    }

    ll x=0;
    for (auto it=arr.begin();it!=arr.end();it++)
    {
        x+=(it->second)*(all_product/it->first)*inv((all_product/it->first), it->first);
    }

    cout << x%all_product << endl;

    return 0;
}