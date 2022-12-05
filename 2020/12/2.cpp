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

    ll x=0;
    ll y=0;
    
    ll waypoll[4]={10,1,0,0};
    ll notch=0;
    for (ll i=0;i<=n-1;i++)
    {
        cout << "i= " << i << endl;
        string s;
        cin >> s;
        string code=s.substr(0,1);
        ll val=stoi(s.substr(1,s.length()-1));

        cout << "code= " << code << endl;
        cout << "val= " << val << endl;

        if (code=="N")
        {
            waypoll[(notch+1)%4]+=val;
        }
        else if (code=="S")
        {
            waypoll[(notch+3)%4]+=val;
        }
        else if (code=="E")
        {
            waypoll[notch%4]+=val;
        }
        else if (code=="W")
        {
            waypoll[(notch+2)%4]+=val;
        }
        else if (code=="L")
        {
            notch+=3*(val/90);
        }
        else if (code=="R")
        {
            notch+=(val/90);
        }
        else if (code=="F")
        {
            waypoll[notch%4]-=waypoll[(notch+2)%4];
            waypoll[(notch+1)%4]-=waypoll[(notch+3)%4];
            waypoll[(notch+2)%4]=0;
            waypoll[(notch+3)%4]=0;
            x+=val*(waypoll[notch%4]);
            y+=val*(waypoll[(notch+1)%4]);
        }

        cout << "--------" << endl;
        cout << "x= " << x << endl;
        cout << "y= " << y << endl;
        cout << "waypoll0= " << waypoll[0] << endl;
        cout << "waypoll1= " << waypoll[1] << endl;
        cout << "waypoll2= " << waypoll[2] << endl;
        cout << "waypoll3= " << waypoll[3] << endl;
        cout << "notch= " << notch << endl;
        cout << "--------" << endl;
    }

    cout << abs(x)+abs(y) << endl;
    return 0;
}