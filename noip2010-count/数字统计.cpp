#include <iostream>
using namespace std;

int judge(int& L, int& R)
{
    int ret = 0;
    for (int i = L; i <= R; i++)
    {
        int num = i;
        while(num>0)
        {
            if(num%10==2)
            {
                ret++;
            }
            num=num/10;
        }
    }

    return ret;
}




int main()
{
    int L = 0,R = 0;
    cin >> L>> R;
    int p=judge(L, R);
    cout << p;
    return 0;
}
