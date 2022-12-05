#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define endl "\n"
#define n 748
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int x=0;
    int y=0;
    int dir=0;
    // dir 0 is east
    // dir 1 is north
    // dir 2 is west
    // dir 3 is south

    for (int i=0;i<=n-1;i++)
    {
        string s;
        cin >> s;
        string code=s.substr(0,1);
        int val=stoi(s.substr(1,(int)s.length()-1));
        
        if (code=="N")
        {
            y+=val;
        }
        else if (code=="S")
        {
            y-=val;
        }
        else if (code=="E")
        {
            x+=val;
        }
        else if (code=="W")
        {
            x-=val;
        }
        else if (code=="L")
        {
            dir+=(val/90);
            dir=(dir+4)%4;
        }
        else if (code=="R")
        {
            dir-=(val/90);
            dir=(dir+4)%4;
        }
        else if (code=="F")
        {
            if (dir==0)
            {
                x+=val;
            }
            else if (dir==1)
            {
                y+=val;
            }
            else if (dir==2)
            {
                x-=val;
            }
            else if (dir==3)
            {
                y-=val;
            }
        }
    }

    cout << abs(x)+abs(y) << endl;

    return 0;
}