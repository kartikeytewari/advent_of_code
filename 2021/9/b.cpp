#include <bits/stdc++.h>
using namespace std;

bool compare (int a, int b)
{
    return a>b;
}

int dfs (vector<vector<bool>> &vis, stack<pair<int,int>> buffer, int local)
{
    if (buffer.size()==0)
    {
        return local;
    }

    int n=vis.size();
    int m=vis[0].size();

    pair<int,int> temp=buffer.top();
    buffer.pop();
    local++;
    if ((temp.first+1<=n-1) && !vis[temp.first+1][temp.second])
    {
        vis[temp.first+1][temp.second]=true;
        buffer.push({temp.first+1, temp.second});
    }
    if ((temp.first-1>=0) && !vis[temp.first-1][temp.second])
    {
        vis[temp.first-1][temp.second]=true;
        buffer.push({temp.first-1, temp.second});
    }
    if ((temp.second+1<=m-1) && !vis[temp.first][temp.second+1])
    {
        vis[temp.first][temp.second+1]=true;
        buffer.push({temp.first, temp.second+1});
    }
    if ((temp.second-1>=0) && !vis[temp.first][temp.second-1])
    {
        vis[temp.first][temp.second-1]=true;
        buffer.push({temp.first, temp.second-1});
    }

    return dfs(vis, buffer, local);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<vector<int>> arr(n);
    for (int i=0;i<=n-1;i++)
    {
        string s;
        cin >> s;
        for (int j=0;j<=(int)s.length()-1;j++)
        {
            arr[i].push_back(int(s[j])-int('0'));
        }
    }

    int m=arr[0].size();
    vector<pair<int,int>> low_point;
    for (int i=0;i<=n-1;i++)
    {
        for (int j=0;j<=m-1;j++)
        {
            int val=INT_MAX;
            if (i-1>=0)
            {
                val=min(val, arr[i-1][j]);
            }
            if (i+1<=n-1)
            {
                val=min(val, arr[i+1][j]);
            }
            if (j-1>=0)
            {
                val=min(val, arr[i][j-1]);
            }
            if (j+1<=m-1)
            {
                val=min(val, arr[i][j+1]);
            }

            if (val>arr[i][j])
            {
                low_point.push_back({i,j});
            }
        }
    }

    vector<int> basin;
    for (auto it=low_point.begin();it!=low_point.end();it++)
    {
        int a=it->first;
        int b=it->second;
        vector<vector<bool>> vis(n, vector<bool> (m, false));
        for (int i=0;i<=n-1;i++)
        {
            for (int j=0;j<=m-1;j++)
            {
                if (arr[i][j]==9)
                {
                    vis[i][j]=true;
                }
            }
        }
        
        stack<pair<int,int>> buffer;
        buffer.push({a,b});
        vis[a][b]=true;
        int local=dfs(vis, buffer, 0);
        basin.push_back(local);
    }

    sort(basin.begin(), basin.end(), compare);
    int count=0;
    int ans=1;
    for (int i=0;i<=(int)basin.size()-1;i++)
    {
        if (count<=2)
        {
            ans*=basin[i];
            count++;
        }
        else
        {
            break;
        }
    }

    cout << ans << endl;
    return 0;
}
