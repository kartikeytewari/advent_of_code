#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    long long n;
    cin >> n;
    vector<long long> arr(n);
    for (long long i=0;i<=n-1;i++)
    {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());
    long long avg=arr[(n-1)/2];
    long long ans=0;
    for (long long i=0;i<=n-1;i++)
    {
        long long local=abs(arr[i]-avg);
        ans+=local;
    }

    cout << ans << endl;
    return 0;
}
