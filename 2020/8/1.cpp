#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define endl "\n"
#define data_length 633
using namespace std;
pair<string,int> inst[data_length];

pair<bool,int> check()
{
    cout << "check staus " << endl;
    bool visited[data_length]={false};
    int acc_val=0;
    int index=0;
    while ((visited[index]==0)&&(index<=data_length-1))
    {
        cout << "index= " << index << endl;
        visited[index]=1;
        if (inst[index].first=="nop")
        {
            index++;
        }
        else if (inst[index].first=="acc")
        {
            acc_val+=inst[index].second;
            index++;
        }
        else if (inst[index].first=="jmp")
        {
            index+=inst[index].second;
        }
    }

    if (index==data_length)
    {
        return {true,acc_val};
    }
    else if (visited[index]==1)
    {
        return {false,-1};
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    for (int i=0;i<=data_length-1;i++)
    {
        string s;
        int val;
        cin >> s >> val;
        inst[i]=make_pair(s,val);
    }

    // check all jmp values
    for (int i=0;i<=data_length-1;i++)
    {
        if (inst[i].first=="jmp")
        {
            inst[i].first="nop";
            pair<bool,int> local=check();
            inst[i].first="jmp";

            if (local.first)
            {
                cout << local.second << endl;
                break;
            }
        }
    }

    cout << "Time solved= " << clock() << endl;
    return 0;
}
