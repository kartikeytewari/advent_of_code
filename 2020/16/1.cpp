#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define endl "\n"
#define q 242
#define n 20
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int arr[1000]={false};
    for (int w=0;w<=n-1;w++)
    {
        int a,b,c,d;
        cin >> a >> b >> c >> d;

        for (int i=a;i<=b;i++)
        {
            arr[i]=true;
        }
        for (int i=c;i<=d;i++)
        {
            arr[i]=true;
        }
    }

    int ans=0;
    for (int i=0;i<=241;i++)
    {
        bool local=true;
        int temp[20];
        for (int j=0;j<=19;j++)
        {
            int a;
            cin >> a;
            temp[j]=a;
            if (!arr[a])
            {
                local=false;
                ans+=a;
            }
        }

        if (local)
        {
            for (int j=0;j<=19;j++)
            {
                cout << temp[j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}