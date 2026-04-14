#include <iostream>
#include <cmath>
#include <string>
#include <vector>
using namespace std;

int main()
{
	long long k = 0, m = 0, n = 0;
	
	cin >> k >> m >> n;
	vector<long long>a(m);
	vector<long long>b(m);
	long long time = 0;
	long long ret = 0;
	
	for (long long i = 0; i < m; i++)
	{
		cin >> a[i] >> b[i];
	}

	for (long long i = 0; i < m;i++)
	{
		if (a[i] > 0)
		{
			time = k / a[i];
			if (time * b[i] >= n)
			{
				cout << i + 1 << " ";
				ret = 1;
			}
			time = 0;


		}
		else
		{
			cout << i + 1 << " ";
			ret = 1;
		}
		
		

	}

	if (ret == 0)
	{
		cout << -1;
	}

	return 0;
}
