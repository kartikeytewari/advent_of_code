#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define endl "\n"
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int arr[200];
    for (int i=0;i<=199;i++)
    {
        cin >> arr[i];
    }

    int ans=0;
    for (int i=0;i<=197;i++)
    {
        for (int j=0;j<=198;j++)
        {
            for (int k=0;k<=199;k++)
            {
                if (arr[i]+arr[j]+arr[k]==2020)
                {
                    ans=arr[i]*arr[j]*arr[k];
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}