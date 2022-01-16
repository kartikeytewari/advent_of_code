#include <bits/stdc++.h>
using namespace std;

bool check_negative(stack<char> buffer, char val)
{
    if (buffer.empty())
    {
        return true;
    }
    else if (buffer.top()!=val)
    {
        return true;
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<long long> arr;
    for (int i=0;i<=n-1;i++)
    {
        string s;
        cin >> s;
        stack<char> buffer;
        bool incomplete_line=true;
        for (int j=0;j<=(int)s.length()-1;j++)
        {
            if (((s[j]=='(') || (s[j]=='[')) || ((s[j]=='{') || (s[j]=='<')))
            {
                buffer.push(s[j]);
            }
            else if ((s[j]==')') && check_negative(buffer, '('))
            {
                incomplete_line=false;
                break;
            }
            else if ((s[j]==']') && check_negative(buffer, '['))
            {
                incomplete_line=false;
                break;
            }
            else if ((s[j]=='}') && check_negative(buffer, '{'))
            {
                incomplete_line=false;
                break;
            }
            else if ((s[j]=='>') && check_negative(buffer, '<'))
            {
                incomplete_line=false;
                break;
            }
            else
            {
                buffer.pop();
            }
        }

        if (incomplete_line)
        {
            long long val=0;
            while (!buffer.empty())
            {
                char temp=buffer.top();
                buffer.pop();

                val*=5ll;
                if (temp=='(')
                {
                    val+=1ll;
                }
                if (temp=='[')
                {
                    val+=2ll;
                }
                if (temp=='{')
                {
                    val+=3ll;
                }
                if (temp=='<')
                {
                    val+=4ll;
                }
            }

            arr.push_back(val);
        }
    }    

    sort(arr.begin(), arr.end());
    int m=(int)arr.size();
    cout << arr[m/2] << endl;
    return 0;
}
