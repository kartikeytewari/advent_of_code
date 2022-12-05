#include <bits/stdc++.h>
using namespace std;

string get_oxygen_generator (vector<pair<string,bool>> arr)
{
    int n=arr.size();
    int k=arr[0].first.size();
    int total=n;

    for (int j=0;j<=k-1;j++)
    {
        if (total==1)
        {
            break;
        }

        int count=0;
        for (int i=0;i<=n-1;i++)
        {
            if (arr[i].second && (arr[i].first[j]=='0'))
            {
                count++;
            }
        }
        char max_val='0';
        if (count<=total-count)
        {
            max_val='1';
        }

        for (int i=0;i<=n-1;i++)
        {
            if (arr[i].second && (arr[i].first[j]!=max_val))
            {
                arr[i].second=false;
                total--;
            }
        }
    }

    for (int i=0;i<=n-1;i++)
    {
        if (arr[i].second)
        {
            return arr[i].first;
        }
    }
}

string get_co2_scrubber_rating (vector<pair<string,bool>> arr)
{
    int n=arr.size();
    int k=arr[0].first.size();
    int total=n;

    for (int j=0;j<=k-1;j++)
    {
        if (total==1)
        {
            break;
        }

        int count=0;
        for (int i=0;i<=n-1;i++)
        {
            if (arr[i].second && (arr[i].first[j]=='0'))
            {
                count++;
            }
        }
        char min_val='0';
        if (count>total-count)
        {
            min_val='1';
        }

        for (int i=0;i<=n-1;i++)
        {
            if (arr[i].second && (arr[i].first[j]!=min_val))
            {
                arr[i].second=false;
                total--;
            }
        }
    }

    for (int i=0;i<=n-1;i++)
    {
        if (arr[i].second)
        {
            return arr[i].first;
        }
    }
}

int to_int(string s)
{
    int val=0;
    for (int i=0;i<=(int)s.length()-1;i++)
    {
        if (s[i]=='1')
        {
            val+=1;
        }
        val*=2;
    }
    val/=2;

    return val;
}

int main()
{
    int n;
    cin >> n;
    
    vector<pair<string,bool>> arr(n);
    for (int i=0;i<=n-1;i++)
    {
        cin >> arr[i].first;
        arr[i].second=true;
    }

    int alpha=to_int(get_oxygen_generator(arr));
    int beta=to_int(get_co2_scrubber_rating(arr));

    cout << "alpha= " << alpha << endl;
    cout << "beta= " << beta << endl;
    cout << "sol= " << alpha*beta << endl;
    
    return 0;
}