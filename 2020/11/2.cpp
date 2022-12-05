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
    for (int i=a-1;i>=0;i--)
    {
        if ((arr[i][b]=='L')||(arr[i][b]=='#'))
        {
            if (arr[i][b]=='#')
            {
                count++;
            }
            break;
        }
    }

    for (int i=a+1;i<=n-1;i++)
    {
        if ((arr[i][b]=='L')||(arr[i][b]=='#'))
        {
            if (arr[i][b]=='#')
            {
                count++;
            }
            break;
        }
    }

    for (int i=b-1;i>=0;i--)
    {
        if ((arr[a][i]=='L')||(arr[a][i]=='#'))
        {
            if (arr[a][i]=='#')
            {
                count++;
            }
            break;
        }
    }

    for (int i=b+1;i<=m-1;i++)
    {
        if ((arr[a][i]=='L')||(arr[a][i]=='#'))
        {
            if (arr[a][i]=='#')
            {
                count++;
            }
            break;
        }
    }

    int alpha=a-1;
    int beta=b-1;
    while ((alpha>=0)&&(beta>=0))
    {
        if ((arr[alpha][beta]=='L')||(arr[alpha][beta]=='#'))
        {
            if (arr[alpha][beta]=='#')
            {
                count++;
            }
            break;
        }
        alpha--;
        beta--;
    }

    alpha=a+1;
    beta=b-1;
    while ((alpha<=n-1)&&(beta>=0))
    {
        if ((arr[alpha][beta]=='L')||(arr[alpha][beta]=='#'))
        {
            if (arr[alpha][beta]=='#')
            {
                count++;
            }
            break;
        }
        alpha++;
        beta--;
    }

    alpha=a-1;
    beta=b+1;
    while ((alpha>=0)&&(beta<=m-1))
    {
        if ((arr[alpha][beta]=='L')||(arr[alpha][beta]=='#'))
        {
            if (arr[alpha][beta]=='#')
            {
                count++;
            }
            break;
        }
        alpha--;
        beta++;
    }

    alpha=a+1;
    beta=b+1;
    while ((alpha<=n-1)&&(beta<=m-1))
    {
        if ((arr[alpha][beta]=='L')||(arr[alpha][beta]=='#'))
        {
            if (arr[alpha][beta]=='#')
            {
                count++;
            }
            break;
        }
        alpha++;
        beta++;
    }

    return count;
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
            if ((q>=5)&&(temp[i][j]=='#'))
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