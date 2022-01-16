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
    int ans=0;
    for (int i=0;i<=n-1;i++)
    {
        string s;
        cin >> s;
        stack<char> buffer;
        int local=0;
        for (int j=0;j<=(int)s.length()-1;j++)
        {
            if (((s[j]=='(') || (s[j]=='[')) || ((s[j]=='{') || (s[j]=='<')))
            {
                buffer.push(s[j]);
            }
            else if ((s[j]==')') && check_negative(buffer, '('))
            {
                local=3;
                break;
            }
            else if ((s[j]==']') && check_negative(buffer, '['))
            {
                local=57;
                break;
            }
            else if ((s[j]=='}') && check_negative(buffer, '{'))
            {
                local=1197;
                break;
            }
            else if ((s[j]=='>') && check_negative(buffer, '<'))
            {
                local=25137;
                break;
            }
            else
            {
                buffer.pop();
            }
        }
        cout << "local= " << local << endl;
        ans+=local;
    }    

    cout << ans << endl;
    return 0;
}
