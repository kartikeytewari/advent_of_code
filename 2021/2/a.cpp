#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int x=0;
    int y=0;
    for (int i=0;i<=n-1;i++)
    {
        string s;
        int d;
        cin >> s >> d;

        if (s=="forward")
        {
            x+=d;
        }
        else if (s=="down")
        {
            y+=d;
        }
        else
        {
            y-=d;
        }
    }

    cout << "x= " << x << endl;
    cout << "y= " << y << endl;
    cout << "multiply= " << x*y << endl;

    return 0;
}