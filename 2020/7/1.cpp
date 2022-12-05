#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define endl "\n"
#define line 2719
using namespace std;
vector<string> bag_index;
int path[line][line];


// --------------------------------------------------------------------------------------------------------
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
// --------------------------------------------------------------------------------------------------------



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
            for (auto it=next(buffer.begin());it!=buffer.end();it++)
            {
                string a=(*it).substr(2,(*it).length()-2);
                *it=a;
            }

            for (auto it=buffer.begin();it!=buffer.end();it++)
            {
                int a=get_id(*buffer.begin());
                int b=get_id(*it);
                path[a][b]=1;
            }
            buffer.clear();
        }
        else
        {
            buffer.push_back(s);
        }
        initial_line++;
    }

    int ans=0;
    int check=get_id("shiny gold bag");
    for (int i=0;i<=line-1;i++)
    {
        vector<int> visited(line,0);
        deque<int> local;
        local.push_back(i);
        visited[i]=1;

        while (local.size()!=0)
        {
            int a=local.back();
            local.pop_back();
            for (int j=0;j<=line-1;j++)
            {
                if ((path[a][j]==1)&&(visited[j]==0))
                {
                    local.push_front(j);
                    visited[j]=1;
                }
            }
        }

        if (visited[check]==1)
        {
            ans++;
        }
    }
    cout << ans-1 << endl;

    return 0;
}