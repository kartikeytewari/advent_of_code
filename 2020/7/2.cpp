#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define endl "\n"
#define line 2719
using namespace std;
vector<string> bag_index;
int path[line][line];

int val (int index)
{
    int local=0;
    for (int i=0;i<=line-1;i++)
    {
        if (path[index][i]!=0)
        {
            local+=path[index][i]*(val(i)+1);
        }
    }

    return local;
}

int get_id (string s)
{
    for (auto it=bag_index.begin();it!=bag_index.end();it++)
    {
        if (*it==s)
        {
            return (int)distance(bag_index.begin(), it);
        }
    }

    bag_index.push_back(s);
    return (int)(bag_index.size()-1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    for (int i=0;i<=line-1;i++)
    {
        for (int j=0;j<=line-1;j++)
        {
            path[i][j]=0;
        }
    }

    string s;
    int initial_line=1;
    vector<string> buffer;
    while (initial_line<=line)
    {
        getline (cin, s);
        if (s.length()==0)
        {
            int start=get_id(*buffer.begin());
            for (auto it=next(buffer.begin());it!=buffer.end();it++)
            {
                string a=(*it).substr(0,1);
                string b=(*it).substr(2,(*it).length()-2);
                int end=get_id(b);
                if (a=="n")
                {
                    path[start][end]=0;
                }
                else
                {
                    path[start][end]=stoi(a);
                }
            }

            buffer.clear();
        }
        else
        {
            buffer.push_back(s);
        }
        initial_line++;
    }

    int check=get_id("shiny gold bag");
    int ans=val(check);
    cout << ans << endl;

    return 0;
}