#include <iostream>
#include <vector>

using namespace std;
#define MAX 1025

int n, m;
int x1, y1, x2, y2;
int board[MAX][MAX];
int d[MAX][MAX]; // board[1][1]~board[i][j] 까지의 합 dp[i][j]
vector<int> res;

void getSum()
{
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            d[i][j] = d[i-1][j] + d[i][j-1] - d[i-1][j-1] + board[i][j];
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            cin >> board[i][j];
    
    getSum();

    for(int i=0; i<m; i++)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        int temp = d[x2][y2] - d[x1-1][y2] - d[x2][y1-1] + d[x1-1][y1-1];
        res.push_back(temp);
    }

    for(int i=0; i<res.size(); i++)
        cout << res[i] << '\n';

    return 0;
}