#include <iostream>
#include <vector>
using namespace std;


int main()
{
	int n = 0;
	cin >> n;
	vector<int> arr(n+1);
	vector<bool> judge(n+1,1);

	judge[0] = judge[1] = 0;
	for (int i = 1; i <=n; i++)
	{
		arr[i] = i;
	}

	for (int i = 2; i <= n; i++)
	{
		if (judge[i])
		{
			for (int j = i*i; j <= n; j+=i)
			{

				if (i * j <= n)
					judge[i * j] = 0;


			}
		}
		
	}

	for (int i = 1; i <= n; i++)
	{
		if (judge[i])
			cout << arr[i] << endl;
	}


	return 0;
}
