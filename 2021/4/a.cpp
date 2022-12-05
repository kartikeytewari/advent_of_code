#include <bits/stdc++.h>
using namespace std;

pair<int,int> solve(vector<int> arr, vector<vector<vector<pair<int,bool>>>>& board)
{
    int k=(int)board.size();
    int n=(int)arr.size();
    for (int num=0;num<=n-1;num++)
    {
        for (int br=0;br<=k-1;br++)
        {
            for (int i=0;i<=4;i++)
            {
                for (int j=0;j<=4;j++)
                {
                    if (board[br][i][j].first==arr[num])
                    {
                        board[br][i][j].second=true;
                    }
                }
            }

            // check row
            for (int i=0;i<=4;i++)
            {
                int count=0;
                for (int j=0;j<=4;j++)
                {
                    if (board[br][i][j].second)
                    {
                        count++;
                    }
                }

                if (count==5)
                {
                    return {arr[num],br};
                }
            }

            // check column
            for (int j=0;j<=4;j++)
            {
                int count=0;
                for (int i=0;i<=4;i++)
                {
                    if (board[br][i][j].second)
                    {
                        count++;
                    }
                }

                if (count==5)
                {
                    return {arr[num],br};
                }
            }
        }
    }
}

int main()
{
    vector<int> arr={92,12,94,64,14,4,99,71,47,59,37,73,29,7,16,32,40,53,30,76,74,39,70,88,55,45,17,0,24,65,35,20,63,68,89,84,33,66,18,50,38,10,83,75,67,42,3,56,82,34,90,46,87,52,49,2,21,62,93,86,25,78,19,57,77,26,81,15,23,31,54,48,98,11,91,85,60,72,8,69,6,22,97,96,80,95,58,36,44,1,51,43,9,61,41,79,5,27,28,13};
    int k;
    cin >> k;

    vector<vector<vector<pair<int,bool>>>> board(k, vector<vector<pair<int,bool>>> (5, vector<pair<int,bool>> (5)));
    for (int q=0;q<=k-1;q++)
    {
        for (int i=0;i<=4;i++)
        {
            for (int j=0;j<=4;j++)
            {
                cin >> board[q][i][j].first;
                board[q][i][j].second=false;
            }
        }
    }

    pair<int,int> index=solve(arr, board);
    int sum=0;
    for (int i=0;i<=4;i++)
    {
        for (int j=0;j<=4;j++)
        {
            if (!board[index.second][i][j].second)
            {
                sum+=board[index.second][i][j].first;
            }
        }
    }

    cout << "val= " << index.first << endl;
    cout << "sum= " << sum << endl;
    cout << "sol= " << index.first*sum << endl;
    
    return 0;
}