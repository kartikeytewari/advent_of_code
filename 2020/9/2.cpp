#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define endl "\n"
#define n 1000
#define preamble_length 25
#define wrong_number 258585477
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int arr[n];
    for (int i=0;i<=n-1;i++)
    {
        cin >> arr[i];
    }

    for (int i=0;i<=n-2;i++)
    {
        int local=arr[i];
        for (int j=i+1;j<=n-1;j++)
        {
            local+=arr[j];
            if (local==wrong_number)
            {
                int min_val=INT_MAX;
                int max_val=INT_MIN;

                for (int k=i;k<=j;k++)
                {
                    min_val=min(min_val, arr[k]);
                    max_val=max(max_val, arr[k]);
                }

                cout << min_val+max_val << endl;
                return 0;
            }
        }
    }

    return 0;
}