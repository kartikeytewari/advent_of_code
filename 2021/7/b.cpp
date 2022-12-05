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

    long long ans=LLONG_MAX;
    for (long long val=arr[0];val<=arr[n-1];val++)
    {
        long long ans_val=0;
        for (long long i=0;i<=n-1;i++)
        {
            long long diff=abs(arr[i]-val);
            long long local=(diff*(diff+1))/2;
            ans_val+=local;
        }
        ans=min(ans, ans_val);
    }

    cout << ans << endl;
}
