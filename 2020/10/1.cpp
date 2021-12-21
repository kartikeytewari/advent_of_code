#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define endl "\n"
#define n 98
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

    sort(arr,arr+n);
    int alpha=0; // diff of 1
    int beta=0; // diff of 3
    for (int i=1;i<=n-1;i++)
    {
        if (arr[i]-arr[i-1]==1)
        {
            alpha++;
        }
        else
        {
            beta++;
        }
    }
    if (arr[0]==1)
    {
        alpha++;
    }
    else if (arr[0]==3)
    {
        beta++;
    }
    beta++;

    cout << alpha*beta << endl;

    return 0;
}