#include <iostream>

using namespace std;
#define NUM 1000000000

int n;
int d[101][10]; // d[i][j]일 때, i자리 숫자 중 일의자리 수가 j인 경우의 수
int res = 0;

void dp()
{
    for(int i=1; i<10; i++)
        d[1][i] = 1;
        
    for(int i=2; i<=n; i++)
    {
        for(int j=0; j<10; j++)
        {
            if(j==0)
                d[i][0] = d[i-1][j+1];
            else if(j==9)
                d[i][9] = d[i-1][j-1];
            else
                d[i][j] = d[i-1][j-1] + d[i-1][j+1];

            d[i][j]%=NUM;
        }
    }
}

int main()
{
    cin >> n;

    dp();    
    for(int i=0; i<10; i++)
    {
        res = (res+d[n][i]) % NUM;
    }
    
    cout << res;
    return 0;
}