#include <bits/stdc++.h>
using namespace std;

void print_arr (vector<int> arr)
{
    cout << "arr: ";
    for (auto it=arr.begin();it!=arr.end();it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

int main()
{
    int n,k;
    cin >> n >> k;

    vector<int> arr(n);
    for (int i=0;i<=n-1;i++)
    {
        cin >> arr[i];
    }

    for (int i=0;i<=k-1;i++)
    {
        int old_size=(int)arr.size();
        for (int j=0;j<=old_size-1;j++)
        {
            if (arr[j]!=0)
            {
                arr[j]--;
            }
            else
            {
                arr[j]=6;
                arr.push_back(8);
            }
        }
        
        // print_arr(arr);
        cout << "i= " << i << endl;
        cout << "val= " << arr.size() << endl;
    }

    cout << arr.size() << endl;
}