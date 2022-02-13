#include <bits/stdc++.h>
using namespace std;

int main()
{
    int command_count;
    cin >> command_count;
    vector<pair<char,int>> command(command_count);
    for (int i=0;i<=command_count-1;i++)
    {
        cin >> command[i].first >> command[i].second;
    }

    int n;
    cin >> n;
    vector<pair<int,int>> arr(n);
    for (int i=0;i<=n-1;i++)
    {
        cin >> arr[i].first >> arr[i].second;
    }

    for (int i=0;i<=command_count-1;i++)
    {
        for (int j=0;j<=n-1;j++)
        {
            if (command[i].first=='x')
            {
                // along x-axis
                arr[j].first=min(arr[j].first, (2*command[i].second)-arr[j].first);
            }
            else
            {
                // along y-axis
                arr[j].second=min(arr[j].second, (2*command[i].second)-arr[j].second);
            }
        }
    }

    int x_max=0;
    int y_max=0;
    for (int i=0;i<=n-1;i++)
    {
        x_max=max(x_max, arr[i].first);
        y_max=max(y_max, arr[i].second);
    }

    cout << "x_max= " << x_max << endl;
    cout << "y_max= " << y_max << endl;

    vector<vector<char>> board(x_max+1, vector<char> (y_max+1, '.'));
    for (int i=0;i<=n-1;i++)
    {
        board[arr[i].first][arr[i].second]='#';
    }

    for (int j=0;j<=y_max;j++)
    {
        for (int i=0;i<=x_max;i++)
        {
            cout << board[i][j];
        }
        cout << endl;
    }

    return 0;
}