#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define endl "\n"
#define n 6
#define prll_val 30000000
using namespace std;

struct node
{
    ll value=-1;
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<ll> arr(n);
    for (ll i=0;i<=n-1;i++)
    {
        cin >> arr[i];
    }

    map<ll,node> cache;
    for (ll i=0;i<=n-2;i++)
    {
        cache[arr[i]].value=i;
    }

    for (ll count=n;count<=prll_val-1;count++)
    {
        ll last=*prev(arr.end());
        if (cache[last].value==-1)
        {
            arr.push_back(0);
        }
        else
        {
            ll q=arr.size()-1-cache[last].value;
            arr.push_back(q);
        }

        cache[last].value=arr.size()-2;
    }

    cout << *prev(arr.end()) << endl;
    return 0;
}