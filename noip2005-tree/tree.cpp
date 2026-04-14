#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main()
{
	int l = 0;
	int m = 0;
	int j = 0;//起始点编号
	int i = 0;//树木编号
	int count = 0;
	cin >> l >> m;

	int* tree= new int[l+1];
	int* arr = new int[2 * m];
	for (i = 0; i <=l; i++)
	{
		tree[i] = 1;
	}

	for (j= 0; j < 2 * m; j++)
	{
		cin >> arr[j];
	}
	for (int i = 0; i < j;i = i + 2)
	{
		for (int j = arr[i]; j <= arr[i + 1]; j++)
		{
			tree[j] = 0;
		}
	}
	for (int i = 0; i <= l; i++)
	{
		if (tree[i] == 1)
		{
			count++;
		}
	}
	cout << count;

	
}
