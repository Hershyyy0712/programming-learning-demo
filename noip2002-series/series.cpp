#include <iostream>
using namespace std;

int main()
{
    double s = 0;
    int n = 0;
    int k = 0;
    cin>>k;
    while(true)
    {
        ++n;
        s=s+1.0/n;
        
        if(s>k)
            break;
    }

    cout<<n;
    return 0;
}
