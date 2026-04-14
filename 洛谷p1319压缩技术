#include <iostream>

using namespace std; 

int main()
{
	int N = 0;
	cin >> N;
	int i = 0;
	int ret = 1;//while循环依据
	int total = 0;//输入压缩码之和
	int arr[200];

	while (ret)
	{
		cin >> arr[i];
		total += arr[i];
		++i;
		if (total >= N * N)
		{
			ret = 0;
		}
	}
	

	int k = 0;
	int p = 0;
	
	for(k;k<=i;k+=2)
	{
		
		for (int j = 0; j < arr[k]; j++)
		{
			++p;
			if (p % (N + 1) == 0)
			{
				cout << endl;
				cout << 0;
				++p;
			}
			else
				cout << 0;
			
		}
		for (int j = 0; j < arr[k + 1]; j++)
		{
			++p;
			if (p % (N + 1) == 0)
			{
				cout << endl;
				cout << 1;
				++p;
			}
			else
				cout << 1;
			
		}
		
	}

	return 0;
}

