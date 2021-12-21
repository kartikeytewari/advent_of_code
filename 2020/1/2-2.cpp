#include <bits/stdc++.h>
using namespace std;

int main()
{
	int arr[200];
	for (int i=0;i<=199;i++)
	{
		cin >> arr[i];
	}

	map<int,int> counter;
	for (int i=0;i<=199;i++)
	{
		counter[arr[i]]++;
	}

	bool flag=true;
	for (int i=0;i<=198;i++)
	{
		for (int j=i+1;j<=199;j++)
		{
			if ((flag)&&(counter[2020-arr[i]-arr[j]]>=1))
			{
				cout << arr[i]*arr[j]*(2020-arr[i]-arr[j]) << endl;
				flag=false;
			}
		}
	}

	return 0;
}
