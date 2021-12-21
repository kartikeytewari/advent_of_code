#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define endl "\n"
#define n 90
#define m 91
using namespace std;

int check_neighbours (int a, int b, char arr[n][m])
{
    int count=0;
    if ((((a-1)>=0)&&((b-1)>=0))&&(arr[a-1][b-1]=='#'))
    {
        count++;
    }
    if ((((a-1)>=0)&&(b>=0))&&(arr[a-1][b]=='#'))
    {
        count++;
    }
    if ((((a-1)>=0)&&((b+1)<=m-1))&&(arr[a-1][b+1]=='#'))
    {
        count++;
    }
    if ((((a)>=0)&&((b-1)>=0))&&(arr[a][b-1]=='#'))
    {
        count++;
    }
    if ((((a)>=0)&&((b+1)<=m-1))&&(arr[a][b+1]=='#'))
    {
        count++;
    }
    if ((((a+1)<=n-1)&&((b-1)>=0))&&(arr[a+1][b-1]=='#'))
    {
        count++;
    }
    if ((((a+1)<=n-1)&&((b)>=0))&&(arr[a+1][b]=='#'))
    {
        count++;
    }
    if ((((a+1)<=n-1)&&((b+1)<=m-1))&&(arr[a+1][b+1]=='#'))
    {
        count++;
    }
    return count++;
}

int func (char arr[n][m])
{
    cout << "hello" << endl;
    // calculate the next layer
    char temp[n][m]={};
    for (int i=0;i<=n-1;i++)
    {
        for (int j=0;j<=m-1;j++)
        {
            int q=check_neighbours(i,j,arr);
            if ((q==0)&&(arr[i][j]=='L'))
            {
                temp[i][j]='#';
            }
            else
            {
                temp[i][j]=arr[i][j];
            }
        }
    }

    char next[n][m]={};
    for (int i=0;i<=n-1;i++)
    {
        for (int j=0;j<=m-1;j++)
        {
            int q=check_neighbours(i,j,temp);
            if ((q>=4)&&(temp[i][j]=='#'))
            {
                next[i][j]='L';
            }
            else
            {
                next[i][j]=temp[i][j];
            }
        }
    }
    
    // check is next is same as arr
    bool flag=true;
    for (int i=0;i<=n-1;i++)
    {
        for (int j=0;j<=m-1;j++)
        {
            if (arr[i][j]!=next[i][j])
            {
                flag=false;
            }
        }
    }

    // cout << "--------" << endl;
    // for (int i=0;i<=n-1;i++)
    // {
    //     for (int j=0;j<=m-1;j++)
    //     {
    //         cout << next[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << "--------" << endl;

    if (flag)
    {
        int ans=0;
        for (int i=0;i<=n-1;i++)
        {
            for (int j=0;j<=m-1;j++)
            {
                if (arr[i][j]=='#')
                {
                    ans++;
                }
            }
        }
        return ans;
    }
    else
    {
        return func(next);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    char arr[n][m];
    for (int i=0;i<=n-1;i++)
    {
        for (int j=0;j<=m-1;j++)
        {
            cin >> arr[i][j];
        }
    }

    cout << func(arr) << endl;
    return 0;
}