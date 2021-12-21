#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<string> arr(n);
    for (int i=0;i<=n-1;i++)
    {
        cin >> arr[i];
    }

    int k=arr[0].size();
    int gamma=0;
    int epsilon=0;
    for (int j=0;j<=k-1;j++)
    {
        int count=0;
        for (int i=0;i<=n-1;i++)
        {
            if (arr[i][j]=='0')
            {
                count++;
            }
        }

        gamma*=2;
        epsilon*=2;
        if (count>n-count)
        {
            epsilon+=1;
        }
        else
        {
            gamma+=1;
        }
    }

    cout << gamma*epsilon << endl;
    return 0;
}