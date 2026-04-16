#include <iostream>
using namespace std;

// 1 = 路可以走
// 0 = 墙不能走
int maze[5][5] = 
{
    {1, 0, 0, 0, 0},
    {1, 1, 1, 0, 0},
    {0, 0, 1, 0, 0},
    {0, 0, 1, 1, 1},
    {0, 0, 0, 0, 1}
};

// 标记有没有走过
int vis[5][5];

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

// x,y = 当前位置
void dfs(int x, int y)
{
    // 1. 到达(4,4)
    if (x == 4 && y == 4)
    {
        cout << "find out exit" << endl;
        return;
    }

    // 2. 遍历 4 个方向
    for (int i = 0; i < 4; i++) 
    {
        int nx = x + dx[i]; // 新的x
        int ny = y + dy[i]; // 新的y

     
        // 不越界&&不是墙&&没走过
        if (nx >= 0 && nx < 5 && ny >= 0 && ny < 5
            && maze[nx][ny] == 1
            && vis[nx][ny] == 0) 
        {

            vis[nx][ny] = 1; // 标记走过
            dfs(nx, ny);     // 递归
            vis[nx][ny] = 0; // 回溯
        }
    }
}

int main() 
{
    vis[0][0] = 1;   // 起点标记
    dfs(0, 0);
    return 0;
}
