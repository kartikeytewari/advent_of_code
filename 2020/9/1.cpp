#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define endl "\n"
#define n 1000
#define preamble_length 25
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

    for (int i=preamble_length;i<=n-1;i++)
    {
        vector<int> temp;
        for (int j=i-preamble_length;j<=i-1;j++)
        {
            temp.push_back(arr[j]);
        }

        bool flag=false;
        for (int j=0;j<=preamble_length-2;j++)
        {
            for (int k=j+1;k<=preamble_length-1;k++)
            {
                int val=temp[j]+temp[k];
                if (val==arr[i])
                {
                    flag=true;
                }
            }
        }

        if (!flag)
        {
            cout << arr[i] << endl;
            break;
        }
    }

    return 0;
}