#include <iostream>
#include <cmath>
#include <string>
using namespace std;


int main()
{
	int N = 0;
	string s;
	string part;
	int i = 0;
	int z = 0;
	int o = 0;
	int count = 0;

	while (cin >> part)
	{
		s += part;
		part.clear();
	}
	i = s.size();
	
	N = static_cast<int>(round(sqrt(i)));

	cout << N;

	if (s[0] == '1')
	{
		cout << " 0";
	}
	for (int j = 0; j < i; j++)
	{


		if (s[j] == '0')
		{
			if (o != 0)
			{
				cout << " " << o;
				o = 0;
			}

			z++;
		}
		else if (s[j] == '1')
		{
			if (z != 0)
			{
				cout << " " << z;
				z = 0;
			}

			o++;
		}
	}
	
		
	
	

	if (z != 0)
		cout << " "<<z;
	if (o != 0)
		cout << " "<<o;
	return 0;

}
