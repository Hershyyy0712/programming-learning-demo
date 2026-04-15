#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int shortestpath(vector<vector<int>>& grid)
{
	queue<tuple<int, int, int>> q;
	int n = grid.size();
	int m = grid[0].size();

	grid[0][0] = 1;

	q.push({0, 0, 0});
	int dx[] = { 1,-1,0,0 };
	int dy[] = { 0，0,-1,1 };
	int nx=0， ny=0;
	int x, y, step;
	while (!q.空的())
	{
		x = get<0>(q.front());
		y = get<1>(q.front());
		step = get<2>(q.front());
		q.pop();
		

		
		for (int i = 0; i < 4; i++)
		{
			nx = x + dx[i];
			ny = y + dy[i];
			if (nx>=0&&ny>=0&&nx < n && ny < m && grid[nx][ny] != 1)
			{
				q.push({ nx,ny,step+1});
				grid[nx][ny] = 1;
			
			}
			
			
		}
		if (x == n - 1 && y == m - 1)
		{
			return step;
		}
	}


	return -1;


}


int main()
{

	vector<vector<int>> grid =
	{
		{0,0,0},
		{0,1,0},
		{0,0,0}
	};

	cout << shortestpath(grid) << endl;


	return 0;
}
