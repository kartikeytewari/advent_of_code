#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define endl "\n"
#define n 190
using namespace std;
int arr[n][20];

void calc (int a, int b, int c, int d)
{
    int ans[20]={0};
    for (int i=0;i<=n-1;i++)
    {
        for (int j=0;j<=19;j++)
        {
            int t=arr[i][j];
            if (!(((t>=a)&&(t<=b))||((t>=c)&&(t<=d))))
            {
                ans[j]++;
            }
        }
    }

    for (int i=0;i<=19;i++)
    {
        if (ans[i]==0)
        {
            cout << i+1 << " ";
        }
    }
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    for (int i=0;i<=n-1;i++)
    {
        for (int j=0;j<=19;j++)
        {
            cin >> arr[i][j];
        }
    }

    // departure location: 28-787 or 804-964
    calc(28,787,804,964);
    // departure station: 41-578 or 594-962
        calc(41,578,594,962);
    // departure platform: 50-718 or 733-949
        calc(50,718,733,949);
    // departure track: 27-846 or 862-949
        calc(27,846,862,949);
    // departure date: 50-241 or 249-957
        calc(50,241,249,957);
    // departure time: 44-81 or 104-972
        calc(44,81,104,972);
    // arrival location: 45-292 or 299-954
        calc(45,292,299,954);
    // arrival station: 46-650 or 657-974
        calc(46,650,657,974);
    // arrival platform: 42-396 or 405-953
        calc(42,396,405,953);
    // arrival track: 42-871 or 886-973
        calc(42,871,886,973);
    // class: 31-808 or 829-964
        calc(31,808,829,964);
    // duration: 39-909 or 935-969
        calc(39,909,935,969);
    // price: 49-350 or 364-970
        calc(49,350,364,970);
    // route: 44-251 or 264-959
        calc(44,251,264,959);
    // row: 50-539 or 556-952
        calc(50,539,556,952);
    // seat: 45-624 or 630-951
        calc(45,624,630,951);
    // train: 28-283 or 290-960
        calc(28,283,290,960);
    // type: 44-334 or 340-951
        calc(44,334,340,951);
    // wagon: 43-699 or 716-961
        calc(43,699,716,961);
    // zone: 42-668 or 688-958
        calc(42,668,688,958);
    return 0;
}