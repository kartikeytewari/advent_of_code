#include <bits/stdc++.h>
using namespace std;

void display (int step, int local, vector<vector<int>> arr)
{
    cerr << "------------------" << endl;
    cerr << "step= " << step << endl;
    cerr << "local= " << local << endl;
    
    int n=arr.size();
    int m=arr[0].size();
    for (int i=0;i<=n-1;i++)
    {
        for (int j=0;j<=m-1;j++)
        {
            cerr << arr[i][j] << " ";
        }
        cerr << endl;
    }
    cerr << "------------------" << endl;

    return;
}

void inc_neighbour (vector<vector<int>> &arr, vector<vector<bool>> &flash, stack<pair<int,int>> &high, int x, int y)
{
    int n=arr.size();
    int m=arr[0].size();
    if (((x>=0) && (x<=n-1)) && ((y>=0) && (y<=m-1)))
    {
        if (!flash[x][y])
        {
            arr[x][y]++;
            if ((arr[x][y]>=10) && (!flash[x][y]))
            {
                flash[x][y]=true;
                high.push({x, y});
            }
        }
    }

    return;
}

pair<int, vector<vector<int>>> simulate_step (vector<vector<int>> arr)
{
    int local=0;
    int n=arr.size();
    int m=arr[0].size();

    vector<vector<bool>> flash(n, vector<bool> (m, false));
    stack<pair<int,int>> high;
    for (int i=0;i<=n-1;i++)
    {
        for (int j=0;j<=m-1;j++)
        {
            arr[i][j]++;
            if (arr[i][j]>=10)
            {
                flash[i][j]=true;
                high.push({i,j});
            }
        }
    }

    while (!high.empty())
    {
        pair<int,int> val=high.top();
        high.pop();
        local++;

        arr[val.first][val.second]=0;
        inc_neighbour(arr, flash, high, val.first-1, val.second-1);
        inc_neighbour(arr, flash, high, val.first-1, val.second);
        inc_neighbour(arr, flash, high, val.first-1, val.second+1);
        inc_neighbour(arr, flash, high, val.first, val.second-1);
        inc_neighbour(arr, flash, high, val.first, val.second+1);
        inc_neighbour(arr, flash, high, val.first+1, val.second-1);
        inc_neighbour(arr, flash, high, val.first+1, val.second);
        inc_neighbour(arr, flash, high, val.first+1, val.second+1);
    }

    return {local, arr};
}

int main()
{
    int n,m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int> (m));
    for (int i=0;i<=n-1;i++)
    {
        string s;
        cin >> s;
        for (int j=0;j<=m-1;j++)
        {
            arr[i][j]=int(s[j])-int('0');
        }
    }

    int total_flash=0;
    display(0, 0, arr);
    for (int step=1;step<=100;step++)
    {
        pair<int, vector<vector<int>>> next_step=simulate_step(arr);
        int local=next_step.first;
        arr=next_step.second;
        total_flash+=local;
        display(step, local, arr);
    }

    cout << "total_flash= " << total_flash << endl;
    return 0;
}