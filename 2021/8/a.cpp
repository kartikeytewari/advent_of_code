#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> check={2,3,4,7};
    int count=0;
    for (int i=0;i<=n-1;i++)
    {
        string s;
        cin >> s;
        int val=s.length();
        if (binary_search(check.begin(), check.end(), val))
        {
            count++;
        }
    }

    cout << count << endl;
    return 0;
}
