// 백준 1890 - 점프
// https://www.acmicpc.net/problem/1890
// dp

#include <iostream>

using namespace std;

int n;
int map[101][101];
long long d[101][101]; // map[i][j]까지 가는 경로의 수

void dp()
{   
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            // 해당 좌표로 이동 불가능한 경우 무시
            if(map[i][j]==0)
                continue;
            // 오른쪽 이동 시
            if(i!=n-1 && i+map[i][j]<n)
                d[i+map[i][j]][j] += d[i][j];
            // 아래쪽 이동 시
            if(j!=n-1 && j+map[i][j]<n)
                d[i][j+map[i][j]] += d[i][j];
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> map[i][j];

    d[0][0] = 1;
    dp();

    cout << d[n-1][n-1];

    return 0;
}