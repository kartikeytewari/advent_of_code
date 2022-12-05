#include <bits/stdc++.h>
using namespace std;

int main()
{
    int type, val;
    cin >> type >> val;

    int n;
    cin >> n;
    vector<pair<int,int>> arr(n);
    for (int i=0;i<=n-1;i++)
    {
        cin >> arr[i].first >> arr[i].second;
    }

    if (type==1)
    {
        // fold along x-axis
        for (int i=0;i<=n-1;i++)
        {
            arr[i].first=min(arr[i].first, (2*val)-arr[i].first);
        }
    }
    else
    {
        // fold along y-axis
        for (int i=0;i<=n-1;i++)
        {
            arr[i].second=min(arr[i].second, (2*val)-arr[i].second);
        }
    }

    set<pair<int,int>> buffer;
    for (int i=0;i<=n-1;i++)
    {
        buffer.insert({arr[i].first, arr[i].second});
    }

    cout << buffer.size() << endl;
    return 0;
}