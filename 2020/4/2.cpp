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
            buffer.pop_back();
            int check=0;
            for (auto it=buffer.begin();it!=buffer.end();it++)
            {
                string temp=*it;
                string first=temp.substr(0,3);
                string second=temp.substr(4,(int)temp.length());
                if (first=="byr")
                {
                    if ((second.length()==4)&&((stoi(second)>=1920)&&(stoi(second)<=2002)))
                    {
                        check++;
                    }
                }
                else if (first=="iyr")
                {
                    if ((second.length()==4)&&((stoi(second)>=2010)&&(stoi(second)<=2020)))
                    {
                        check++;
                    }
                }
                else if (first=="eyr")
                {
                    if ((second.length()==4)&&((stoi(second)>=2020)&&(stoi(second)<=2030)))
                    {
                        check++;
                    }
                }
                else if ((first=="hgt")&&(second.length()>=4))
                {
                    string unit=second.substr(second.length()-2,2);
                    string val_string=second.substr(0,second.length()-2);
                    int val=stoi(val_string);

                    if ((unit=="cm")&&((val>=150)&&(val<=193)))
                    {
                        check++;
                    }
                    else if ((unit=="in")&&((val>=59)&&(val<=76)))
                    {
                        check++;
                    }
                }
                else if (first=="hcl")
                {
                    int local_validity=0;
                    for (int i=0;i<=(int)second.length()-1;i++)
                    {
                        if (i==0)
                        {
                            if (second[i]=='#')
                            {
                                local_validity++;
                            }
                        }
                        else
                        {
                            int ascii_val=int(second[i]);
                            if ((ascii_val>=48)&&(ascii_val<=57))
                            {
                                local_validity++;
                            }
                            if ((ascii_val>=97)&&(ascii_val<=102))
                            {
                                local_validity++;
                            }
                        }
                    }

                    if ((local_validity==7)&&(second.length()==7))
                    {
                        check++;
                    }
                }
                else if (first=="ecl")
                {
                    vector<string> correct={"amb", "blu", "brn", "gry", "grn", "hzl", "oth"};
                    sort(correct.begin(), correct.end());
                    if (binary_search(correct.begin(),correct.end(),second))
                    {
                        check++;
                    }
                }
                else if (first=="pid")
                {
                    int local_validity=0;
                    for (int i=0;i<=(int)second.length()-1;i++)
                    {
                        int ascii_val=int(second[i]);
                        if ((ascii_val>=48)&&(ascii_val<=57))
                        {
                            local_validity++;
                        }
                    }

                    if ((local_validity==9)&&(second.length()==9))
                    {
                        check++;
                    }
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