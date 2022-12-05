#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int x=0;
    int y=0;
    int aim=0;
    for (int i=0;i<=n-1;i++)
    {
        string s;
        int d;
        cin >> s >> d;

       if (s=="down")
       {
           aim+=d;
       }
       else if (s=="up")
       {
           aim-=d;
       }
       else
       {
           x+=d;
           y+=aim*d;
       }
    }

    cout << "x= " << x << endl;
    cout << "y= " << y << endl;
    cout << "multiply= " << x*y << endl;

    return 0;
}