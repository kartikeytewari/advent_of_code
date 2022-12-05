#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<pair<pair<int,int>, pair<int,int>>> arr(n);
    
    int x_max=0;
    int y_max=0;
    for (int i=0;i<=n-1;i++)
    {
        pair<int,int> a;
        pair<int,int> b;
        cin >> a.first >> a.second;
        cin >> b.first >> b.second;

        arr[i]={min(a,b), max(a,b)};
        x_max=max(x_max, arr[i].first.first);
        x_max=max(x_max, arr[i].second.first);
        y_max=max(y_max, arr[i].first.second);
        y_max=max(y_max, arr[i].second.second);
    }

    vector<vector<int>> board(x_max+1, vector<int> (y_max+1, 0));
    for (int i=0;i<=n-1;i++)
    {
        if (arr[i].first.first == arr[i].second.first)
        {
            int alpha=min(arr[i].first.second, arr[i].second.second);
            int beta=max(arr[i].first.second, arr[i].second.second);
            for (int j=alpha;j<=beta;j++)
            {
                board[arr[i].first.first][j]+=1;
            }
        }

        else if (arr[i].first.second == arr[i].second.second)
        {
            int alpha=min(arr[i].first.first, arr[i].second.first);
            int beta=max(arr[i].first.first, arr[i].second.first);
            for (int j=alpha;j<=beta;j++)
            {
                board[j][arr[i].first.second]+=1;
            }
        }

        else
        {
            int a=arr[i].first.first-arr[i].second.first;
            int b=arr[i].first.second-arr[i].second.second;
            int c=a*b;
            int flag=-1;
            if (c>=0)
            {
                flag=1;
            }
            // flag=-1 different direction
            // flag=1 same direction
            int old=arr[i].first.second;
            for (int j=arr[i].first.first;j<=arr[i].second.first;j++)
            {
                board[j][old]+=1;
                old+=flag;
            }
        }
    }

    int count=0;
    for (int i=0;i<=x_max;i++)
    {
        for (int j=0;j<=y_max;j++)
        {
            if (board[i][j]>=2)
            {
                count++;
            }
        }
    }

    cout << count << endl;
    return 0;
}