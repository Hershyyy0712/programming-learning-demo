#include <iostream>
#include <string>
using namespace std;

string s;          
bool vis[10];       // 标记第i个字符是否被用过
string path;        // 当前正在拼的排列


void dfs()
{
    //  递归出口
    if (path.size() == s.size()) 
    {
        cout << path << endl; 
        return;                 
    }

    //  遍历字符
    for (int i = 0; i < s.size(); i++)
    {

       
        if (!vis[i])
        {

            vis[i] = true;      // 标记
            path += s[i];       // 拼接

            dfs();              // 递归

            //回溯
            path.pop_back();    
            vis[i] = false;    
        }
    }
}

int main()
{
    cin >> s;
    dfs();      
    return 0;
}
