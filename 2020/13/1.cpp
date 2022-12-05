#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define endl "\n"
#define n 86
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    vector<int> bus;
    for (int i=0;i<=n-1;i++)
    {
        string s;
        cin >> s;
        if (s!="x")
        {
            bus.push_back(stoi(s));
        }
    }

    sort(bus.begin(),bus.end());
    int min_val=INT_MAX;
    int ans_bus=0;
    for (auto it=bus.begin();it!=bus.end();it++)
    {
        cout << "id= " << *it << endl;
        int id=*it;
        int a=id-(t%id);
        if (a==id)
        {
            a=0;
        }

        if (min_val>=a)
        {
            min_val=a;
            ans_bus=*it;
        }
    }

    cout << min_val*ans_bus << endl;
    return 0;
}