#include <iostream>
#include <algorithm>

using namespace std;
#define MAX 10001

int n;
int wine[MAX];
int d[MAX]; // d[i] : i번째 포도주까지 마셨을 때 마신 포도주의 최대 양

int dp()
{
    int temp;

    for(int i=3; i<=n; i++)
    {
        temp = max(d[i-1], d[i-2]+wine[i]); // 16 vs 19 = 19
        d[i] = max(temp, d[i-3]+wine[i-1]+wine[i]); // 19 vs 16 = 19
    }

    return d[n];
}

int main() 
{
    cin >> n;
    for(int i=1; i<=n; i++)
    {
        cin >> wine[i];
    }

    d[1] = wine[1];
    d[2] = wine[1] + wine[2];
    
    cout << dp();
}