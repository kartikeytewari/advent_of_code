#include <bits/stdc++.h>
using namespace std;

vector<vector<long long>> dp(301, vector<long long> (257, -1ll));

long long calc (long long a, long long k)
{
    if (k<=0)
    {
        return 1;
    }
    else if (dp[a][k]==-1)
    {
        if (a!=0)
        {
            long long val=calc(0,k-a);
            dp[a][k]=val;
        }
        else
        {
            long long val=calc(6,k-1)+calc(8,k-1);
            dp[a][k]=val;
        }
    }

    return dp[a][k];
}

int main()
{
    long long n,k;
    cin >> n >> k;
    
    long long count=0;
    for (long long i=0;i<=n-1;i++)
    {
        long long a;
        cin >> a;
        cout << "a= " << a << endl;
        long long val=calc(a, k);
        count+=val;
        cout << "val= " << val << endl;
    }

    cout << count << endl;
    return 0;
}