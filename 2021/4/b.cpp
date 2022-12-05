#include <bits/stdc++.h>
using namespace std;

void print_arr(vector<vector<vector<pair<int,bool>>>> arr)
{
    cout << "----------------" << endl;
    int q=(int)arr.size();
    for (int arr_id=0;arr_id<=q-1;arr_id++)
    {
        cout << "arr_id= " << arr_id << endl;
        for (int i=0;i<=4;i++)
        {
            for (int j=0;j<=4;j++)
            {
                cout << "[" << arr[arr_id][i][j].first << "-" << arr[arr_id][i][j].second << "]\t";
            }
            cout << endl;
        }
    }
    cout << "----------------" << endl;

    return;
}

int main()
{
    int n;
    cin >> n;
    vector<int> num={92,12,94,64,14,4,99,71,47,59,37,73,29,7,16,32,40,53,30,76,74,39,70,88,55,45,17,0,24,65,35,20,63,68,89,84,33,66,18,50,38,10,83,75,67,42,3,56,82,34,90,46,87,52,49,2,21,62,93,86,25,78,19,57,77,26,81,15,23,31,54,48,98,11,91,85,60,72,8,69,6,22,97,96,80,95,58,36,44,1,51,43,9,61,41,79,5,27,28,13};

    vector<vector<vector<pair<int,bool>>>> arr(n, vector<vector<pair<int,bool>>>(5, vector<pair<int,bool>> (5)));
    vector<pair<int,int>> play(n, {-1,-1});
    for (int q=0;q<=n-1;q++)
    {
        for (int i=0;i<=4;i++)
        {
            for (int j=0;j<=4;j++)
            {
                cin >> arr[q][i][j].first;
                arr[q][i][j].second=false;
            }
        }
    }

    int global_count=0;
    for (int num_id=0;num_id<=(int)num.size()-1;num_id++)
    {
        for (int arr_id=0;arr_id<=n-1;arr_id++)
        {
            if (play[arr_id].first==-1)
            {
                // check if arr[arr_id] contains num[num_id]
                for (int i=0;i<=4;i++)
                {
                    for (int j=0;j<=4;j++)
                    {
                        if (arr[arr_id][i][j].first == num[num_id])
                        {
                            arr[arr_id][i][j].second=true;
                        }
                    }
                }


                // check if arr[arr_id] is a winner yet
                // check row
                for (int i=0;i<=4;i++)
                {
                    int local=0;
                    for (int j=0;j<=4;j++)
                    {
                        if (arr[arr_id][i][j].second)
                        {
                            local++;
                        }
                    }

                    if (local==5)
                    {
                        global_count++;
                        play[arr_id]={global_count, num[num_id]};
                    }
                }
                // check col
                for (int j=0;j<=4;j++)
                {
                    int local=0;
                    for (int i=0;i<=4;i++)
                    {
                        if (arr[arr_id][i][j].second)
                        {
                            local++;
                        }
                    }

                    if (local==5)
                    {
                        global_count++;
                        play[arr_id]={global_count, num[num_id]};
                    }
                }
            }
        }

        cout << "num= " << num[num_id] << endl;
        print_arr(arr);
    }

    cout << "play_array:" << endl;
    for (int i=0;i<=n-1;i++)
    {
        cout << play[i].first << " " << play[i].second << endl;
    }

    int ans=0;
    for (int arr_id=0;arr_id<=n-1;arr_id++)
    {
        if (play[arr_id].first==global_count)
        {
            int unmark_sum=0;
            for (int i=0;i<=4;i++)
            {
                for (int j=0;j<=4;j++)
                {
                    if (!arr[arr_id][i][j].second)
                    {
                        unmark_sum+=arr[arr_id][i][j].first;
                    }
                }
            }

            ans=unmark_sum*play[arr_id].second;
        }
    }

    cout << ans << endl;
    return 0;
}