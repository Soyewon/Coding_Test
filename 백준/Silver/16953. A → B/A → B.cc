#include <iostream>

using namespace std;

int cnt = 0;

int main()
{
    int a, b;

    cin >> a >> b;

    while(true)
    {
        if(a>b)
        {    
            cout << -1;
            break;
        }
        if(a==b)
        {   
            cnt++;
            cout << cnt;
            break;
        }

        if(b%10==1)
        {   
            cnt++;
            b -= 1;
            b /= 10;
        }
        else if(b%2==0)
        {
            cnt++;
            b /= 2;
        }
        else
        {
            cout << -1;
            break;
        }
    }
}