#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <queue>
using namespace std;

int main()
{
	queue<int> q;
	for (int i = 0; i < 10; i++)
	{
		q.push(i + 1);
	}

	int count = 1;
	int person = 0;

	while (q.size() > 1)
	{
		if (count % 3 == 0)
		{
			cout << "out:" << q.front() << endl;
			count = 0;
		}
		else
		{
			person = q.front();
			q.push(person);
		}
		q.pop();
		

		count++;
	}
	cout << "last:" << q.front() << endl;
}
