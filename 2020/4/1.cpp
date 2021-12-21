#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define endl "\n"
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int line=1139;
    string s;
    int ans=0;
    vector<string> buffer;
    while (line>=0)
    {
        getline(cin, s);
        string local;
        for (int i=0;i<=(int)s.length()-1;i++)
        {
            if (s[i]==' ')
            {
                buffer.push_back(local);
                local="";
            }
            else
            {
                local+=s[i];
            }
        }
        buffer.push_back(local);
        line--;

        if (s.length()==0)
        {
            int check=0;
            for (auto it=buffer.begin();it!=buffer.end();it++)
            {
                string temp=*it;
                temp=temp.substr(0,3);
                if (temp=="byr")
                {
                    check++;
                }
                if (temp=="iyr")
                {
                    check++;
                }
                if (temp=="eyr")
                {
                    check++;
                }
                if (temp=="hgt")
                {
                    check++;
                }
                if (temp=="hcl")
                {
                    check++;
                }
                if (temp=="ecl")
                {
                    check++;
                }
                if (temp=="pid")
                {
                    check++;
                }
            }

            if (check==7)
            {
                ans++;
            }
            buffer.clear();
        }
    }
    cout << ans << endl;

    return 0;
}