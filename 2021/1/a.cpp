#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i=0;i<=n-1;i++)
    {
        cin >> arr[i];
    }

    int count=0;
    for (int i=1;i<=n-1;i++)
    {
        if (arr[i]>arr[i-1])
        {
            count++;
        }
    }
    cout << count << endl;

    return 0;
}