#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int val=0;
    vector<int> arr;
    for (int i=0;i<=n-1;i++)
    {
        string s;
        cin >> s;

        if (s=="new_batch")
        {
            arr.push_back(val);
            val=0;
        }
        else
        {
            val+=stoi(s);
        }
    }
    arr.push_back(val);

    sort(arr.begin(), arr.end());
    cout << *arr.rbegin() << endl;
    return 0;
}